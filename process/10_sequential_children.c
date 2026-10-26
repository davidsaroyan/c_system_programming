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
        printf("\n");
        pid = fork();
        if (pid == -1)
        {
            perror("Fork failed!\n");
            return -1;
        }
        else if (pid > 0)
        { // parent process
            int status;
            pid_t chpid = wait(&status);
            printf("\n");
        }
        else
        { // child process
            char *cmd = "pwd";
            system(cmd);
        }
    }
    else
    { // child process
        char *cmd = "ls";
        system(cmd);
    }
}