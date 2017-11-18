//FUNCTION CURE - IT CHECKS IF VIRUSES ARE PRESENT AND THEN REMOVES THEM
// data - CONTAINS THE COMPLETE DATA OF THE FILE TO BE SCANNED
// secstr - AN ARRAY OF ALL THE VIRUSES DEFINED BY THE USER
// nov - NUMBER OF VIRUSES DEFINED BY THE USER
// a - CONTAINS THE PATH OF THE CURRENT FILE
// nC - CONTAINS THE NUMBER OF CHARACTERS IN A FILE
void cure(char *data, char secstr[][1024], int nov, char *a, int nC) {

  int i,j,k,l;
  int changes=0; // NUMBER OF VIRUSES SCANNED AND FIXED
  char mainstr[nC+1]; // CONTAINS A COPY OF THE DATA OF THE FILE

  //COPIES THE DATA IN data INTO THE mainstr VARIABLE
  for (i=0; i< nC-1; i++) {
    mainstr[i] = data[i];
  }

  //----
  clock_t start, end; // TIME VARIABLES TO CALCULATE THE TIME TAKEN FOR PROCESS SPECIFIC TO CURRENT FILE
  double timetaken; // IT WILL CONTAIN THE TIME TAKEN
  //----
  start = clock(); // STORE THE INITIAL CLOCK TIME

  
  // LOOP TO CHECK FOR VIRUSES IN THE STRING. NUMBER OF SPACES ARE IGNORED.
  for ( i=0 ; i<strlen(mainstr) ; i++ ) {
      for ( j=0 ; j<nov ; j++) {
          if ( mainstr[i]==secstr[j][0]) {
            int isit = 0;
              for ( k=1, l=i+1 ; k<strlen(secstr[j]); k++, l++) {
                  if ( mainstr[l] == ' ' || mainstr[l]== '\n' || secstr[j][k] == ' ' || secstr[j][k]== '\n'  ) {
                    if ( mainstr[l] == ' ' || mainstr[l]== '\n' ) {
                      k--;
                    }

                    if ( secstr[j][k] == ' ' || secstr[j][k]== '\n' ) {
                      l--;
                    }
                    continue;

                  }

                  if ( mainstr[l]!=secstr[j][k] ) {
                    isit=1;
                    break;
                  }
              }

              if ( isit==0 ) {
				  changes++;
                int init = i, fin = l;
                int x;
                for (x = init; x < fin ; x++) {
                  mainstr[x] = ' ';
                }
              }
          }
      }

  }

  FILE *f;
  f = fopen(a, "w"); // OPEN THE CURRENT FILE
  fprintf(f, "%s", mainstr); // COPY THE CURED DATA IN THE FILE, REPLACING THE INFECTED DATA IN THE PROCESS
  fclose(f);
  
  char minibuff[1024]; // A STRING FOR STORING SMALL PARTS OF STRINGS TO BE PRINT IN THE LOG.TXT FILE
  printf(" |  %d Viruses found and fixed. ", changes); // SHOWING THE NUMBER OF VIRUSES CURED TO THE USER
  
  sprintf(minibuff, "VIRUSES FOUND AND FIXED: %d | ", changes);
  strcat(strbuff, minibuff);
  end = clock(); // STORE THE END CLOCK TIME
  timetaken = ((double)end - (double)start)/(double)CLOCKS_PER_SEC; // CALCULATE THE TIME TAKEN
  printf(" |  Time taken in the process : %lf s | ", timetaken);
  sprintf(minibuff,"TIME TAKEN: %lf s\n\n", timetaken);
  strcat(strbuff, minibuff);


  f = fopen("log.txt", "a");
  fprintf(f, "%s", strbuff); // PRINT THE DATA OF THIS PROCESS IN THE LOG FILE
  fclose(f);

}


// =========================================================================
