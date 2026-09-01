#include <stdio.h>
#define MAXLINE 1000
#define PLENGTH 80

int get_line(char line[], int maxLine);

int main(void) {
    int lineLength;
    char line[MAXLINE];

    while ((lineLength = get_line(line, MAXLINE)) > 0) {
        if (lineLength >= PLENGTH) {
            printf("%s", line);
        }
    }

    return 0;
}

int get_line(char line[], int maxLine) {
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (i < maxLine - 1) {
            line[i] = c;
        }
        ++i;
    }

    if (c == '\n') {
        if (i < maxLine - 1) {
            line[i] = c;
        }
        ++i;
    }

    if (i < maxLine) {
        line[i] = '\0';
    } else {
        line[maxLine - 1] = '\0';
    }

    return i;
}