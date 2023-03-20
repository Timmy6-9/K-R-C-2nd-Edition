#include <stdio.h>

int main(){
    // Variables must be declared at the top of a function/block scope
    float fahr, celsius;
    int lower, upper, step;

    lower = -150; // first value to convert
    upper = 150; // last value to convert
    step = 20; // how much the value increases each iteration

    celsius = lower;

    printf("\nTemperature Conversion\n\n");

    printf("Celsius | Farenheit \n");

    printf("-------------------\n");

    while (celsius <= upper){
        //celsius = (5.0 / 9.0) * (fahr - 32.0);
        fahr = ((9.0 / 5.0) * celsius) + 32.0;
        // Tell printf to print 2 signed integers (%d) with a tab between them, first the given fahr integer then the converted celsius integer.
        printf("%6.0f  | %6.0f\n", celsius, fahr);
        // Finally, increase the step before next iteration
        celsius = celsius + step;
    }

    printf("\n");
}