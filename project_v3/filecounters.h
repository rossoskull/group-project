
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
