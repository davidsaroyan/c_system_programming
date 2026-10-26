#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MAX_ARGS 32
void do_cmd(char * cmd){
	char * argv[MAX_ARGS];
	int argc = 0;
	for(char * tok = strtok(cmd, " \t"); tok != NULL && argc < MAX_ARGS - 1; tok = strtok(NULL, " \t")){
		argv[argc++] = tok;
	}
	argv[argc] = NULL;
	if(argc == 0){
		return;
	}

	pid_t pid = fork();
	if(pid == -1){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		execvp(argv[0], argv);
		perror(argv[0]);
		_exit(127);
	}
	else{
		int status;
		if(waitpid(pid, &status, 0) == -1){
			perror("waitpid");
		}
	}
}

int main(){
	char cmd [200] = {};
	while(1){
		printf("Enter command: \n");
		if(fgets(cmd, sizeof cmd, stdin) == NULL){
			return 0;
		}
		cmd[strcspn(cmd, "\n")] = '\0';
		if(strcmp(cmd, "exit") == 0){
			return 0;
		}
		do_cmd(cmd);
	}
}
