#include <stdio.h>

int main(){
    unsigned int n = 1000000;
    
    // All but the right-most 7 bits are changed to 0, making the number 64 if there are enough bits to perform the operation
    n = n & 0177;

    printf("%d\n", n);
}