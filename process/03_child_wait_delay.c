#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork();
	if(pid < 0){
		printf("fork failed\n");
	}
	else if(pid == 0){
		sleep(5);
	}
	else{
		int status;
		pid_t chpid = wait(&status);
		printf("Child finished, pid: %d\n", chpid);
	}
}
