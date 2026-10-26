#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
char cmd[512];
void handler(int signo){
	(void)signo;
	system(cmd);
}

int main(int argc, char *argv[]){
	const char *path = argc > 1 ? argv[1] : "/home/david/Music/sound.wav";
	snprintf(cmd, sizeof(cmd), "aplay %s", path);
	signal(SIGALRM, handler);
	int sec = 0;
	printf("Input seconds for alarm: ");
	if(scanf("%d", &sec) != 1 || sec <= 0){
		printf("Seconds must be a positive number\n");
		return 1;
	}
	alarm(sec);
	pause();
	return 0;
}
