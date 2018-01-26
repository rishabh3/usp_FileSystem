/* USP PROJECT --- Phase1 *
 * Ravi Shreyas 	  *
 * Rishabh Dutt	 	  *
 * Rajat Nigam     	  */
#ifndef DIR_H_
#define DIR_H_
#include <stdbool.h>
/* File contains prototype for directory functions.*/
// Implement mkdir, pwd, rmdir etc.
char* get_current_directory();
bool make_directory(char* pathname);
bool remove_directory(char* pathname);
bool change_directory(char* pathname); 
#endif
