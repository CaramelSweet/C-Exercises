#include <stdio.h>
#define TABSIZE         4
#define MAXLINELENGTH   1000

int getTheLine(char line[], int lineLength);
void entab(char line[], int lineLength);

int main(void) {
    int lineLength;
    char line[MAXLINELENGTH];

    while ((lineLength = getTheLine(line, MAXLINELENGTH)) != -1) {
        entab(line, lineLength);
        printf("%s\n", line);
    }

    return 0;
}

int getTheLine(char line[], int lineLength) {
    if (lineLength <= 0) {
        return -1;
    }

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

void entab(char line[], int lineLength) {

    int spaceCount = 0;
    int shifted = 0;
    for (int i = 0; i < lineLength; i++) {
        
        if (line[i] == ' ') {
            spaceCount++;
        } else {
            spaceCount = 0;
        }

        if (line[i] == '\t') {
            for (int j = i - spaceCount; j <= lineLength - spaceCount; j++) {
                line[j] = line[j + spaceCount];
            }

            shifted += TABSIZE - 1;

            i = (i - spaceCount);
        } else if (((i + shifted + 1) % TABSIZE == 0) && (spaceCount > 0)) {

            line[i - spaceCount + 1] = 't';
            
            // move array over left (spaceCount - 1)
            for (int j = i - spaceCount + 2; j <= lineLength - spaceCount + 1; j++) {
                line[j] = line[j + spaceCount - 1];
            }

            i = (i - spaceCount + 1);

            lineLength = (lineLength - spaceCount + 1); // update info

            shifted += spaceCount - 1;

            spaceCount = 0; 
        }
    }
}