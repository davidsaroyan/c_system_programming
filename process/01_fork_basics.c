#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	pid_t pid = fork();
	if(pid == -1){
		printf("Fork failed!\n");
	}
	else if(pid > 0){
		int status = -1;
		pid = wait(&status);
		if(status == 0)
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
}
