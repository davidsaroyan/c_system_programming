#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(){
	char str[50];
	printf("Input for echo: \n");
	if(fgets(str, sizeof str, stdin) == NULL){
		fprintf(stderr, "no input\n");
		return 1;
	}
	str[strcspn(str, "\n")] = '\0';

	pid_t pid = fork();
	if(pid < 0){
		perror("fork");
		return 1;
	}
	else if(pid == 0){
		execl("/bin/echo", "echo", str, (char*) NULL);
		perror("execl");
		_exit(127);
	}
	else{
		int status;
		if(waitpid(pid, &status, 0) == -1){
			perror("waitpid");
			return 1;
		}
	}
	return 0;
}
