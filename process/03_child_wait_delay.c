#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork();
	if(pid < 0){
		perror("fork");
		return 1;
	}
	else if(pid == 0){
		sleep(5);
		_exit(0);
	}
	else{
		int status;
		pid_t chpid = wait(&status);
		if(chpid == -1){
			perror("wait");
			return 1;
		}
		printf("Child finished, pid: %d\n", chpid);
	}
	return 0;
}
