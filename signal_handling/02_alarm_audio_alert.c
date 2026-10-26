#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
void handler(int signo){
	system("aplay /home/david/Music/sound.wav");
}

int main(){
	signal(SIGALRM, handler);
	int sec = 0;
	printf("Input seconds for alarm: ");
	scanf("%d", &sec);
	alarm(sec);
	pause();
}
