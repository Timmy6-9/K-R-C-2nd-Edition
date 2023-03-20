#include <stdio.h>

// Integer constants

#define MAXLEN 10000 // Maximum full string length
#define SPLITLEN 100 // Maximum split length

// Whitespace constants
#define NEWLINE '\n'
#define TAB '\t'
#define BLANK ' '

int getinput(char string[], int length);

void foldprint(char string[], int length);

int main(){

int length = 0;

char fullstring[MAXLEN];

    // leave foldprint to do the printing
    while((length = getinput(fullstring, MAXLEN)) > 0){
        foldprint(fullstring, length);
        length = 0;
    }

    return 0;
}

// Copy pasted from previous exercise
int getinput(char string[], int max){

    int i, n, c, spacestofill;

    for(i = 0; (c = getchar()) != EOF && c != '\n' && i < max; ++i)
        string[i] = c;

    if(c = '\n'){
        string[i] = c;
        ++i;
    }

    string[i] = '\0';

    return i;
}

// Turn the long/full string into multiple lines and print them
void foldprint(char fullstring[], int length){

    printf("\n");

    // If length is higher that SPLITLEN, input needs to be split
    if(length > SPLITLEN){

        int i, n, x, splitno;

        i = n = x = splitno = 0;

        // Initialize as the first split amount, 100 columns
        int currsplit = SPLITLEN;

        // Current string to collect and print
        char currstring[SPLITLEN];

        splitno = length / SPLITLEN;

        // The last bit of whitespace BEFORE the SPLITLEN column is where the split needs to be made
        for(x = 0; x <= splitno; ++x){
            for(n = 0; n < SPLITLEN; ++n){
                currstring[n] = fullstring[i];
                ++i;
            }
            // Second for loop here needs to go back to the first space/tab before the split
            for(n = SPLITLEN; n > 0; --n)
                if(currstring[n] == BLANK || currstring[n] == TAB || currstring[n] == NEWLINE)
                    break;
                else
                    --i;

            // Do "Something intelligent" if there are no whitespace characters before the split column
            if(n == 0){
                i = currsplit;
                // Look for punctuation or capital letters
                for(n = SPLITLEN; n > 0; --n)
                    if((currstring[n] >= 33 && currstring[n] <= 47) || (currstring[n] >= 65 && currstring[n] <= 90))
                        break;
                    else
                        --i;
                // If n is still 0, simply set currstring to end at SPLITLEN
                if(n == 0){
                    i = currsplit - SPLITLEN;
                    for(n = 0; n < SPLITLEN; ++n){
                        currstring[n] = fullstring[i];
                        ++i;
                    }
                }
                else{
                    // if a place to split is found, replace the end of current string with blanks as usual
                    for(n; n < SPLITLEN; ++n)
                        currstring[n] = BLANK;
                    for(n = 0; n < SPLITLEN; ++n)
                        if(currstring[n] == BLANK || currstring[n] == TAB)
                            currstring[n] = '\b';
                        else
                            break;
                }
            }
            // Split using whitespace if there's any to use
            else{
                // Make sure the end of the line is blank as the earlier for loop simply breaks without changing anything (Didn't want to nest another for loop)
                for(n; n < SPLITLEN; ++n)
                    currstring[n] = BLANK;
                // Replace whitespace at start of currstring with backspaces
                for(n = 0; n < SPLITLEN; ++n)
                    if(currstring[n] == BLANK || currstring[n] == TAB)
                        currstring[n] = '\b';
                    else
                        break;
            }
            printf("%s\n", currstring);
        }
    }
    else
        printf("%s", fullstring);
}