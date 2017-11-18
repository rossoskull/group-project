//ENTER VIRUSES INTO VIRUSES.DAT
void enterV () {
	printf("Enter your virus definition : \n>");
	char virus[1024];
	gets(virus);
	
	FILE *f;
	f = fopen("viruses.dat", "a");
	fprintf(f, "\n%s\n", virus);
	printf("Virus successfuly entered!\n");
	fclose(f);
	
	
	
}