#include "block.h"
#include <stdio.h>
#include "fs.h"
struct disk_block disk_block[];
int main(){
	printf("%ld\n", sizeof(disk_block[0]));
	printf("%ld\n", sizeof(disk_block[0].buf_type));
	printf("%ld\n", sizeof(struct inode));
	return 0;
}
