#include <stdio.h>

int any(char s1[], char s2[]);

int main(void) {
	char s1[] = "abcdef";
	char s2[] = "zd";

	printf("%d\n", any(s1, s2));

	return 0;
}

int any(char s1[], char s2[]) {
	int match = -1;

	for (int i = 0; s1[i] != '\0'; i++) {
		for (int j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j]) {
				match = i;
				break;
			}
		}

		if (match != -1) {
			break;
		}
	}

	return match;
}
