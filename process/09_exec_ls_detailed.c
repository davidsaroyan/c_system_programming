#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("Fork failed!\n");
        return -1;
    }
    else if (pid > 0)
    { // parent process
        int status;
        pid_t chpid = wait(&status);
        printf("Child %d, finished with status: %d\n", chpid, status);
    }
    else
    { // child process
        char *cmd = "ls -l -a";
        system(cmd);
        exit(1);
    }
}