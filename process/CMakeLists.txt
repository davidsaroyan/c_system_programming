cmake_minimum_required(VERSION 3.10)
project(ProcessExercises C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wshadow -g")

# List of all process exercises
set(PROCESS_EXERCISES
    01_fork_basics.c
    02_race_first_child.c
    03_child_wait_delay.c
    04_parent_kill_child.c
    05_execv_ps.c
    06_execl_echo.c
    07_mini_shell.c
    08_math_competition.c
    09_exec_ls_detailed.c
    10_sequential_children.c
)

# Automatically create an executable for each .c file
foreach(src ${PROCESS_EXERCISES})
    get_filename_component(exec_name ${src} NAME_WE)
    add_executable(${exec_name} ${src})
endforeach()

# log2, pow and tgamma live in the math library (libm)
target_link_libraries(08_math_competition m)
