#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
  char* path;
  for(int i = 1; i<=argc; i++){
  	path = "/";
	path = strcat(path, argv[i]);
  }
  chdir(path);
  return 0;

}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;
  char name[200];
  getcwd(name, 200);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
while(strcmp(argv[0], "cd") == 0){
  if(argc == 1){
	return 0;
  }else if(argc==3 && strcmp(argv[1], ".")==0 && strcmp(argv[2], ".")==0){
        return 0;
  }else if(argc>=2){
	return 1;
  }
}
return 0;
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
while(strcmp(argv[0], "pwd")==0){
  if(argc >= 2){
	return 0;
  }else if(argc == 1){ 
	return 1;
  }
}
return 0;
}
