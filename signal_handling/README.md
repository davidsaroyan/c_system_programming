# Signal Handling in C (Linux System Programming)

This directory contains practical exercises focused on asynchronous communication, signal handlers (`sigaction`, `signal`), timers (`alarm`), signal blocking (`sigprocmask`), and process interruption control in Linux.

## Exercises Overview

* **`01_sigusr1_child.c`**: Demonstrates basic signal communication. The parent process spawns a child, configures a custom signal handler for `SIGUSR1`, and sends the signal to the child.
* **`02_alarm_audio_alert.c`**: Sets an asynchronous timer using `alarm()` and triggers an audio alert via `system("aplay ...")` when the countdown expires.
* **`03_ping_pong_signals.c`**: Organizes a synchronized "ping-pong" dialogue between parent and child using `SIGUSR1` and `SIGUSR2` for 5 iterations before cleaning up.
* **`04_graceful_exit.c`**: Intercepts `Ctrl+C` (`SIGINT`) to prevent abrupt termination, displaying an interactive confirmation prompt (`Do you really want to exit? (y/n)`) to handle clean resource deallocation.
* **`05_periodic_timer.c`**: Implements a recurrent timer using `SIGALRM` handlers and re-armed `alarm()` calls to track elapsed time, terminating cleanly after 10 seconds.
* **`06_critical_section_mask.c`**: Simulates a protected critical operation by blocking `SIGINT` signals using POSIX signal sets (`sigemptyset`, `sigaddset`) and `sigprocmask()` for 5 seconds before safely restoring normal signal delivery.