#include <stdio.h>

unsigned int setbits(unsigned int x, unsigned int y, int p, int n);

int main(){

    unsigned int firstno, secondno;
    int insertposition, bitstomove, result;

    printf("Please enter a number for bits to be inserted into: \n");
    scanf("%u", &firstno);

    printf("Please enter a number for bits to be taken from: \n");
    scanf("%u", &secondno);

    printf("Please enter the position to move the bits into: \n");
    scanf("%d", &insertposition);

    printf("Please enter the number of bits to move: \n");
    scanf("%d", &bitstomove);

    result = setbits(firstno, secondno, insertposition, bitstomove);

    printf("New first number: %d\n", result);

    return 0;
}

unsigned int setbits(unsigned int x, unsigned int y, int p, int n){

    int i, mask;
    unsigned int bitstoadd, bitstokeep;
    bitstokeep = 0;
    // To get n we need a mask filled with the correct number of positive bits
    // n = 4 should be 1 + 2 + 4 + 8 = 15 for 00001111, keep doubling until you have the correct number of bits to preserve from y

    for(i = 0; i <= n; i++)
        if(i == 0)
            mask = 1;
        else
            mask = mask * 2;

    if(mask > 1)
        mask-=1;

    // Apply mask to y

    // & (AND) will keep only the bits that are positive in both numbers in both positions

    bitstoadd = y & mask;

    // If p is greater than 0, we need to keep some bits from the end of x so we can add them back
    if(p > 0){
        bitstokeep = x << (32 - p);
        bitstokeep = bitstokeep >> (32 - p);
        x = x >> p + n;
        x = x << n;
        x = x ^ bitstoadd;
        x = x << p;
        x = x ^ bitstokeep;
    }
    else{
        x = x >> n;
        x = x << n;
        x = x ^ bitstoadd;
    }

    return x;
}