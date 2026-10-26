#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    const char *cmds[] = {"ls", "pwd"};
    const int count = sizeof cmds / sizeof cmds[0];

    for (int i = 0; i < count; ++i)
    {
        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork");
            return 1;
        }
        if (pid == 0)
        { // child process
            execlp(cmds[i], cmds[i], (char *)NULL);
            perror(cmds[i]);
            _exit(127);
        }

        // parent: wait for this child before starting the next one
        int status;
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
            return 1;
        }
        printf("\n");
    }
    return 0;
}
