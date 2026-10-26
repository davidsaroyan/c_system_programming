#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void handler(int signo){
	(void)signo;
	printf("[pid: %d] Just got signal SIGUSR1\n", getpid());
	exit(0);
}

int main(){
	signal(SIGUSR1, handler);
	pid_t pid = fork();
	if(pid < 0){
		perror("fork");
		return 1;
	}else if(pid == 0){
		pause();
	}
	else{
		sleep(1);
		kill(pid, SIGUSR1);
		int status;
		wait(&status);
	}
	return 0;
}
