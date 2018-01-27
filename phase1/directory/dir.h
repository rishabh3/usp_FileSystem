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
bool make_directory(char* );
bool remove_directory(char* );
bool change_directory(char* ); 
#endif
