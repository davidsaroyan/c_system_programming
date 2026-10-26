#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("Fork failed!\n");
        return -1;
    }
    else if (pid > 0)
    { // parent process
        pid_t pid2 = fork();
        if (pid2 == -1)
        {
            perror("Fork failed!\n");
            return -1;
        }
        else if (pid2 > 0)
        { // parent process
            pid_t pid3 = fork();
            if (pid3 == -1)
            {
                perror("Fork failed!\n");
                return -1;
            }
            else if (pid3 > 0)
            { // parent process
                int status;
                pid_t chpid = wait(&status);
                kill(pid,SIGTERM);
                kill(pid2, SIGTERM);
                kill(pid3, SIGTERM);
            }
            else
            { // cube child process
                int res = pow(n,3);
                printf("%d ^ 3 = %d, pid = %d\n", n, res, getpid());
                exit(1);
            }
        }
        else
        { // fact child process
            double res = tgamma((double)n + 1);
            printf("fact(%d) = %0.2lf, pid = %d\n", n, res, getpid());
            exit(1);
        }
    }
    else
    { // log child process
        float res = log2(n);
        printf("log2(%d) = %0.2f, pid = %d\n", n, res, getpid());
        exit(1);
    }
}