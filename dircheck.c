#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

/* 
C program to check if the contents of a give directory are directories or files, by Jay Mistry.
New concepts - structs, pointers.
New libraries - sys/types.h, sys/stat.h, unistd.h, dirent.h.
It is an important snippet for our future project.
*/
int main(){
    DIR *pwd;
    pwd = opendir(".");
    struct stat st;
    struct dirent *sd;

    if(pwd == NULL ){
        printf("Unable to open Directory");
        exit(1);
    }

    while (  (sd=readdir(pwd)) != NULL ){
        printf(">>%s \t", sd->d_name);
        stat(sd->d_name, &st);
        if(S_ISDIR(st.st_mode)){
            printf("Directory\n");
        } else {
            printf("File\n");
        }

    }

return 0;
}
