#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bof_function(char *s){

	char buffer[24];
	strcpy(buffer, s);

	return 1;
}

int main(){
	
	char str[517];
	FILE *errorFile;
	errorFile = fopen("errorFile", "r");
	fread(str, sizeof(char), 517, errorFile);

	bof_function(str);
	printf("Returned ok\n");
	return 1;
}
