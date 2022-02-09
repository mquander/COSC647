/* stack.c */

/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str_bof)
{
    char buffer[24];

    /* The following statement has a buffer overflow problem */ 
    strcpy(buffer, str_bof);

    return 1;
}

int main(int argc, char **argv)
{
    char str_main[517];
    FILE *badfile;

    badfile = fopen("badfile", "r");
    fread(str_main, sizeof(char), 517, badfile);
    bof(str_main);

    printf("Returned Properly\n");
    return 1;
}
