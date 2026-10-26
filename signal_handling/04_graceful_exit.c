#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo){
	printf("Do you really want to exit? (y/n)\n");
	char input = 0;
	scanf("%c", &input);
	if(input == 'y'){
		printf("Cleaning up resources...\n");
		exit(0);
	}else if(input == 'n'){
		kill(getpid(), SIGCONT);
	}
	else{
		printf("Invalid input\n");
		kill(getpid(), SIGINT);
	}
}
int main(){
	signal(SIGINT, handler);
	while(1){
		printf("Working...\n");
		sleep(1);
	}
}
