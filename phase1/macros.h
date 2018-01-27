/*Header file which contains the basic macros for our file system
 * Ravi Shreyas Anupindi
 * Rishabh Dutt
 * Rajat Nigam
*/
#ifndef MACROS_H_
#define MACROS_H_

#define DISK_BLOCKS 128

#define BLOCK_SIZE 4096
#define UNION_SIZE 4080

#define NUM_INODES 16 /*roughly close to 10% of the disc blocks */

/* #define BLOCKS_PER_FILE 4 */

#define MAX_LENGTH 255

#define POINTERS_PER_BLOCK (BLOCK_SIZE / sizeof(int))

#define I_BLOCK 0x00 //flag for inode block
#define D_BLOCK 0x01 //flag for data block
#define P_BLOCK 0x02 //flag for indirect block

#define NR_DISK_BLOCK 125000 //Total Number of disk blocks we have for our filesystem.
#define DISK_NUM 	1 //Basically we have only one disk.
#define IN_USE 	1
#define COMPLETELY_FILLED 2
#define INODE_START 1
#define INODE_END 16
#define MAX_INODE_SPACE 72
#endif
