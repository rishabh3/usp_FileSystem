#include "dir.h"
#include "../fs.h"
#include "../block.h"
#include <string.h>

struct disk_block disk_block[];

bool make_directory(char* pathname){
	// Needs to be thought upon
	struct inode new_inode;
	struct directory new_dir;
	strcpy(new_dir.name, ".\0");
	//new_inode.disk = DISK_NUM;
	new_inode.inode_num = generate_unique_inode_num();
	new_dir.inode_num = new_inode.inode_num;
	new_inode.size = BLOCK_SIZE;
	new_inode.mstring = set_mode_of_file(1);
	new_inode.tstamp = set_time_for_file(1);
	preprocess(disk_block);
	int index = find_free_inode_block(disk_block);
	disk_block[index].diskblocknumber = index;
	disk_block[index].block_flag = I_BLOCK;
	disk_block[index].filled = IN_USE;
	int index_space = find_free_inode_space(disk_block[index].buf_type.iblock);
	disk_block[index].buf_type.iblock[index_space] = new_inode;
 	
}
