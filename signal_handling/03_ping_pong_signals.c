#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
pid_t pid = 0;
void chldhandler(int signo){
	printf("[CHILD] Ping!\n");
	kill(getppid(), SIGUSR2);
}
void phandler(int signo){
	printf("[PARENT] Pong!\n");
	sleep(1);
	kill(pid, SIGUSR1);
}
int main(){
	pid = fork();
	if(pid < 0){
		printf("FORK FAILED\n");
	}
	else if(pid == 0){
		signal(SIGUSR1, chldhandler);
	}
	else{
		signal(SIGUSR2, phandler);
		sleep(1);
		kill(pid, SIGUSR1);
	}
	for(int i = 0; i < 5; ++i){
		pause();
	}
}
