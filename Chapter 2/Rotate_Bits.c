#include <stdio.h>

// Rotate integer x to the right by n positions
unsigned int rightrotate(unsigned int x, int n);

int main(){
    
    unsigned int x, result;
    int n;

    // Take input
    printf("Please input a number to partially rotate: \n");
    scanf("%u", &x);

    printf("Please input a number of bits to rotate to the right: \n");
    scanf("%d", &n);

    // Get modified value
    result = rightrotate(x, n);

    // Print and return
    printf("New Number: %u\n", result);

    return 0;

}

unsigned int rightrotate(unsigned int x, int n){

    unsigned int mask, bitstorotate, xlen, nbits;
    int i, bitstozero;
    bitstozero = 0;
    nbits = 1;

    // Get a number of n bits, the same way we've been getting a mask
    for(i = 0; i < n; ++i)
        nbits = nbits * 2;
    
    // Work out difference between length of x and n | Probably a nicer way to do this, oh well
    xlen = nbits;

    for(i = 0; i <= 32; ++i)
        if(xlen < x){
            ++bitstozero;
            xlen = xlen * 2;
        }
        else if(xlen > x)
            break;

    if(nbits > 0)
        nbits-=1;

    // Mask is number of bits to take off the left side + number of zeroes to make the bit length equal the number of bits in x
    mask = nbits << bitstozero;
    // Get bits to rotate by applying the mask to x with bitwise &
    bitstorotate = x & mask;
    // We're adding it to the right/least significant side so bitshift right to take out the zeroes and we're left with n in the correct position
    bitstorotate = bitstorotate >> bitstozero;
    // Invert the mask with the unary operator/one's complement
    mask = ~mask;
    // Apply the mask to x, this leaves us with x without the bits we've just preserved from the left side
    x = x & mask;
    // Bitshift left to add n number of zeroes
    x = x << n;
    // Use bitwise | (inclusive OR) to apply bitstorotate to the right side of x, where we've just added the zeroes 
    x = x | bitstorotate;
    // Return rotated x
    return x;
}