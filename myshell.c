/***** Sam Watchorn - 22381831 - sam.watchorn@ucdconnect.ie *****/

# include "myheader.h"

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

int main()
{	
	char *input_line;                     // pointer for getline() output string
	size_t max_line_size_t = MAXLINESIZE; // MAXLINESIZE but as a size_t type for use in getline()
	int end_flag = 0;		      // treated as boolean and used to govern the main loop's activity

	// allocate memory for input line
	input_line = (char *)malloc(MAXLINESIZE * sizeof(char));
	if (input_line == NULL) {
		printf("ERROR: cannot allocate memory.\n");
		return -1;
	}

	/***** MAIN LOOP *****/
	signal(SIGINT, kill_command); // catch any SIGINTs sent, instead calling kill_command(), see program_execute.c
	while (!end_flag) {
		prompt(); 	      // print the prompt line with date+time information, see prompt.c

		// get the command line from stdin, store as a continuous string in input_line
		// if stdin contains EOF (ctrl+D), raise the end_flag boolean and end this loop iteration
		if (getline(&input_line, &max_line_size_t, stdin) == -1) {
			end_flag = 1;
			continue;
		}

		program_execute(input_line); // send the command line to program_execute() for processing, see program_execute.c
	}
	printf("\n");
}
