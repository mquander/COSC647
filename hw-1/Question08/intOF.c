#include <stdio.h>
/* a C program that contains an integer overflow when 
   user inputs an integer over 65,535 it wraps around to 0*/

int main(){
	
	unsigned short int x;
	unsigned int y;

	printf("Enter a number from 0 to 100: ");
	scanf("%i", &y);
	
	x = y;
	if(x >= 0 && x <= 100)
		printf("%i --> good entry\n", y);

	else
		printf("%i --> bad entry\n", y);

	return 0;
}
