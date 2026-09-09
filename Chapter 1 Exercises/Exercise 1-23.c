#include <stdio.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '"') {
			putchar(c);
			while (1) {
				c = getchar();

				if (c == EOF) {
					break;
				}

				if (c == '\\') {
					putchar(c);
					c = getchar();
				} else if (c == '"') {
					break;
				}
				putchar(c);
			}
		}

		if (c == '\'') {
			putchar(c);
			while (1) {
				c = getchar();

				if (c == EOF) {
					break;
				}

				if (c == '\\') {
					putchar(c);
					c = getchar();
				} else if (c == '\'') {
					break;
				}
				putchar(c);
			}
		}

		if (c == '/') {
			c = getchar();
			if (c == EOF) {
				putchar('/');
				break;
			}

			if (c == '/') {	 // check if single line
				while (1) {
					c = getchar();

					if (c == '\n' || c == EOF) {
						break;
					}
				}
			} else if (c == '*') {	// check if mult-line
				while (1) {
					c = getchar();

					if (c == EOF) {
						break;
					}

					if (c == '*') {
						while ((c = getchar()) == '*') {
						}
						if (c == '/') {
							c = getchar();
							break;
						}
					}
				}
			} else {
				putchar('/');
			}
		}

		if (c != EOF) {
			putchar(c);
		}
	}
}
