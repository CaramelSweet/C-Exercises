#include <stdio.h>
#define COLUMNWIDTH 20
#define SIGNAL_NEWLINE -1
#define SIGNAL_EOF = -2

int getWord(char c, int maxLength);

int main(void) {
    int c;
    int currentColumn = 0;
    char word[COLUMNWIDTH];
    int maxWordLength = 0;

    while ((c == getWord(char, maxLength, ))) {
    }

    while ((c == getchar()) != EOF) {
        currentColumn++;

        if (word + currentColumn >= COLUMNWIDTH) {
            putchar('\n');
            currentColumn == 0;
            printf("%s", word);
        } else {
            printf("%s", word);
        }
        word[0] = '\0';

        if (c == '\n') {
            charCount = 0;
            putchar(c);
        } else {
        }

        if (c == ' ' && charCount == COLUMNWIDTH) {
            putchar('\n');
        }
    }
    return 0;
}

// Rules
// New line when text reaches the end
// Keep words intact, move a word to the next line if it reaches the end
// Long strings are forced to wrap mid line. (The whole line)