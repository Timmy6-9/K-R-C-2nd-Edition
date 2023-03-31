#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

    int x;
    long maxtypevalue; 

    unsigned long long maxlongvalue;
    signed long minsignedlong;

    float maxfloatvalue;
    double maxdoublevalue;

    printf("\nLibrary/Header Definitions: \n\n");

    printf("How many bits we got: %d\n\n", __WORDSIZE);

    printf("Maximum Unsigned Char Size: %d\n", UCHAR_MAX);
    printf("Minimum Signed Char Size: %d\n", SCHAR_MIN);
    printf("Maximum Signed Char Size: %d\n", SCHAR_MAX);

    printf("\n");

    printf("Maximum Unsigned Short Size: %d\n", USHRT_MAX);
    printf("Minimum Signed Short Size: %d\n", SHRT_MIN);
    printf("Maximum Signed Short Size: %d\n", SHRT_MAX);

    printf("\n");

    printf("Maximum Unsigned Integer Size: %u\n", UINT_MAX);
    printf("Minimum Signed Integer Size: %d\n", INT_MIN);
    printf("Maximum Signed Integer Size: %d\n", INT_MAX);

    printf("\n");

    printf("Maximum Unsigned Long Size: %lu\n", ULONG_MAX);
    printf("Minimum Signed Long Size: %ld\n", LONG_MIN);
    printf("Maximum Signed Long Size: %ld\n", LONG_MAX);

    printf("\n");

    printf("Maximum Float Size = %.10e\n", FLT_MAX);
    printf("Minimum Float Size = %.10e\n", FLT_MIN);

    printf("\n");

    printf("Maximum Double Size = %.10e\n", DBL_MAX);
    printf("Minimum Double Size = %.10e\n", DBL_MIN);

    // Unsure if this is in the spirit of the exercise (Using sizeof) but this is the "Computation" method I went with 
    
    // 1 bit = 1 or 0 | 2 bits = 0, 1, 2 or 3 (Max value represented by bits doubles each time you add an extra bit)

    printf("\nComputed Values: \n\n");
    
    //These all start at 2 as it represents how many values 1 bit can show (1 or 0)
    
    // Char type
    maxtypevalue = 2;

    for(x = 0; x < (sizeof(char) * 8) - 1; ++x){
        maxtypevalue = maxtypevalue * 2;
    }

    printf("Max unsigned value of char: %ld\n", maxtypevalue - 1);
    maxtypevalue = (maxtypevalue / 2);
    printf("Max signed value of char: %ld\n", maxtypevalue - 1);
    maxtypevalue = (maxtypevalue - (maxtypevalue * 2));
    printf("Min signed value of char: %ld\n", maxtypevalue);

    // Short Type
    maxtypevalue = 2;

    for(x = 0; x < (sizeof(short) * 8) - 1; ++x){
        maxtypevalue = maxtypevalue * 2;
    }

    printf("Max unsigned value of short: %ld\n", maxtypevalue - 1);
    maxtypevalue = (maxtypevalue / 2);
    printf("Max signed value of short: %ld\n", maxtypevalue - 1);
    maxtypevalue = (maxtypevalue - (maxtypevalue * 2));
    printf("Min signed value of short: %ld\n", maxtypevalue);

    // Int Type
    maxtypevalue = 2;

    for(x = 0; x < (sizeof(int) * 8) - 1; ++x){
        maxtypevalue = maxtypevalue * 2;
    }

    printf("Max unsigned value of int: %ld\n", maxtypevalue - 1);
    maxtypevalue = (maxtypevalue / 2);
    printf("Max signed value of int: %ld\n", maxtypevalue - 1);
    maxtypevalue = (maxtypevalue - (maxtypevalue * 2));
    printf("Min signed value of int: %ld\n", maxtypevalue);

    // Long Type
    maxlongvalue = 2;

    for(x = 0; x < (sizeof(long) * 8) - 1; ++x){
        maxlongvalue = maxlongvalue * 2;
    }

    printf("Max unsigned value of long: %llu\n", maxlongvalue - 1);

    maxlongvalue = 2;

    for(x = 0; x < (sizeof(long) * 8) - 2; ++x){
        maxlongvalue = maxlongvalue * 2;
    }

    printf("Max signed value of long: %llu\n", maxlongvalue - 1);

    minsignedlong = (maxlongvalue - maxlongvalue - maxlongvalue);

    printf("Min signed value of long: %ld\n", minsignedlong);

    return 0;
}