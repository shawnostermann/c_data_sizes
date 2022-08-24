/* what are all of the data type and syscall argument type lengths on this machine?? */
/* Shawn Ostermann - updated 8/24/2022 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/sem.h>

int
main(int argc, char *argv[])
{
	(void) printf("char is        %2lu bytes\n", sizeof (char));
	(void) printf("short is       %2lu bytes\n", sizeof (short));
	(void) printf("int is         %2lu bytes\n", sizeof (int));
	(void) printf("long is        %2lu bytes\n", sizeof (long));
	(void) printf("long long is   %2lu bytes\n", sizeof (long long));
	(void) printf("pointer is     %2lu bytes\n", sizeof (void *));
	(void) printf("float is       %2lu bytes\n", sizeof (float));
	(void) printf("double is      %2lu bytes\n", sizeof (double));
	(void) printf("long double is %2lu bytes\n", sizeof (long double));
	(void) printf("enum is        %2lu bytes\n", sizeof (enum e {Y=1, N=2} ));

	(void) printf("----\n");
	(void) printf("size_t is      %2lu bytes\n", sizeof (size_t));
	(void) printf("clock_t is     %2lu bytes\n", sizeof (clock_t));
	(void) printf("time_t is      %2lu bytes\n", sizeof (time_t));
	(void) printf("sem key_t is   %2lu bytes\n", sizeof (key_t));
	(void) printf("pid_t is       %2lu bytes\n", sizeof (pid_t));
 
	return (0);
} 
