#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	pid_t pid = fork();
	
	if(pid < 0){
		printf("fork failed\n");
	}
	else if(pid == 0){
		char * str;
		printf("Input for echo: \n");
		fgets(str, 50, stdin);
		execl("/bin/echo", "echo", str, (char*) NULL);
	}
	else{
		int status;
		wait(&status);
	}
}
