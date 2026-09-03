#include <stdio.h>
#define COLWIDTH 10
#define TABSIZE 4

int getWord();
char word[COLWIDTH + 1];
int endOfWord = 0;

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    int colPos = 0;
    int wordLength;

    while (endOfWord != EOF) {
        wordLength = getWord();

        if (wordLength + colPos > COLWIDTH) {
            putchar('\n');
            colPos = 0;
        }

        printf("%s", word);
        colPos += wordLength;

        if (endOfWord == ' ' && colPos < COLWIDTH) {
            putchar(' ');
            colPos++;
        } else if (endOfWord == '\n') {
            putchar('\n');
            colPos = 0;
        } else if (endOfWord == '\t' && colPos <= COLWIDTH) {
            int spaceLeft = COLWIDTH - colPos;
            int spacesToTab = TABSIZE - (colPos % TABSIZE);
            int numSpaces;

            if (spaceLeft > spacesToTab) {
                numSpaces = spacesToTab;
            } else {
                numSpaces = spaceLeft;
            }

            int i = 0;
            while (i < numSpaces) {
                putchar('T');
                i++;
            }

            colPos += numSpaces;
        }
    }

    return 0;
}

int getWord() {
    int c;
    int i = 0;

    while (i < COLWIDTH && (c = getchar()) != EOF && c != '\n' && c != ' ' && c != '\t') {
        word[i] = c;
        i++;
    }

    if (i >= COLWIDTH) {
        endOfWord = 0;
    } else {
        endOfWord = c;
    }

    word[i] = '\0';

    return i;
}
// Rules
// New line when text reaches the end
// Keep words intact, move a word to the next line if it reaches the end
// Long strings are forced to wrap mid line. (The whole line)