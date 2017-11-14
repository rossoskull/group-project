void printCredits(){

char names[4][50];
strcpy(names[0], "JAY MISTRY - ID:201751025");
strcpy(names[1], "NEERAJ RAJPUROHIT - ID:201751027");
strcpy(names[2], "NILESH KOLI - ID:201751027");
strcpy(names[3], "CHANCHAL SAINI - ID:201751027");

printf("--A PROJECT BY - --\n");
Sleep(750);
int i,j;
for (i=0; i<4; i++) {
  printf("-:");
  for ( j=0 ; j<strlen(names[i]) ; j++) {
      printf("%c", names[i][j]);
      Sleep(50);
  }
  Sleep(250);
  printf("\n");

}

}
