#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	pid_t pid = fork();
	if(pid == -1){
		perror("fork");
		return 1;
	}
	else if(pid > 0){
		int status;
		pid = waitpid(pid, &status, 0);
		if(pid == -1){
			perror("waitpid");
			return 1;
		}
		if(WIFEXITED(status) && WEXITSTATUS(status) == 0)
			printf("Succesful child process\n");
		else
			printf("Something bad with child status\n");
		printf("Hello from parent: parent pid: %d\n", getpid());
		printf("Childs PID: %d\n", pid);
		printf("\n");
	}
	else{
		printf("Hello from child: parent pid: %d\n", getppid());
		printf("CHILLDS PID: %d\n", getpid());
		printf("\n");
	}
	return 0;
}
