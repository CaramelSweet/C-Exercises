#include <stdio.h>
#define MAXLENGTH   1000

int get_line(char line[], int maxLine);
void removeBlanks(char string[], int length);

int main(void) {
    int lineLength;
    char line[MAXLENGTH];

    while ((lineLength = get_line(line, MAXLENGTH)) != - 1) {
        removeBlanks(line, lineLength);
        printf("%s\n", line);
    }

    return 0;
}

int get_line(char line[], int maxLine) {
    int c = 0;
    int i = 0;
    while (i < maxLine - 1 && (c = getchar()) != EOF && c != '\n') {
        line[i] = c;
        ++i;
    }

    if (maxLine > 0) {
        line[i] = '\0';     
    }

    if (c == EOF && i == 0) {
        return -1;
    }

    return i;
}

void removeBlanks(char string[], int length) {
    int i = length - 1;
    while (i >= 0 && (string[i ] == ' ' || string[i] == '\t')) {
        string[i] = '\0';
        --i;
    }
}