#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
	pid_t pid [3]; 
	pid[0] = fork();
	for(int i = 0; i < 2; ++i){
		if(pid[0] < 0){
			printf("FORK FAILED\n");
		}
		else if(pid[i] > 0){
			pid[i+1] = fork(); 
		}
	}
	if(pid[0] != 0 && pid[1] != 0 && pid[2] !=0){
		int status;
		int ended_pid = wait(&status);
		printf("1st finished PID: %d\nstatus: %d\n", ended_pid, status);
		for(int i = 0; i < 3; ++i){
			if(kill(pid[i], SIGTERM) == 0)
				printf("Successfullly killed pid: %d\n", pid[i]);
		}
	}
	else{
		sleep(2);
	}
}
