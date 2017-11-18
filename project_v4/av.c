/*
A CODE THAT INJECTS AND CURES USER DEFINED VIRUSES INTO A FOLDER'S COMPONENTS.
FILES IN THIS PROJECT:
av.c
traversor.h
storefile.h
cure.h
filecounters.h
printCredits.h
menu.h
enterv.h
*/

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


//GLOBAL VARIABLES USED THROUGHOUT THE CODE
char strbuff[1024]; //A CONTAINER STRING FOR PRINTING INTO THE LOG FILE
char c; //FUNCTION WE WANT TO USE
int nInfects=0; //NUMBER OF VIRUSES WE WOULD LIKE TO ENTER


//INCLUDE OUR HEADER FILES
#include"cure.h"
#include"storefile.h"
#include"filecounters.h"
#include"traversor.h"
#include"printCredits.h"
#include"menu.h"
#include"enterv.h"


int main() {
	againhere: //A LABEL WHERE CONTROL WILL PASS IN THE END BASED ON THE USER INPUT
	system("CLS");
	system("color 0A");
    char *loc; //STORE THE LOCATION OF BASE DIRECTORY
		printMenu(); //PRINT THE MENU
		c = getch();
		if ( c == '1' ) {
			system("CLS");
			printf("You chose to Infect the files.\n");
			printf("Enter how many many viruses you would like to inject : ");
			scanf("%d", &nInfects);
		} if ( c == '3' ) {
			enterV();
			goto end;
			
		}

		system("CLS");

    loc = ".\\folder";
		clock_t session_start, session_stop; //CLOCK VARIABLES FOR CALCULATING COMPLETE PROCESS TIME
		float session_time; //COMPLETE SESSION TIME WILL BE STORED HERE
		session_start = clock();
		
		fileScan(loc,0);
		
		session_stop = clock();
		session_time = ((float)session_stop-(float)session_start)/(float)CLOCKS_PER_SEC;
		printf("\n-- THE COMPLETE SESSION TOOK %f s TO COMPLETE --\n",session_time);

		FILE *f = fopen("log.txt", "a");
	    fprintf(f, "\n\n", strbuff);
	    fclose(f);

		end:
		Sleep(750);
		printf("Would you like to continue further? (y/n) :\n");
		c = getch();
		if (c=='y' || c=='Y') {
			goto againhere; //GOTO THE againhere LABEL
		}
		system("CLS");
		printf("-- THANK YOU FOR USING OUR ANTIVIRUS --\n");
		Sleep(750);
		printCredits(); //PRINT THE CREDITS
    getch();
	system("color 07");
	system("CLS");
return 0;
}
