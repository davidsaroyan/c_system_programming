#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo){
	(void)signo;
	char input = 0;
	do{
		printf("Do you really want to exit? (y/n)\n");
		if(scanf(" %c", &input) != 1)
			exit(1);
	}while(input != 'y' && input != 'n');
	if(input == 'y'){
		printf("Cleaning up resources...\n");
		exit(0);
	}
}
int main(){
	signal(SIGINT, handler);
	while(1){
		printf("Working...\n");
		sleep(1);
	}
}
