#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	pid_t pid = fork();
	if(pid < 0){
		perror("fork");
		return 1;
	}
	else if(pid == 0){
		char * arg[] = {"ps", "-ef", NULL};
		execv("/bin/ps", arg);
		perror("execv");   // only reached if execv failed
		_exit(127);
	}
	else{
		int status;
		if(waitpid(pid, &status, 0) == -1){
			perror("waitpid");
			return 1;
		}
		if(WIFEXITED(status))
			printf("ps exited with code %d\n", WEXITSTATUS(status));
	}
	return 0;
}
