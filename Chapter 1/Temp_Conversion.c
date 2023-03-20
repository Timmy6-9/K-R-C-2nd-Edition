#include <stdio.h>

int main(){
    // Variables must be declared at the top of a function/block scope
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; // first value to convert
    upper = 300; // last value to convert
    step = 20; // how much the value increases each iteration

    fahr = lower;

    printf("\nTemperature Conversion\n\n");

    while (fahr <= upper){
        // I assume C follows BODMAS
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        // Tell printf to print 2 signed integers (%d) with a tab between them, first the given fahr integer then the converted celsius integer.
        printf("%3.0f %6.1f\n", fahr, celsius);
        // Finally, increase the step before next iteration
        fahr = fahr + step;
    }

    printf("\n");
}