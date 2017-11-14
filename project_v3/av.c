
//INCLUDE COMPILER HEADER FILES
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
#include<windows.h>

char strbuff[1024];


#include"cure.h"
#include"storefile.h"
#include"filecounters.h"
#include"traversor.h"
#include"printCredits.h"

int main(){

	system("CLS");
	system("color 0A");
    char *loc;
    loc = ".\\folder";
		clock_t session_start, session_stop;
		float session_time;
		session_start = clock();
    fileScan(loc,0);
		session_stop = clock();
		session_time = ((float)session_stop-(float)session_start)/(float)CLOCKS_PER_SEC;
		printf("\n-- THE COMPLETE SESSION TOOK %f s TO COMPLETE --\n",session_time);
		Sleep(750);
		printf("-- THANK YOU FOR USING OUR ANTIVIRUS --\n");
		Sleep(750);
		printCredits();
    getch();
	system("color 07");
	system("CLS");
return 0;
}
