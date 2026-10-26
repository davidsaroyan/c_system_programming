#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void handler(int signo){
	printf("[pid: %d] Just got signal SIGUSR1\n", getpid());
	exit(0);
}

int main(){
	pid_t pid = fork();
	if(pid < 0){
		printf("FORK FAILED\n");
	}else if(pid == 0){
		printf("chld");
		signal(SIGUSR1, handler);
		pause();
	}
	else{
		sleep(1);
		kill(pid, SIGUSR1);
		int status;
		wait(&status);
	}
}
