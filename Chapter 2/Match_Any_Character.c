#include <stdio.h>
#include <string.h>

#define MAX 1000 // Max string size
#define BLANK ' ' // Blank Constant 

// Function that needs to match any character from string2 to the first occurrence of the character in string1 | Try to return the character directly from the string
char any(char string1[], char string2[]);

int main(){
    char string1[MAX];
    char string2[MAX];
    char firstMatch;

    printf("Please enter string 1: \n");
    fgets(string1, 1000, stdin);

    printf("Please enter string 2: \n");
    fgets(string2, 1000, stdin);

    firstMatch = any(string1, string2);

    // If the function returns a BLANK char, print a message explaining no match found
    if(firstMatch != BLANK)
        printf("First Common Character Found: %c\n", firstMatch);
    else
        printf("Sorry, no matching characters found ): \n");
}

char any(char string1[], char string2[]){
    
    int i, n, breakfor;

    char matched = BLANK;

    breakfor = 0;

    // string1[n] >= 'A' && string1[n] <= 'z' can be used if only alphabetical characters are to be searched for
    // First for loop to iterate through string2
    for(i = 0; i < strlen(string2); ++i)
        // Second for loop is to iterate through string1 to search for matches
        if(breakfor == 1)
            break;
        else{
            for(n = 0; n < strlen(string1); ++n)
                // Set the minimum value to 33 as this is the first non whitespace or control character (33 is an exclamation mark)
                if((string1[n] == string2[i]) && string1[n] >= 33 && string1[n] <= 126){
                    matched = string1[n];
                    breakfor = 1;
                    break;
                }
        }

    return matched;
}
