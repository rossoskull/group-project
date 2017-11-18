
//GET NUMBER OF CHARACTERS IN A FILE
// a - PATH OF THE FILE
int charFile(char *a){
  FILE *f;
  f = fopen(a, "r");
  int count = 0;
  char c;
  // UNTIL END OF FILE IS REACHED, COUNT THE NUMBER OF CHARACTERS
  while (1) {
        c = fgetc(f);
        if (c == EOF)
            break;
        ++count;
    }


  fclose(f);
  return count; // RETURNS NUMBER OF CHARACTERS IN THE FILE
}
// ==================================================================

//GET NUMBER OF LINES IN FILE
// a - PATH OF THE FILE
int lineFile(char *a){
  FILE *f;
  f = fopen(a, "r");
  int count = 0;
  char buff[1024];
  
  // UNTIL THE END OF FILE IS REACHED, COUNTS THE NUMBER OF LINES
  while (!feof(f)) {
    fgets(buff, 1024, f);
    count++;
  }
  fclose(f);
  return count; // RETURNS NUMBER OF LINES IN THE FILE
}
// =================================================================
