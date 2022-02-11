#include <stdio.h>
#include <stdlib.h>

int myfunction(int *array, int len){

	int *myarray, i;
	if(len < 0 || len > 10000)
		return -1;
	myarray = malloc(len * sizeof(int)); 
	if(myarray == NULL)
		return -1;

	for(int i=0; i < len; i++){
		myarray[i] = array[i];		
	}
	return myarray;
}

int main(){

	int arr[4] = {1, 2, 3, 4};
	int returnValue = myfunction(arr, -1);
	if(returnValue == -1)
		printf("Error: \n");
	else
		printf("good \n");
	
}
