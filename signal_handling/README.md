# Signal Handling in C (Linux System Programming)

This directory contains practical exercises focusing on Linux signals: installing handlers, sending signals between processes, timers with `alarm()`, and blocking signals during critical sections, using calls like `signal()`, `kill()`, `alarm()`, `pause()`, and `sigprocmask()`.

## Exercises Overview

* **`01_sigusr1_to_child.c`**: Created a child process with `fork()` that installs a `SIGUSR1` handler, while the parent sends it `SIGUSR1` with `kill()` and the child's handler prints a message when the signal arrives.
* **`02_alarm_sound_alert.c`**: Set an `alarm()` for a user-supplied number of seconds and, when `SIGALRM` fires, played a sound alert with `system("aplay /path/to/sound.wav")`.
* **`03_ping_pong_signals.c`**: Built a parent–child "dialogue" with `SIGUSR1` and `SIGUSR2`: the child prints `Child: Ping!` and answers with `SIGUSR2`, the parent prints `Parent: Pong!`, waits 1 second with `sleep(1)` and sends `SIGUSR1` again, repeating 5 times before terminating the child.
* **`04_ctrl_c_cleanup.c`**: Ran an infinite loop printing `Working...` every second and caught Ctrl+C (`SIGINT`) to ask `Do you really want to exit? (y/n)`, printing `Cleaning up resources...` and calling `exit(0)` on `y` or continuing on `n`.
* **`05_alarm_elapsed_timer.c`**: Implemented a repeating timer where the user enters an interval in seconds, a `SIGALRM` handler prints the total elapsed time (`Elapsed time: N seconds`) and re-arms itself with `alarm()`, and the program prints `Time is up` and exits once 10 seconds have passed, sleeping in `pause()` between alarms.
* **`06_block_sigint_critical.c`**: Simulated an uninterruptible critical section by building a signal set containing only `SIGINT` with `sigemptyset()`/`sigaddset()`, blocking it with `sigprocmask(SIG_BLOCK)` for 5 seconds, then unblocking it with `SIG_UNBLOCK`.
