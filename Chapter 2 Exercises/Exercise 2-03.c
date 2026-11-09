#include <stdio.h>
int htoi(char s[]);

int main(void) {
	char a[] = "0x3A7";	 // hex input

	printf("%d", htoi(a));

	return 0;
}

int htoi(char s[]) {
	int i = 0, total = 0;
	int value;

	if (s[i] == '0' && (s[i + 1] == 'X' || s[i + 1] == 'x')) i = 2;	 // Skip past 0x

	while (s[i] != '\0') {
		if (s[i] >= '0' && s[i] <= '9') {
			value = s[i] - '0';
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			value = s[i] - 'A' + 10;
		} else if (s[i] >= 'a' && s[i] <= 'f') {
			value = s[i] - 'a' + 10;
		} else {  // Invalid character check
			break;
		}
		total = 16 * total + value;
		i++;
	}

	return total;
}