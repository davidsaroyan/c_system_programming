#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	pid_t pid = fork();
	if(pid < 0){
		printf("fork failed\n");
	}
	else if(pid == 0){
		char * arg[] = {"ps", "-ef", NULL};
		execv("/bin/ps", arg);
	}
	else{
		int status;
		wait(&status);
	}
}
