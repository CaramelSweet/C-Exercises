#include <stdio.h>

int main(void) {
	size_t charCount = 0;
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {  // blanks, tabs, and newlines
			++charCount;
		}
	}

	printf("%zu\n", charCount);

	return 0;
}