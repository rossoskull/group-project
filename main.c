#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

/* 
C program to check if the contents of a give directory are directories or files, by Jay Mistry.
Also if the contents are directories, go into the directories and check their contents.
Thus, explore the complete file system.
New concepts - structs, pointers, recursive function.
New libraries - sys/types.h, sys/stat.h, unistd.h, dirent.h.
It is the basis code for file traversing.
*/


int main(){
    char *loc;
    loc = ".";
    fileScan(loc,0);
    getch();

return 0;
}



void fileScan(char *a, int ind){

    DIR *pwd;
    pwd = opendir(a);
    struct stat st;
    struct dirent *sd;

    if(pwd == NULL ){
        printf("Unable to open Directory");
        exit(1);
    }

    while (  (sd=readdir(pwd)) != NULL ){
    char *filename = sd->d_name;
    int i;
    if(!(strcmp(filename,".") == 0 || strcmp(filename,"..")==0)){
    if(ind>0){printf("|");}
    for(i=0;i<ind;i++){
       printf(" - ");
    }
    printf("> ");
    }
            if(strcmp(filename,".") == 0 || strcmp(filename,"..")==0){
                continue;
            } 
        printf("%s", sd->d_name);
        char *path;
            path = (char *)malloc( 1024 * sizeof(char ));           
            strcpy(path,a);
            char *slash;
            slash = "\\";
            strcat(path,slash);
            strcat(path,filename);
        stat(path, &st);
        if(S_ISDIR(st.st_mode)){
            printf(" (Directory)\n");
            
            fileScan(path,ind+1);
            

        } else {
            printf(" (File)\n");
            //The virus checking algorithm will be implemented here.
        }

    }

}

