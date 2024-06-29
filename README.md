# Custom-Shell
Custom shell done as part of a college assignment. Emulates a handful of Bash functionalities, such as program execution, signal catching, etc. Use ctrl+D to terminate rather than ctrl+C.

-=-=- INDEX -=-=-
myheader.h ---------- Definitions and Function Prototypes, as well as function details.
myshell.c ----------- Main loop, user inputs, and signal interrupts.
prompt.c ------------ Function to print the prompt including date and time information.
program_execute.c --- All functions relating to processing the command line and executing commands, as well as multiple process handling.

-=-=- FEATURES -=-=-
Basic Shell ---------------------------- Implemented without complication. <stdio.h>'s getline() function used to get user inputs.

Feature 1 - Exec and Fork -------------- Implemented without complication. Command line processing is clunky, but functional.
-------------- Would improve on subsequent attempts.

Feature 2 - Date in prompt ------------- Implemented without complication.

Feature 3 - Catch SIGINT signal -------- Implemented with complications. SIGINT successfully intercepted and command process terminated,
                                -------- however new prompt only opened if a command process was running. SIGINT being sent to an open
                                -------- prompt does nothing.
                                
Feature 4 - Change Directory builtin --- Implemented with minor complication. Errors reported successfully, successes also reported.

Feature 5 - Redirect builtin ----------- Not implemented. Outside personal ability and time constraints.
                             ----------- Would attempt on subsequent attempts.
