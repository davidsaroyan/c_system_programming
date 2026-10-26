# Signal Handling in C (Linux System Programming)

This directory contains practical exercises focused on asynchronous communication, signal handlers (`signal`), timers (`alarm`), signal blocking (`sigprocmask`), and process interruption control in Linux.

## Exercises Overview

* **`01_sigusr1_child.c`**: Demonstrates basic signal communication. A custom handler for `SIGUSR1` is installed before `fork()` so the child inherits it, then the parent sends the signal to the child, which prints a message and exits.
* **`02_alarm_audio_alert.c`**: Sets an asynchronous timer using `alarm()` and triggers an audio alert via `system("aplay ...")` when the countdown expires. The sound file path can be passed as the first argument (`./02_alarm_audio_alert /path/to/sound.wav`).
* **`03_ping_pong_signals.c`**: Organizes a synchronized "ping-pong" dialogue between parent and child using `SIGUSR1` and `SIGUSR2` for 5 iterations, after which the parent terminates the child with `SIGTERM` and reaps it with `wait()`.
* **`04_graceful_exit.c`**: Intercepts `Ctrl+C` (`SIGINT`) to prevent abrupt termination, displaying an interactive confirmation prompt (`Do you really want to exit? (y/n)`) to handle clean resource deallocation.
* **`05_periodic_timer.c`**: Implements a recurrent timer using `SIGALRM` handlers and re-armed `alarm()` calls to track elapsed time, terminating cleanly once at least 10 seconds have passed.
* **`06_critical_section_mask.c`**: Simulates a protected critical operation by blocking `SIGINT` signals using POSIX signal sets (`sigemptyset`, `sigaddset`) and `sigprocmask()` for 5 seconds before safely restoring normal signal delivery. A Ctrl+C pressed during those 5 seconds stays pending and is delivered as soon as `SIGINT` is unblocked.
