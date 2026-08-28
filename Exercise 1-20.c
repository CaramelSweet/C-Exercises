#include <stdio.h>
#define TABSIZE 4;

int main(void) {


    char stuff[50];
    int c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        stuff[i] = c;
        ++i;
    }

    stuff[i] = '\0';

    printf("The string is %s", stuff);
    
}
// get line function

//process tabs function,

// get a line
// analysize line tabs and replace tabs with spaces to set column
