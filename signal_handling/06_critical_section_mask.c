#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int main(){
	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sigprocmask(SIG_BLOCK, &sigset, NULL);
	for(int i = 0; i < 5; ++i){
		printf("Saving...%d / 5 (CAN'T INTERRUPT)\n", i);
		sleep(1);
	}
	sigprocmask(SIG_UNBLOCK, &sigset, NULL);
	printf("Now you can interrupt\n");
	while(1){
		printf("working..\n");
		sleep(2);	
	}
}
