#include <stdio.h>
#define IN  1
#define OUT 0
#define MAX_LEN 25

int main(void) {
    int letterCount = 0;
    int state = OUT;
    int wordLengths[MAX_LEN] = {0};

    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            state = OUT;
            if (letterCount > 0) {
                if (letterCount < MAX_LEN) {
                    ++wordLengths[letterCount - 1];
                } else {
                    ++wordLengths[MAX_LEN - 1];
                }
                letterCount = 0;
            }
        } else {
            state = IN;
            ++letterCount;
        }
    }

    // find graph height
    int height = wordLengths[0];
    for (int i = 0; i < MAX_LEN; ++i) {
        if (height < wordLengths[i]) {
            height = wordLengths[i];
        }
    }

    for (int h = height; h > 0; --h) {
        printf("%2d\xE2\x94\x82", h);
        for (int i = 0; i < MAX_LEN; ++i) {
            if (wordLengths[i] >= h) {
                printf("\xE2\x96\x88");
            } else {
                putchar('.');
            }
        }
        printf("\xE2\x94\x82");
        putchar('\n');
    }

    printf("  \xE2\x94\x94");
    for (int i = 0; i < MAX_LEN; ++i) {
        printf("\xE2\x94\x80"); 
    }
    printf("\xE2\x94\x98");
    printf("\n");

    printf("   ");
    for (int i = 1; i <= MAX_LEN; ++i) {
        if ( i < 10) {
            putchar('0');
        } else {
            printf("%d", i / 10);
        }
    }
    putchar('\n');
    printf("   ");
    for (int i = 1; i <= MAX_LEN; ++i) {
        printf("%d", i % 10);
    }
    putchar('\n');
    return 0;
}