#include <stdio.h>

int f_to_c(int f);

int main(void) {
    int celsius;

    int lower = 0;
    int upper = 300;
    int step = 20;
    int fahr = lower;
    
    while (fahr <= upper) {
        printf("%d\t%d\n", fahr, f_to_c(fahr));
        fahr = fahr + step;
    }


    return 0;
}

int f_to_c(int f) {
    int c = 5 * (f - 32) / 9;
    return c;
}

