#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define N 3

int main(){
	pid_t pid[N];
	for(int i = 0; i < N; ++i){
		pid[i] = fork();
		if(pid[i] < 0){
			perror("fork");
			for(int j = 0; j < i; ++j){
				kill(pid[j], SIGTERM);
				waitpid(pid[j], NULL, 0);
			}
			return 1;
		}
		if(pid[i] == 0){
			sleep(N - i);   // different delays, so there is a real winner
			_exit(i);
		}
	}

	int status;
	pid_t ended_pid = wait(&status);
	if(ended_pid == -1){
		perror("wait");
		return 1;
	}
	if(WIFEXITED(status))
		printf("1st finished PID: %d\nexit code: %d\n", ended_pid, WEXITSTATUS(status));

	for(int i = 0; i < N; ++i){
		if(pid[i] == ended_pid)
			continue;   // already reaped: its PID may now belong to someone else
		if(kill(pid[i], SIGTERM) == 0)
			printf("Sent SIGTERM to pid: %d\n", pid[i]);
		if(waitpid(pid[i], &status, 0) > 0 && WIFSIGNALED(status))
			printf("pid %d terminated by signal %d\n", pid[i], WTERMSIG(status));
	}
	return 0;
}
