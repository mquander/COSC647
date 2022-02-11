#include <stdio.h>
/* corrected C program that checks for an integer 
   overflow when user inputs an integer */

int main(){
	unsigned int y;
	unsigned short int x; // still causes errors at boundaries of signed int entries
	printf("Enter a number from 0 to 100: ");
	//scanf("%hu", &x);
	//scanf("%lu", &y);
	scanf("%i", &y);
	//printf("y= %d\n", y);
	//printf("y= %i\n", y);

	/*int a = y < 65536;
	int b = y >= 0;
	printf("%d\n", a);
	printf("%d\n", b);*/
	if(y < 65536 && y >= 0){ //x-65536 > 0
		x = y;
		if(x >= 0 && x <= 100)
			printf("%hu --> good entry\n", x);

		else
			printf("%hu --> bad entry\n", x);
	}
	else{
		printf("%i is out of range\n", y);
	}
	return 0;
}
