#include <stdio.h>

// Function needs to invert n bits starting at position p in x
unsigned int invert(unsigned int x, int p, int n);

int main(){

    unsigned int x, result;
    int p, n;

    printf("Please enter number to partially invert: \n");
    scanf("%u", &x);

    printf("Please enter the position from which to invert from: \n");
    scanf("%d", &p);

    printf("Please enter the number of bits to invert: \n");
    scanf("%d", &n);

    result = invert(x, p, n);

    printf("New number: %u\n", result);

    return 0;
}

unsigned int invert(unsigned int x, int p, int n){

    int i, mask;
    unsigned int bitstoinvert, bitstokeep, newno;

    for(i = 0; i <= n; i++)
        if(i == 0)
            mask = 1;
        else
            mask = mask * 2;

    if(mask > 1)
        mask-=1;

    if(p > 0){

        bitstokeep = x << (32 - p);
        bitstokeep = bitstokeep >> (32 - p);

        bitstoinvert = ((x >> p) & mask);

        bitstoinvert = ~bitstoinvert;

        bitstoinvert = bitstoinvert << (32 - n);
        bitstoinvert = bitstoinvert >> (32 - n);

        x = x >> p + n;
        x = x << n;
        x = x ^ bitstoinvert;
        x = x << p;
        x = x ^ bitstokeep;
    }
    else{
        bitstoinvert = ((x >> p) & mask);

        bitstoinvert = ~bitstoinvert;

        bitstoinvert = bitstoinvert << (32 - n);
        bitstoinvert = bitstoinvert >> (32 - n);

        x = x >> n;
        x = x << n;
        x = x ^ bitstoinvert;
    }
    
    return x;
}