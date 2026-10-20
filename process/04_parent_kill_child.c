#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
	pid_t pid = fork();
	if(pid < 0){
		printf("fork failed\n");
	}else if(pid == 0){
		while(1){
			printf("%d\n", getpid());
			sleep(1);
		}
	}else{
		sleep(3);
		if(kill(pid, SIGTERM) == 0){
			printf("Child finished\n");
		}
	}
	
}
