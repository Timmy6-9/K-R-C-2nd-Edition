#include <stdio.h>

// Max file length in characters
#define MAX 10000

// These are all treated the same in terms of needing an open/close and needing counters for nesting
#define OPENPAREN '(' // To check for a closed parentheses
#define CLOSEPAREN ')' // Need to make sure these appear at some point after an open parentheses, will also need a parentheses count for nested parentheses e.g. (1 + (2 * 2))
#define OPENBRACE '{'
#define CLOSEBRACE '}'
#define OPENBRACKET '['
#define CLOSEBRACKET ']'

// Checks brackets, braces and parentheses are closed
void checkclosed(char cfile[], int length);

int main(){

    int i = 0;

    char cfile[MAX];

    FILE *cprog = fopen("./testprogram.c", "r");

    if(cprog != NULL){
        printf("File Loaded\n");

        while((cfile[i] = fgetc(cprog)) != EOF)
            ++i;

        checkclosed(cfile, i);

        fclose(cprog);

        printf("Done\n");

        return 0;

    }
    else{
        printf("Error Loading File");
        fclose(cprog);
    }

}

// Remember counters for each type of bracket/brace
void checkclosed(char cfile[], int length){

    int bracketcount, bracecount, parencount, closebracketcount, closebracecount, closeparencount, i;
    bracketcount = bracecount = parencount = closebracketcount = closebracecount = closeparencount = 0;
    
    for(i = 0; i < length; ++i){
        switch(cfile[i]){
            case OPENBRACE:
                ++bracecount;
                break;
            case OPENBRACKET:
                ++bracketcount;
                break;
            case OPENPAREN:
                ++parencount;
                break;
            case CLOSEBRACE:
                ++closebracecount;
                break;
            case CLOSEBRACKET:
                ++closebracketcount;
                break;
            case CLOSEPAREN:
                ++closeparencount;
                break;
        }
    }
    if((bracecount > 0 || closebracecount > 0) && bracecount != closebracecount)
        if(bracecount - closebracecount < 1)
            printf("Missing Open Braces: %d\n", closebracecount - bracecount);
        else
            printf("Missing Closing Braces: %d\n", bracecount - closebracecount);

    if((bracketcount > 0 || closebracketcount > 0) && bracketcount != closebracketcount)
        if(bracketcount - closebracketcount < 1)
            printf("Missing Open Brackets: %d\n", closebracketcount - bracketcount);
        else
            printf("Missing Closing Brackets: %d\n", bracketcount - closebracketcount);

    if((parencount > 0 || closeparencount > 0) && parencount != closeparencount)
        if(parencount - closeparencount < 1)
            printf("Missing Open Parentheses: %d\n", closeparencount - parencount);
        else
            printf("Missing Closing Parentheses: %d\n", parencount - closeparencount);

    if(bracecount == closebracecount && bracketcount == closebracketcount && parencount == closeparencount)
        printf("No missing braces, brackets or parentheses found!\n");
}