// Using more of the built-in libraries this time
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Max string length
#define MAX 10

// Optional characters that can come before hexadecimal numbers
#define ZERO '0'
#define LOWERX 'x'
#define UPPERX 'X'

// Exercise is to make this function convert a string of hexadecimal digits to the equivalent integer value
int htoi(char hexstring[], int length);

int main(){
    char string[MAX];
    int length;

    // Take a string as input and get the length
    printf("Please enter any valid hexadecimal number up to 8 digits (excluding optional 0x/0X header): \n");
    scanf("%10s", string);
    length = strlen(string);

    // Convert string to hexadecimal
    htoi(string, length);

    return 0;
}

// ctype.h has a very useful function called isxdigit
// I'm not sure if C now has a built-in hexadecimal number converter but I believe the spirit of this exercise is to do the conversion myself
// Hexadecimal = Base16, 0 - 9 are just 0 - 9, A - F is 10 - 15 | Position indicates power, if a hex number is 3 digits long, the first digit will be equal to (16 x 16) x firstdigit, the second digit equal to 16 x seconddigit and the third will just be thirddigit
int htoi(char string[], int length){

    int i;
    double currnumber;
    double total = 0;
    int nothex = 0;
    int has0x = 0;
    int digit = 0;


    for(i = 0; i < length; ++i)
        // if the first 2 digits are 0x or 0X, skip them
        if(i == 0 && string[i] == ZERO && (string[i + 1] == LOWERX || string[i + 1] == UPPERX)){
            has0x = 1;
        }
        else if(i == 1 && has0x == 1)
            ;
        else if(isxdigit(string[i]) == 0)
            nothex = 1;

    if(nothex == 1)
        printf("Not a valid hexadecimal value, please try again\n");
    else{
        if(has0x == 1){
            i = 2;
            digit = length - 3;
        }
        else{
            i = 0;
            digit = length - 1;
        }
        printf("%d %d\n", length, digit);
        for(i; i < length; ++i){
            // Assign Numerical Value for A - F values | Probably could have made this more readable
            switch(string[i]){
                case 'a':
                    currnumber = 10;
                    break;
                case 'A':
                    currnumber = 10;
                    break;
                case 'b':
                    currnumber = 11;
                    break;
                case 'B':
                    currnumber = 11;
                    break;
                case 'c':
                    currnumber = 12;
                    break;
                case 'C':
                    currnumber = 12;
                    break;
                case 'd':
                    currnumber = 13;
                    break;
                case 'D':
                    currnumber = 13;
                    break;
                case 'e':
                    currnumber = 14;
                    break;
                case 'E':
                    currnumber = 14;
                    break;
                case 'f':
                    currnumber = 15;
                    break;
                case 'F':
                    currnumber = 15;
                    break;
                default:
                    // Get real numerical value rather than ASCII character value
                    currnumber = string[i] - ZERO;
            }
            if(digit > 0){
                currnumber = currnumber * pow(16, digit);
                total+=currnumber;
            }
            else
                total+=currnumber;
            
            --digit;
        }
    }
    printf("Number as decimal: %.0f\n", total);
}

