#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char* argv[]){
	int pipefds[2];
	char buf[30];
	if(pipe(pipefds) == -1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	printf("writing to file descriptor #%d\n",pipefds[1]);
	write(pipefds[1],"CSCI3150",9);
	printf("reading from file descriptor #%d\n", pipefds[0]);
	read(pipefds[0], buf,9);
	printf("read \"%s\"\n",buf);
	return 0;
}
