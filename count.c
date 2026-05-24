#include <stdio.h>

int main (void) {
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            while ((ch = getchar()) == ' ') {

            }
            putchar('\n');
            if (ch == EOF) {
                break;
            }
        }
        
        putchar(ch);
    }

    return 0;
}