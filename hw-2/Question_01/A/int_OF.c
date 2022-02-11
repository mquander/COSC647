#include <stdio.h>

int table[800];

int insert_in_table(int val, unsigned int pos){
	
	if(pos < 0 || pos > sizeof(table)/sizeof(int)){
			
		return -1;
	}

	table[pos] = val;
	return 0;
}

int main(){
	int num;
	printf("Enter a number between 0 and 800 to enter into array: ");
	scanf("%d", &num);
	int returnValue = insert_in_table(3, num);
	if(returnValue == 0)
		printf("%d -> good return\n", returnValue);
	else
		printf("%d -> bad return\n", returnValue);
	
	return 0;
}
