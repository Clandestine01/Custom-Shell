/***** Sam Watchorn - 22381831 - sam.watchorn@ucdconnect.ie *****/

# include "myheader.h"

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <signal.h>

pid_t command_process_pid; // stores the process id of the command thread
			   // global variables so that they are accessible to asynchronus functions
			   // verbose names chosen to minimise risk of namespace pollution

void kill_command(int signo) {
	kill(command_process_pid, SIGINT); // send SIGINT to the command process id
	printf("\n");
	fflush(stdout);
}



void change_directory(char *path)
{
	int result = chdir(path); // attempts to change directory, recording the result

	// reports on result of cd command, including success
	if (result==0) {printf("cd: Successfully changed directory\n");}
	else {perror("cd");}
}



int program_execute(char *input_line)
{
	int process_status; // reports on the status of the command once finished

	command_process_pid = fork(); // splits the main shell off from the command process
	
	if (command_process_pid == 0)
	{
		/***** COMMAND PROCESS *****/
		char **argv = malloc(sizeof(char*));      // string array to contain command line arguments
		char *temp;				  // temporary storage for every command line argument
		const char *delim = " ", *newline = "\n"; // delimiting characters for strtok()
		int i=0;				  // iterative variable for array allocation

		temp = strtok(input_line, delim); // allocating first command line argument
		while(temp != NULL)		  // loop continues until end of command line is reached
		{
			argv[i] = temp;				  // add argument to array
			i++;					  // iterate
			argv = realloc(argv,(i+1)*sizeof(char*)); // add space for subsequent arguments
			temp = strtok(NULL, delim);		  // acquire next argument
		}				  // loop ends
		argv[i-1] = strtok(argv[i-1], newline);		  // trim newline character from final argument
		argv[i] = NULL;					  // close array with a NULL string

		if ( !strcmp(argv[0], "cd") )      // check if the command is "cd"
		{
			change_directory(argv[1]); // divert to change_directory() function
			exit(0);		   // terminate command process
		}
		else
		{
			execvp(argv[0],argv);

			printf("Unknown command.\n"); // only executes if execvp() cannot execute the given command
			exit(-1);		      // report failure to shell process
		}
	}
	else
	{
		/***** SHELL PROCESS *****/
		wait(&process_status);        // wait for the command process to terminate
		return(process_status);       // report exit status of the command process (currently unused)
	}
}
