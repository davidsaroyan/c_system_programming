#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int main(){
	sigset_t sigset;
	sigset_t prev;
	sigemptyset(&sigset);
	sigemptyset(&prev);
	sigaddset(&sigset, SIGINT);
	sigprocmask(SIG_BLOCK, &sigset, &prev);
	int i = 0;
	while(1){
		printf("Saving...%d / 5 (CAN'T INTERRUPT)\n", i);
		sleep(1);
		++i;
		if(i == 5)
			break;
	}
	sigprocmask(SIG_UNBLOCK, &sigset, &prev);
	printf("Now you can interrupt\n");
	while(1){
		printf("working..\n");
		sleep(2);	
	}
}
