/* USP Project - Phase 1*
 * Ravi Shreyas 	*
 * Rishabh Dutt		*
 * Rajat Nigam 		*/

#ifndef BLOCK_H_
#define BLOCK_H_

#include "macros.h"
#include "fs.h"

struct disk_block;
struct inode_block;
struct data_block;
struct indirect_block;

struct data_block{
  char buffer[UNION_SIZE];  
};

struct dir_block{
	struct directory dir[UNION_SIZE/sizeof(struct directory)];
};

struct inode_block{
    struct inode inod;
    int filled;	
};

struct indirect_block{
    struct disk_block *buffer[UNION_SIZE / sizeof(struct disk_block *)];
};


/* File that abstracts our storage device into blocks*/
extern struct disk_block{
	int diskblocknumber;
    unsigned int block_flag;
	int filled;
    union buffer_type{
        struct inode_block iblock[UNION_SIZE/sizeof(struct inode_block)];
        struct data_block dblock;
        struct indirect_block pblock;
	struct dir_block drblock;
    } buf_type;
}disk_block[NR_DISK_BLOCK];

int find_free_inode_space(struct inode_block*);
int find_free_inode_block(struct disk_block *);
void preprocess(struct disk_block *);
/* Needs to be worked upon */
#endif
