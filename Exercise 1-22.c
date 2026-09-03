#include <stdio.h>
#define COLWIDTH 20

int getWord();

char word[COLWIDTH];
char endOfWord;

int main(void) {
    int colPos = 0;
    int wordLength;

    while (() {
        if (result ==)

            if (wordLength + colPos > COLWIDTH) {
                putchar('\n');
                colPos = 0;
            }
        printf("%s", word);
    }

    return 0;
}

int getWord() {
    int c;
    int i = 0;

    while ((c = getchar()) != EOF || c != '\n' || c != ' ') {
        i[word] = c;
    }
    return i;
    endOfWord = c;
}

// Rules
// New line when text reaches the end
// Keep words intact, move a word to the next line if it reaches the end
// Long strings are forced to wrap mid line. (The whole line)