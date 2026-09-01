#include <stdio.h>
#define MAX_LEN 128

int main(void) {
    int letterCount = 0;
    int charCount[MAX_LEN] = {0};

    int ch;
    while ((ch = getchar()) != EOF) {
        ++charCount[ch];
    }

    for (int i = 0; i < MAX_LEN; ++i) {
        if (charCount[i] > 0) {
            if (i == 10) {
                printf("NL|");
            } else {
                printf(" %c|", i);
            }
            for (int y = 0; y < charCount[i]; ++y) {
                putchar('*');
            }
            putchar('\n');
        }
    }

    return 0;
}