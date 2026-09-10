#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
	// print range using the library
	printf("--------Printed using library macros--------\n");
	printf("The range of signed char is:	%d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("The range of unsigned char is:	%d to %u\n", 0, UCHAR_MAX);

	printf("The range of signed short is:	%d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("The range of unsigned short is:	%d to %u\n", 0, USHRT_MAX);

	printf("The range of signed int is:		%d to %d\n", INT_MIN, INT_MAX);
	printf("The range of unsigned int is:	%d to %u\n", 0, UINT_MAX);

	printf("The range of signed long is:	%d to %ld\n", LONG_MIN, LONG_MAX);
	printf("The range of unsigned long is:	%d to %lu\n", 0, ULONG_MAX);

	printf("The range of float is:	%e to %e\n", FLT_MIN, FLT_MAX);
	printf("The range of double is:	%e to %e\n", DBL_MIN, DBL_MAX);

	// print range using arithmetic
	unsigned char uCharMax = 0;
	unsigned short uShortMax = 0;
	unsigned int uIntMax = 0;
	unsigned long uLongMax = 0;

	uCharMax -= 1;
	uShortMax -= 1;
	uIntMax -= 1;
	uLongMax -= 1;

	signed char sCharMax = uCharMax / 2;
	signed char sCharMin = -sCharMax - 1;
	signed short sShortMax = uShortMax / 2;
	signed short sShortMin = -sShortMax - 1;
	signed int sIntMax = uIntMax / 2;
	signed int sIntMin = -sIntMax - 1;
	signed long sLongMax = uLongMax / 2;
	signed long sLongMin = -sLongMax - 1;

	printf("\n--------Printed using arithmetic--------\n");
	printf("The range of signed char is:	%d to %d\n", sCharMin, sCharMax);
	printf("The range of unsigned char is:	%d to %u\n", 0, uCharMax);

	printf("The range of signed short is:	%d to %d\n", sShortMin, sShortMax);
	printf("The range of unsigned short is:	%d to %u\n", 0, uShortMax);

	printf("The range of signed int is:		%d to %d\n", sIntMin, sIntMax);
	printf("The range of unsigned int is:	%d to %u\n", 0, uIntMax);

	printf("The range of signed long is:	%d to %ld\n", sLongMin, sLongMax);
	printf("The range of unsigned long is:	%d to %lu\n", 0, uLongMax);

	return 0;
}