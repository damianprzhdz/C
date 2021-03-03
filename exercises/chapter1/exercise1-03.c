#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

/* print Fahrenheit-Celsius table for fahr = 0, 20, ... , 300 */
main() {
    double fahr, celsius;

    fahr = LOWER;
    printf("Fahr\tCelsius\n---------------\n");

    while (fahr <= UPPER) {
        celsius = 5 * (fahr-32) / 9;
        printf("%.0f\t%.2f\n", fahr, celsius);
        fahr += STEP; 
    }
    return 0;
}