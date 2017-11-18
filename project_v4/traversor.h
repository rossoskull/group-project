
// FILE TRAVERSION CODE
//a - PATH OF THE CURRENT DIRECTORY
//ind - THE LEVEL OF FILE/DIRECTORY W.R.T THE ROOT/HOME DIRECTORY
void fileScan(char *a, int ind){

    DIR *pwd; // DEFINED IN DIRENT.H
    pwd = opendir(a); // POINTS TO A DIRECTORY WITH PATH a
    struct stat st; // CREATES A STRUCT st- FROM sys/stat.h
    struct dirent *sd; //CREATES A STRUCT POINTER sd FROM sys/types.h

    if (pwd == NULL ) {
        printf("Unable to open Directory");
        exit(1);
    }

    while (  (sd=readdir(pwd)) != NULL ) { //READS THE COMPONENTS OF A DIRECTORY ONE BY ONE AND STORES IT IN sd STRUCTURE
		char *filename = sd->d_name; // d_name IS A VARIABLE IN THE DIRENT STRUCT. STORES NAME OF FILE/DIRECTORY
		int i;
		if (!(strcmp(filename,".") == 0 || strcmp(filename,"..")==0)) { // CHECKS IF IT IS A PARENT DIRECTORY
		if (ind>0) {
			printf("|");
			}
		//PRINTS -'S AS PER THE LEVEL W.R.T HOME DIRECTORY
		for (i=0;i<ind;i++) {
		   printf(" - ");
		}
		printf("> ");
		}
				if (strcmp(filename,".") == 0 || strcmp(filename,"..")==0) {
					continue; // IF IT IS A ROOT OR HOME DIRECTORY, WE SKIP FURTHER STEPS
				}
			printf("%s", sd->d_name);
			char *path;
				path = (char *)malloc( 1024 * sizeof(char )); // CREATE A PATH VARIABLE OF SIZE 1024
				strcpy(path,a);
				char *slash;
				slash = "\\";
				strcat(path,slash);
				strcat(path,filename);
			stat(path, &st);
			if (S_ISDIR(st.st_mode)) { //CHECKS IF IT IS A DIRECTORY. st_mode CONTAINS A CONSTANT VALUE - DIFFERANT FOR DIRECTORIES AND FILES. HELPS IN DISTINGUISHING BETWEEN FILES AND DIRECTORIES
				printf(" (Directory)\n");

				fileScan( path, ind+1); //RECURSIVE CALL TO fileScan FUNCTION


			} else {
				printf(" (File) ");
				int nChar = charFile(path); // GET NUMBER OF CHARACTERS IN A FILE
				printf(" |  Characters = %d ", nChar);
				int nVirus = lineFile("viruses.dat"); // GET NUMBER OF VIRUSES
				printf(" | PATH =  %s ", path);

			sprintf(strbuff, "NAME: %s | PATH: %s | CHARACTER SIZE: %d | ", filename, path, nChar); // STORING DATA IN strbuff FOR PRINTING IN LOG.TXT

				if (nChar==0) {
				printf(" | EMPTY FILE \n"); // IF IT IS AN EMPTY FILE, SKIPS FURTHER PROCESSES

				  continue;
				}
				storeFile(path, nChar, nVirus);
				printf("\n");

			}

    }

}

// ========================================================================
