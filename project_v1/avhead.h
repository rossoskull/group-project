void storeFile( char *, int , int );
void cure(char [], char [][1024], int, char * , int);

//GET NUMBER OF CHARACTERS IN A FILE
int charFile(char *a){
  FILE *f;
  f = fopen(a, "r");
  int count = 0;
  char c;
  while (1) {
        c = fgetc(f);
        if (c == EOF)
            break;
        ++count;
    }


  fclose(f);
  return count;
}
// ==================================================================

//GET NUMBER OF LINES IN FILE
int lineFile(char *a){
  FILE *f;
  f = fopen(a, "r");
  int count = 0;
  char buff[1024];
  while(!feof(f)){
    fgets(buff, 1024, f);
    count++;
  }
  fclose(f);
  return count;
}
// =================================================================

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
            printf("Characters = %d", nChar);
            int nVirus = lineFile("viruses.dat");
            printf("\n");
            if(nChar==0){
              continue;
            }
            storeFile(path, nChar, nVirus);

        }

    }

}

// ========================================================================

//STORE FILE IN A SINGLE STRING, STORE THE VIRUSES AND THEN SCAN AND FIX viruses

void storeFile( char *a, int nC, int nV){
  FILE *f;
  f = fopen(a, "r");
  char data[nC+1], buff[1024], virus[nV][1024];
  strcpy(data, " ");
  while(!feof(f)){
    fgets(buff, 1024, f);
    strcat(data, buff);
  }
  fclose(f);

  f = fopen("viruses.dat", "r");
  int i=0;
  while(!feof(f)){
    fgets(buff, 1024, f);
    strcpy(virus[i], buff);
    i++;
  }

  cure(data, virus, nV,a, nC);

}


// ==========================================================================


// Check if a file is infected and if yes, then cure it.

void cure(char *data, char secstr[][1024], int nov, char *a, int nC){
  int i,j,k,l;
  char mainstr[nC+1];
  for(i=0; i< nC-1; i++){
    mainstr[i] = data[i];
  }
  for( i=0 ; i<strlen(mainstr) ; i++ ){
      for( j=0 ; j<nov ; j++){
          if( mainstr[i]==secstr[j][0]){
            int isit = 0;
              for( k=1, l=i+1 ; k<strlen(secstr[j]); k++, l++){
                  if( mainstr[l] == ' ' || mainstr[l]== '\n' || secstr[j][k] == ' ' || secstr[j][k]== '\n'  ){
                    if( mainstr[l] == ' ' || mainstr[l]== '\n' ){
                      k--;
                    }

                    if( secstr[j][k] == ' ' || secstr[j][k]== '\n' ){
                      l--;
                    }
                    continue;

                  }

                  if( mainstr[l]!=secstr[j][k] ){
                    isit=1;
                    break;
                  }
              }

              if(isit==0){
                int init = i, fin = l;
                int x;
                for(x = init; x < fin ; x++){
                  mainstr[x] = ' ';
                }
              }
          }
      }

  }

  FILE *f;
  f = fopen(a, "w");
  fprintf(f, "%s", mainstr);
  fclose(f);
}

// =========================================================================
