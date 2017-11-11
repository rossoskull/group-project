
// FILE TRAVERSION CODE
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
            printf(" (File) ");
            //The virus checking algorithm will be implemented here.
            int nChar = charFile(path);
            printf(" |  Characters = %d ", nChar);
            int nVirus = lineFile("viruses.dat");
			printf(" | PATH =  %s ", path);
            if(nChar==0){
			printf("\n");

              continue;
            }
            storeFile(path, nChar, nVirus);
			printf("\n");

        }

    }

}

// ========================================================================