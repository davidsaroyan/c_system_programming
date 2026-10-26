#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <math.h>
#include <stdlib.h>

static void calc_log(int n)
{
    printf("log2(%d) = %0.2f, pid = %d\n", n, log2(n), getpid());
}

static void calc_fact(int n)
{
    printf("fact(%d) = %0.2lf, pid = %d\n", n, tgamma((double)n + 1), getpid());
}

static void calc_cube(int n)
{
    printf("%d ^ 3 = %0.0f, pid = %d\n", n, pow(n, 3), getpid());
}

int main()
{
    void (*tasks[])(int) = {calc_log, calc_fact, calc_cube};
    const int count = sizeof tasks / sizeof tasks[0];
    pid_t pids[3];

    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        fprintf(stderr, "please enter a positive integer\n");
        return 1;
    }

    for (int i = 0; i < count; ++i)
    {
        pids[i] = fork();
        if (pids[i] == -1)
        {
            perror("fork");
            return 1;
        }
        if (pids[i] == 0)
        { // child process
            tasks[i](n);
            exit(0); // exit, not _exit: stdout must be flushed
        }
    }

    // parent process
    int status;
    pid_t winner = wait(&status);
    if (winner == -1)
    {
        perror("wait");
        return 1;
    }
    printf("winner: pid %d\n", winner);

    for (int i = 0; i < count; ++i)
    {
        if (pids[i] == winner)
            continue; // already reaped
        kill(pids[i], SIGTERM);
        waitpid(pids[i], NULL, 0);
    }
    return 0;
}
