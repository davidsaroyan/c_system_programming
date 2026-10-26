#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
	pid_t pid = fork();
	if(pid < 0){
		perror("fork");
		return 1;
	}else if(pid == 0){
		while(1){
			printf("%d\n", getpid());
			fflush(stdout);   // otherwise output piped to a file is lost when SIGTERM arrives
			sleep(1);
		}
	}else{
		sleep(3);
		if(kill(pid, SIGTERM) == -1){
			perror("kill");
			return 1;
		}
		int status;
		if(waitpid(pid, &status, 0) == -1){
			perror("waitpid");
			return 1;
		}
		if(WIFSIGNALED(status))
			printf("Child finished, killed by signal %d\n", WTERMSIG(status));
	}
	return 0;
}
