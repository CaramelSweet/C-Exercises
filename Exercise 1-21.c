#include <stdio.h>
#define TABSIZE         8
#define MAXLINELENGTH   1000

int getTheLine(char line[], int lineLength);
void detab(char line[], int lineLength);
void entab(char line[], int lineLength);

int main(void) {
    int lineLength;
    char line[MAXLINELENGTH];

    while ((lineLength = getTheLine(line, MAXLINELENGTH)) != -1) {
        entab(line, lineLength);
        printf("%s\n", line);
    }
}

int getTheLine(char line[], int lineLength) {
    if (lineLength<= 0) {
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
    for (int i = 0; i < lineLength; i++) {
        
        if (line[i] == ' ') {
            spaceCount++;
        }

        if ((i % TABSIZE == 0) && (spaceCount > 0)) {
            // replace spaces with tabs
            line[i - spaceCount] = '\t';
            // move array over left (spaceCount - 1)
            for (int j = i - spaceCount - 1; j < lineLength; j++) {
                line[j] = line[j + 1];
            }
            line[lineLength - spaceCount - 1 ] = '\0';

            lineLength += (spaceCount - 1); // update info
            spaceCount = 0;
        }
    }
}
// aa  aaaa
// 01234567
void detab(char line[], int lineLength) {
    for (int i = 0; i < lineLength; i++) {             // loop through array
        if (line[i] == '\t') {
            int numSpaces = TABSIZE - (i % TABSIZE);    // find number of spaces to insert

            if (lineLength + numSpaces - 1 >= MAXLINELENGTH) { // prevent overlow
                numSpaces = MAXLINELENGTH - lineLength;
            }

            for (int j = lineLength; j > i; j--){      // copy array over numspaces
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

// find space
// count sequential spaces
// if sequential spaces crosses hits boundary/column replaces spaces with tab.