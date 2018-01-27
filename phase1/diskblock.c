#include "block.h"

int find_free_inode_space(struct inode_block * inodes){
	int index = 0;	
	while(inodes[index].filled == IN_USE){
		index++;
	}
	return index;
}

int find_free_inode_block(struct disk_block *dblock){
	for(int i = INODE_START; i <= INODE_END;i++){
		if(dblock[i].filled != COMPLETELY_FILLED){
			return i;
		}
	}
	return -1;
}

void preprocess(struct disk_block *dblock){
	for(int i = INODE_START; i <= INODE_END;i++){
		if(dblock[i].filled != COMPLETELY_FILLED){
			if(no_free_inode_space(dblock[i].buf_type.iblock)){
				dblock[i].filled = COMPLETELY_FILLED;
			}	
			break;
		}
	}
}

bool no_free_inode_space(struct inode_block *iblock){
	int ind = 0;
	while(iblock[ind].filled == IN_USE){
		ind++;
	}
	if(ind >= MAX_INODE_SPACE){
		return true;
	}
	return false;
}
