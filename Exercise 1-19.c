#include <stdio.h>
#define MAXLENGTH   1000

int get_line(char line[], int maxLine);
void reverseString(char string[], int lineLength);

int main (void) {
    int lineLength;
    char line[MAXLENGTH];

    while ((lineLength = get_line(line, MAXLENGTH)) != -1) {
        reverseString(line, lineLength);
        printf("%s\n", line);
    }
    
    return 0;
}

int get_line(char line[], int maxLine) {
    int c;
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

void reverseString(char string[], int stringLength) {
    char temp;

    for (int i = 0; i < stringLength / 2; ++i) {
        temp = string[i];
        string[i] = string[stringLength - i - 1];
        string[stringLength - i - 1] = temp;
    }
}