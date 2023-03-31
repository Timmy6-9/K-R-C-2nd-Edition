// Exercise: Explain why in two's complement x &= (x-1) deletes the rightmost 1 bit in x, then use this knowledge to write a faster version of bitcount.

// Two's complement means the most significant bit determines whether a signed integer is positive or negative MSB = 1 means number is negative, MSB 0 means number is positive

//  x &= (x-1) is the same as x = x & (x - 1)

// The reason the above equation deletes the rightmost 1 bit in x is that x - 1 will make the rightmost 1 bit a 0 bit no matter what e.g 1000100 - 1 = 1000011, this new number is then used as a mask on the original number e.g 1000100 & 1000011 = 1000000

// The below program is meant to be a faster version of the bitcount function in the book based on the above knowledge/explanation

/*
    int bitcount(unsigned int x){
        int b;

        for(b = 0; x != 0; x >>= 1) B equals 0, keep going as long as x doesn't equal 0, increment by shifting x right by 1 position
            if(x & 01) If x masked with 01 equals 1, increment b by 1
                b++;
        return b; Return number of 1 bits in the given x integer
    }
*/



#include <stdio.h>

int bitcount(unsigned int x);

int main(){

    unsigned int x;
    signed int result;

    printf("Please enter number: \n");
    scanf("%u", &x);

    result = bitcount(x);

    printf("Number of positive bits: %d\n", result);

    return 0;
}

int bitcount(unsigned int x){
// Can combine above stuff with bitcount from the book to delete rightmost 1 with a mask as an increment | Should be faster as long as bitwise operations are faster than iterating a loop 1 by 1

 int b;

    for(b = 0; x != 0; x &= (x-1))
        b++;

    return b;


}