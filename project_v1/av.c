#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include"avhead.h"


int main(){
    char *loc;
    loc = ".\\folder";
    fileScan(loc,0);
    getch();

return 0;
}
