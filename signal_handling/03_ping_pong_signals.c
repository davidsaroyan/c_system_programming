#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
pid_t pid = 0;
int rounds = 0;
void chldhandler(int signo){
	(void)signo;
	printf("Child: Ping!\n");
	kill(getppid(), SIGUSR2);
}
void phandler(int signo){
	(void)signo;
	printf("Parent: Pong!\n");
	++rounds;
	if(rounds < 5){
		sleep(1);
		kill(pid, SIGUSR1);
	}
}
int main(){
	signal(SIGUSR1, chldhandler);
	signal(SIGUSR2, phandler);
	pid = fork();
	if(pid < 0){
		perror("fork");
		return 1;
	}
	else if(pid == 0){
		while(1){
			pause();
		}
	}
	else{
		sleep(1);
		kill(pid, SIGUSR1);
		while(rounds < 5){
			pause();
		}
		kill(pid, SIGTERM);
		wait(NULL);
		printf("Parent: child terminated\n");
	}
	return 0;
}
