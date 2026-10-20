#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void do_cmd(const char * cmd){
	pid_t pid = fork();
	if(pid == -1){
		exit(-1);
	}else if(pid == 0){
		system(cmd);
	}
	else{
		wait(NULL);
	}
}

int main(){
	char cmd [200] = {};
	while(1){
		printf("Enter command: \n");
		fgets(cmd, 200, stdin);
		if(strncmp(cmd, "exit\n", 5) == 0){
			return 0;
		}
		cmd[strlen(cmd) - 1] = '\0';
		do_cmd(cmd);
	}
}
