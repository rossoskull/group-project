// Check if a file is infected and if yes, then cure it.

void cure(char *data, char secstr[][1024], int nov, char *a, int nC){
  int i,j,k,l;
  int changes=0;
  char mainstr[nC+1];
  for(i=0; i< nC-1; i++){
    mainstr[i] = data[i];
  }

  //----
  clock_t start, end;
  double timetaken;
  //----
  start = clock();

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
				  changes++;
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
  char minibuff[1024];
  printf(" |  %d Viruses found and fixed. ", changes);
  sprintf(minibuff, "VIRUSES FOUND AND FIXED: %d | ", changes);
  strcat(strbuff, minibuff);
  end = clock();
  timetaken = ((double)end - (double)start)/(double)CLOCKS_PER_SEC;
  printf(" |  Time taken in the process : %lf s | ", timetaken);
  sprintf(minibuff,"TIME TAKEN: %lf s\n\n", timetaken);
  strcat(strbuff, minibuff);
  f = fopen("log.txt", "a");
  fprintf(f, "%s", strbuff);
  fclose(f);
}


// =========================================================================
