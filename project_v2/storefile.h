
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
  fclose(f);
  cure(data, virus, nV,a, nC);

}


// ==========================================================================