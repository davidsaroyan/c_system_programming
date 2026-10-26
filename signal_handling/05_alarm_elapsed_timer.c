#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
int sec = 0;
int counter = 0;
void handler(int signo){
	counter += sec;
	if(counter >= 10){
		printf("Time is up: [%d seconds]\n", counter);
		exit(0);
	}
	printf("Elapsed time: %d seconds\n", counter);
	alarm(sec);
}
int main(){
	signal(SIGALRM, handler);
	printf("Input seconds: ");
	scanf("%d", &sec);
	alarm(sec);
	while(1){
		pause();
	}
}
