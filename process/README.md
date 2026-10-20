# Process Management in C (Linux System Programming)

This directory contains practical exercises focusing on Linux process creation, control, execution, and synchronization using system calls like `fork()`, `exec*()`, `wait()`, and `kill()`.

## Exercises Overview

* **`01_fork_basics.c`**: Implemented basic process creation using `fork()`. The parent process prints its own PID and the child's PID, while the child prints its own PID and its parent's PID using `getpid()` and `getppid()`, inspecting the exit status using `waitpid()`.
* **`02_race_first_child.c`**: Spawned 3 child processes concurrently, used `wait()` to catch the first child to finish, and terminated the remaining active sibling processes.
* **`03_child_wait_delay.c`**: Configured a child process to delay execution via `sleep(5)` while the parent waits and logs a completion message.
* **`04_parent_kill_child.c`**: Designed a scenario where a child prints its PID every second and the parent uses `kill()` to terminate it after 3 seconds.
* **`05_execv_ps.c`**: Executed the `/bin/ps -ef` command from a child process using the `execv()` system call.
* **`06_execl_echo.c`**: Spawned a child process to execute the `echo` command using `execl()`.
* **`07_mini_shell.c`**: Built an interactive command-line loop that reads custom Linux commands from standard input, forks a child process to execute them, and loops until the user types `exit`.
* **`08_math_competition.c`**: Implemented a parallel math race where the parent passes an input integer to 3 children calculating $\log_2$, factorial, and cube respectively, catching the winner and killing the rest.
* **`09_exec_ls_detailed.c`**: Used a child process to display directory contents with full metadata via `ls -la`.
* **`10_sequential_children.c`**: Sequentially spawned two children—the first listing directory contents, and the second printing the absolute path using `pwd`.