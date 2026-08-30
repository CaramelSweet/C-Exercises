#include <stdio.h>
#define TABSIZE         4
#define MAXLINELENGTH   1000

int getTheLine(char line[], int lineLength);
void detab(char line[], int lineLength);

int main(void) {
    int lineLength;
    char line[MAXLINELENGTH];

    while ((lineLength = getTheLine(line, MAXLINELENGTH)) != -1) {
        detab(line, lineLength);
        //printf("%s\n", line);
    }

}

int getTheLine(char line[], int lineLength) {
    int c = 0;
    int i = 0;

    while (i < lineLength - 1 && (c = getchar()) != EOF && c != '\n') {
        line[i] = c;
        ++i;
    }

    if (lineLength > 0) {
        line[i] = '\0';     
    }

    if (c == EOF && i == 0) {
        return -1;
    }

    return i;
}

void detab(char line[], int lineLength) {
    int i = 0;

    while (line[i] != '\0') {

        i++;
    }

}
// get line function

//process tabs function,

// get a line
// analysize line tabs and replace tabs with spaces to set column

// number of spaces = (tabsize)

// insert space until it hits a column.