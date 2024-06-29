/***** Sam Watchorn - 22381831 - sam.watchorn@ucdconnect.ie *****/

# define MAXLINESIZE 256 // Maximum length of the command line.

void kill_command(int signo);
/* Function to kill the command process.
 * Takes the default signal as argument for posterity, goes unused.*/

void prompt(void);
/* Function for printing the opening prompt, including the date and time.
 * No arguments necessary.*/

void change_directory(char *path);
/* Function to change the working directory of the shell.
 * Takes in the desired path as argument.
 * Discards subsequent command line arguments.*/

int program_execute(char *input_line);
/* Function to handle forking and executing commands.
 * Takes the command line as argument.
 * Handles splitting the command line into commands and arguments.*/
