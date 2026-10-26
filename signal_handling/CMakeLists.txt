cmake_minimum_required(VERSION 3.10)
project(SignalHandlingExercises C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wshadow -g")

# List of all signal handling exercises
set(SIGNAL_EXERCISES
    01_sigusr1_to_child.c
    02_alarm_sound_alert.c
    03_ping_pong_signals.c
    04_ctrl_c_cleanup.c
    05_alarm_elapsed_timer.c
    06_block_sigint_critical.c
)

# Automatically create an executable for each .c file
# (files not written yet are skipped, so the folder builds as you go)
foreach(src ${SIGNAL_EXERCISES})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${src})
        get_filename_component(exec_name ${src} NAME_WE)
        add_executable(${exec_name} ${src})
    endif()
endforeach()
