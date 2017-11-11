
//INCLUDE COMPILER HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>


#include"cure.h"
#include"storefile.h"
#include"filecounters.h"
#include"traversor.h"


int main(){
	system("CLS");
	system("color 0A");
    char *loc;
    loc = ".\\folder";
    fileScan(loc,0);
    getch();
	system("color 07");                         
	system("CLS");
return 0;
}
