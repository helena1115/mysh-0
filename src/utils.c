#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
char temp[10000] = "\0";
strcpy(temp, command); //copy command to temp

//argc
*argc = 1;
int j = 0;
int space_count = 0;
while(temp[j]){
	if(temp[j] == ' '| temp[j] == '\t')
		space_count++;
	j++;
}
*argc = (*argc)+space_count;

//allocation
*argv = (char**)malloc(sizeof(char*)*10000);

//parsing
char* token = strtok(temp, " \n\t");

if(token == NULL){
	(*argv)[0] = (char*)malloc(sizeof(char*)*10000);
	strcpy((*argv)[0], "");
	*argc = 1;
	return;
}else{
	int i;
	for(i=0; token != NULL; i++){
		(*argv)[i] = (char*)malloc(sizeof(char*)*10000);
		strcpy((*argv)[i], token);
		token = strtok(NULL, " \n\t");
	}
	*argc = i;
}
return;
}
