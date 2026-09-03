#include <stdio.h>
#define COLWIDTH 10
#define TABSIZE 4

int getWord();
char word[COLWIDTH + 1];
int endOfWord = 0;
int nextChar = -1;

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    int colPos = 0;
    int wordLength;

    while (endOfWord != EOF) {
        wordLength = getWord();

        if (wordLength + colPos > COLWIDTH) {
            if (colPos > 0) {
                putchar('\n');
                colPos = 0;
            }
        }

        printf("%s", word);
        colPos += wordLength;

        if (endOfWord == ' ') {
            if (colPos < COLWIDTH) {
                putchar(' ');
                colPos++;
            } else {
                putchar('\n');
                colPos = 0;
            }

        } else if (endOfWord == '\n') {
            putchar('\n');
            colPos = 0;
        } else if (endOfWord == '\t') {
            if (colPos >= COLWIDTH) {
                putchar('\n');
                colPos = 0;
            }

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

    if (nextChar != -1) {
        word[i++] = nextChar;
        nextChar = -1;
    }

    while (i < COLWIDTH && (c = getchar()) != EOF && c != '\n' && c != ' ' && c != '\t') {
        word[i++] = c;
    }

    if (i < COLWIDTH) {
        endOfWord = c;
    } else {
        c = getchar();

        while (c == ' ') {
            c = getchar();
        }

        if (c == EOF || c == '\n' || c == '\t') {
            endOfWord = c;
        } else {
            nextChar = c;
            endOfWord = ' ';
        }
    }

    word[i] = '\0';
    return i;
}