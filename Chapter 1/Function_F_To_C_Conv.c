#include <stdio.h>

float conversion(int fahr);

int main(){

    int input;

    printf("Please input farenheit in a whole number: \n");

    scanf("%d", &input);

    printf("Celsius conversion: %6.1f \n", conversion(input));
}

float conversion(int fahr){
    return (5.0 / 9.0) * (fahr - 32);
}