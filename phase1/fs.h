/*Header file which contains the basic structures for our file system
 * Ravi Shreyas Anupindi
 * Rishabh Dutt
 * Rajat Nigam
*/

#ifndef FS_H_
#define FS_H_

#include "macros.h"
#include "block.h"

#define MODE_STRING_SIZE 5

/*structure to maintain the modebits for a file
 * considering a single user file system no multi user
 * so permissions would be set as two bits for type of file
 * three bits for read,write,execute permissions
 */

struct mode_string{
    char bit_string[MODE_STRING_SIZE]; // 2 bits for file type, 3 bits for user permissions
};

/* structure to maintain the time stamps for the files*/
struct timestamp{
	unsigned long int ctime; // When the particular inode was changed. Stored in Epoch
	unsigned long int mtime; // when the file contents were modified Stored in Epoch
	unsigned long int atime; // when the file was accessed. Stored in Epoch
};

/*structure to maintain the inode structure for files*/

struct inode{
    //struct inode * parent; // To store the ..	
//    unsigned short int disk; //disk number not required for one disk scenario
    unsigned long int inode_num; //inode identifier
    unsigned int size; //size of the file in blocks
    struct mode_string mstring; // This to store type of the file and permission bit 
    //int block_p[BLOCKS_PER_FILE]; //block numbers where data is stored
    struct timestamp tstamp; // The time stamp contains the mtime, ctime and atime
    struct disk_block * indirect_p; //block number where the first level indirect pointers are stored : there are POINTERS_PER_BLOCK stored in each block
    unsigned int num_blocks; // Stores the number of blocks per file.	
};

/*structure to maintain the inode of directories*/
struct directory{
	unsigned long int inode_num;
	char name[MAX_LENGTH];
};	

struct inode create_inode();
//int getDisk(struct inode *p);
unsigned long int get_inode_num(struct inode *);
// update time stamp when the file is accessed, modified or deleted.
int update_time_stamp(struct timestamp *);
// create a directory mapping.
int create_directory_mapping(struct directory *);
// generate unique inode number
unsigned long int generate_unique_inode_num();
#endif
