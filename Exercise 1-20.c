#include <stdio.h>
#define TABSIZE         8
#define MAXLINELENGTH   1000

int getTheLine(char line[], int lineLength);
void detab(char line[], int lineLength);

int main(void) {
    int lineLength;
    char line[MAXLINELENGTH];

    while ((lineLength = getTheLine(line, MAXLINELENGTH)) != -1) {
        detab(line, lineLength);
        printf("%s\n", line);
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
    printf("%d\n", lineLength);
    for (int i = 0; i < lineLength; i++) {             // loop through array
        if (line[i] == '\t') {

            int numSpaces = TABSIZE - (i % TABSIZE);    // find number of spaces to insert

            for (int j = lineLength; j >= i; j--){      // copy array over numspaces
                line[j + numSpaces - 1] = line[j];
            }
            
            for (int j = 0; j < numSpaces; j++) {       // insert spaces
                line[i + j] = ' ';
            }
            
            lineLength += (numSpaces - 1);             // update info
            i += (numSpaces - 1); 
        }
    }
}