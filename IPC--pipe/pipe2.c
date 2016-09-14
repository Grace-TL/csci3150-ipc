#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
	int pipefds[2];
	pid_t pid;
	char buf[30];
	if(pipe(pipefds)==-1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	memset(buf,0,30);
	pid = fork();
	
	if(pid>0){
		printf("PARENT write in pipe.\n");
		close(pipefds[0]);
		write(pipefds[1],"CSCI3150",9);
		close(pipefds[1]);
		wait(NULL);
	}else{
		close(pipefds[1]);
		while(read(pipefds[0],buf,1)==1){
			printf("CHILD read from pipe --%s\n",buf);
		}
		close(pipefds[0]);
		print(CHILD: "EXITING!");
		exit(EXIT_SUCCESS);
		
	}
}
