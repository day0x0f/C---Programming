/* struct tm {
 * 		int		tm_sec;		-> seconds
 *		int 	tm_min;		-> minutes
 *		int 	tm_hour;	-> hours
 * 		int 	tm_mday;	-> day of th month
 *		int 	tm_mon;		-> month
 *		int 	tm_year;	-> year
 * 		int		tm_wday;	-> day of the week
 *		int 	tm_yday;	-> day in the year
 * 		int 	tm_isdst;	-> daylight saving time
 * }
 */

#include <stdio.h>
#include <time.h>

int main() {
	long int seconds_since_epoch;
	struct tm current_time, *time_ptr;
	int hour, minute, second, day, month, year;

	seconds_since_epoch = time(0); // Pass time a null pointer as argument.
	printf("time() - seconds since epoch: %ld\n", seconds_since_epoch);

	time_ptr = &current_time; 	// Set time_ptr to the address off
								// The current_time struct.								
	localtime_r(&seconds_since_epoch, time_ptr);
	
	// Three different ways to access struct elements:
	hour = current_time.tm_hour;	// Direct access
	minute = time_ptr->tm_min;		// Access via pointer
	second = *((int *) time_ptr);	// Hacky pointer access

	printf("Current time is: %02d:%02d:%02d\n", hour, minute, second);
}
