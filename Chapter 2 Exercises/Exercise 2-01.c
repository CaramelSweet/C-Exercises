#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
	printf("The range of signed char is:	%d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("The range of unsigned char is:	%d to %u\n", 0, UCHAR_MAX);

	printf("The range of signed short is:	%d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("The range of unsigned short is:	%d to %u\n", 0, USHRT_MAX);

	printf("The range of signed int is:		%d to %d\n", INT_MIN, INT_MAX);
	printf("The range of unsigned int is:	%d to %u\n", 0, UINT_MAX);

	printf("The range of signed long is:	%d to %ld\n", LONG_MIN, LONG_MAX);
	printf("The range of unsigned long is:	%d to %lu\n", 0, ULONG_MAX);
	return 0;
}
