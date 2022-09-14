/* what are all of the data type and syscall argument type lengths on this machine?? */
/* Shawn Ostermann - updated 9/14/2022 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/sem.h>

static char * char_signage() {
	char ch = 0xFF;

    if (ch < 0) {
        return("signed");
    } else {
        return("unsigned");
    }
}

static char * byte_order()
{
	union {
		short s;
		char c[sizeof(short)];
	}un;
	un.s = 0x0102;

	if (sizeof(short) != 2) 	// only works on 2-byte short architectures
		return("undetermined");
 
	if (un.c[0] == 0x01 && un.c[1] == 0x02)
		return("big-endian (a.k.a. network byte order)");
	if (un.c[0] == 0x02 && un.c[1] == 0x01)
		return("little-endian");
	return("internal error");
}

int
main(int argc, char *argv[])
{
	printf("char is        %2lu bytes\n", sizeof (char));
	printf("short is       %2lu bytes\n", sizeof (short));
	printf("int is         %2lu bytes\n", sizeof (int));
	printf("long is        %2lu bytes\n", sizeof (long));
	printf("long long is   %2lu bytes\n", sizeof (long long));
	printf("pointer is     %2lu bytes\n", sizeof (void *));
	printf("float is       %2lu bytes\n", sizeof (float));
	printf("double is      %2lu bytes\n", sizeof (double));
	printf("long double is %2lu bytes\n", sizeof (long double));
	printf("enum is        %2lu bytes\n", sizeof (enum e {Y=1, N=2} ));

	printf("----\n");
	printf("size_t is      %2lu bytes\n", sizeof (size_t));
	printf("clock_t is     %2lu bytes\n", sizeof (clock_t));
	printf("time_t is      %2lu bytes\n", sizeof (time_t));
	printf("sem key_t is   %2lu bytes\n", sizeof (key_t));
	printf("pid_t is       %2lu bytes\n", sizeof (pid_t));

 	printf("----\n");
	printf("char sign:      %s\n", char_signage());
	printf("byte order:     %s\n", byte_order());

	return (0);
} 
