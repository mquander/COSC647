#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int get_two_vars(int sock, char *out, int len){
	char buf1[512], buf2[512];
        unsigned int size1, size2;
        unsigned int size;

        if(recv(sock, buf1, sizeof(buf1), 0) < 0){
            return -1;
        }
        if(recv(sock, buf2, sizeof(buf2), 0) < 0){
            return -1;
        }

        /* packet begins with length information */
        memcpy(&size1, buf1, sizeof(int));
        memcpy(&size2, buf2, sizeof(int));

        size = size1 + size2;
        if(size > len){
            return -1;
        }else if(!(size > size1 + size2))
		return -1;

        memcpy(out, buf1, size1);
        memcpy(out + size1, buf2, size2);
        return size;
}

int main(){
	
	printf("%d\n", get_two_vars(3000, "ABC", 22));
	
}
