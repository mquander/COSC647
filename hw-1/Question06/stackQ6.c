#include <stdio.h>
#include <string.h>

int function(){

	char buffer[5];
	strcpy(buffer, "ABCDEFGHIJ");
	return 1;
}

int main(){
	
	function();
	printf("End\n");
	return 1;
}

