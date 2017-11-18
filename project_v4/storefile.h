
//STORE FILE IN A SINGLE STRING, STORE THE VIRUSES AND THEN SCAN AND FIX VIRUSES
// a - CONTAINS THE PATH OF THE FILE
// nC - CONTAINS THE NUMBER OF CHARACTERS
// nV - CONTAINS THE NUMBER OF VIRUSES

void storeFile( char *a, int nC, int nV) {
  FILE *f;
  f = fopen(a, "r");
  char data[nC+1], buff[1024], virus[nV][1024];
  strcpy(data, " "); // INITIALLY COPIES A WHITESPACE IN THE data VARIABLE
  
  // LOOPS AND STORES EACH LINE IN BUFF, CONCATENATES IT INTO data VARIABLE
  while (!feof(f)) {
    fgets(buff, 1024, f);
    strcat(data, buff);
  }
  fclose(f);

  f = fopen("viruses.dat", "r");
  int i=0,j=0;
  
  // LOOPS AND STORES EACH VIRUS IN BUFF, CONCATENATES IT INTO data VARIABLE
  while (!feof(f)) {
    fgets(buff, 1024, f);
    strcpy(virus[i], buff);
    i++;
  }
  fclose(f);

  //INFECTING THE FILE AS PER THE CHOICE
  //IF THE NUMBER OF VIRUSES USER WANTS TO ENTER IS n, AND THE NUMBER OF VIRUSES DEFINED ARE m, THEN NUMBER OF VIRUSES INJECTED WILL BE mn
  if (c == '1') {
    f = fopen(a, "a"); //OPENS THE FILE AND APPENDS DATA TO IT
    while ( j<nInfects ) {
		for ( i=0 ; i<nV ; i++ ) {
		  fprintf(f, "%s\n", virus[i]);
		}
		j++;
  }
  fclose(f);
  return;
}
  cure(data, virus, nV,a, nC);
}


// ==========================================================================
