/* USP PROJECT --- Phase 1*
 * Ravi Shreyas		  *
 * Rajat Nigam		  */
#ifndef FILE_H_
#define FILE_H_
#include <stdbool.h>
#include <stddef.h>
/* Header file that contains functions related to the files. */
// System call for open, close, write, read, lseek
int open(char *,unsigned int);
bool close(int);
off_t lseek(int , off_t , int);
ssize_t read(int ,void *,size_t);  
ssize_t write(int,void *, size_t);  
#endif
