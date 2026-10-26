#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    else if (pid > 0)
    { // parent process
        int status;
        pid_t chpid = wait(&status);
        if (chpid == -1)
        {
            perror("wait");
            return 1;
        }
        if (WIFEXITED(status))
            printf("Child %d, finished with exit code: %d\n", chpid, WEXITSTATUS(status));
    }
    else
    { // child process
        execlp("ls", "ls", "-l", "-a", (char *)NULL);
        perror("execlp"); // only reached if exec failed
        _exit(127);
    }
    return 0;
}
