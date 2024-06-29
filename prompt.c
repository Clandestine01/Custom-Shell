/***** Sam Watchorn - 22381831 - sam.watchorn@ucdconnect.ie *****/

# include "myheader.h"

# include <stdio.h>
# include <time.h>

void prompt(void)
{
	time_t true_time;          // pseudo-integer to store the time since the "epoch" in seconds
	struct tm *time_info;      // structure to store actual useful information derived from true_time
	char date_time_string[20]; // string to store the actual prompt to be printed

	time(&true_time);                  // getting time since "epoch"
	time_info = localtime(&true_time); // deriving useful information

	// arrange useful information into desired formatting
	strftime(
		date_time_string,
		20,
		"[%d/%m %H:%M]# ",
		time_info
	);

	printf("%s",date_time_string); // print prompt
}
