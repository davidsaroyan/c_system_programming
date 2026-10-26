#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
int sec = 0;
int counter = 0;
void handler(int signo){
	(void)signo;
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
	if(scanf("%d", &sec) != 1 || sec <= 0){
		printf("Seconds must be a positive number\n");
		return 1;
	}
	alarm(sec);
	while(1){
		pause();
	}
}
