cmake_minimum_required(VERSION 3.10)
project(SignalHandlingExercises C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")

set(SIGNAL_EXERCISES
    01_sigusr1_child.c
    02_alarm_audio_alert.c
    03_ping_pong_signals.c
    04_graceful_exit.c
    05_periodic_timer.c
    06_critical_section_mask.c
)

foreach(src ${SIGNAL_EXERCISES})
    get_filename_component(exec_name ${src} NAME_WE)
    add_executable(${exec_name} ${src})
endforeach()