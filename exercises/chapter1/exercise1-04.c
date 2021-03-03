#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

/* print Celsius-Fahrenheit table for fahr = 0, 20, ... , 300 */

/*
main() {
    double fahr, celsius;

    celsius = LOWER;
    printf("Celsius\tFahr\n---------------\n");

    while (celsius <= UPPER) {
        fahr = (celsius + 9 / 5) + 32;
        printf("%.0f\t%.2f\n", celsius, fahr);
        celsius += STEP; 
    }
    return 0;
}
*/

int main() {
    double fahr, celsius;
    int direction = 1;

    if (direction == 0) {
    fahr = LOWER;
    printf("Fahr\tCelsius\n---------------\n");
    while (fahr <= UPPER) {
        celsius = 5 * (fahr-32) / 9;
        printf("%.0f\t%.2f\n", fahr, celsius);
        fahr += STEP; 
        }
    }else {
        celsius = LOWER;
        printf("Fahr\tCelsius\n---------------\n");
        while (celsius <= UPPER) {
            fahr = (celsius * 9 / 5) + 32;
            printf("%.0f\t%.2f\n", celsius, fahr);
            celsius += STEP; 
        }
    }
    
    return 0;
}


/*

*/