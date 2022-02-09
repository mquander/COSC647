/*  vulp.c  */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define DELAY 0

int main() {
	char * fn = "/tmp/XYZ";
	char buffer[300];
  FILE *fp;
	long int i;
  /* get user input */
  scanf("%300s", buffer );

  if ( !access(fn, W_OK) ) {
		/*simulating the delay */
		for (i=0; i< DELAY; i++)	{
			int a = i*i;
		}
  	fp = fopen(fn, "a+");
    fwrite("\n", sizeof(char), 1, fp);
    fwrite(buffer, sizeof(char), strlen(buffer), fp);
    fclose(fp);
  }
  else printf("No permission \n");

	return 1;
}
