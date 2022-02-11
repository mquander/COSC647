#include <stdio.h>
#include <string.h>


int copy_something(char *buf, unsigned int len){

	char kbuf[800];
	if(len < 0 || len > sizeof(kbuf)){	
		return -1;
	}

	return memcpy(kbuf, buf, len);
}

int main(){

	int num;
	printf("Enter a number between 0 and 800 to enter into buffer: ");
	scanf("%d", &num);

	char *str = "ABCD";
	int returnValue = copy_something(str, num);

	if(returnValue == -1)
		printf("-1 -> bad return\n");
	else{
		printf("0 -> good return\n");
		printf("%s\n", copy_something(str, num));
	}
		
	return 0;

}
