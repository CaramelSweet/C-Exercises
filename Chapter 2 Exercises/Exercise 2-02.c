#include <stdio.h>

int main(void) {
	// for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
	// 	s[i] = c;
	// }

	int c;
	int i = 0;
	int lim = 20;
	char s[lim];

	while (i < lim - 1) {
		c = getchar();
		if (c == '\n') break;
		if (c == EOF) break;
		s[i++] = c;
	}

	return 0;
}
