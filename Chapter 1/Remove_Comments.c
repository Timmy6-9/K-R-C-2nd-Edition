#include <stdio.h>

#define MAX 10000 // Max character length of c program
#define NEWLINE '\n' // Newline constant
#define BLANK ' ' // Blank constant

void removecomments(char cfile[], int filelength);

// main needs to load the file into an array, pass the array to removecomments to remove all comments, then save the array as a new file and close the I/O stream
int main(){

    int i = 0;

    char cfile[MAX];

    // Load file from local folder
    FILE *cprog = fopen("./testprogram.c", "r");

    if(cprog != NULL){
        printf("File Loaded\n");

        // Create new file to save modified program to
        FILE *newcprog = fopen("./modifiedtestprogram.c", "w");

        while((cfile[i] = fgetc(cprog)) != EOF)
            ++i;

        removecomments(cfile, i);

        fclose(cprog);

        fputs(cfile, newcprog);

        fclose(newcprog);

        printf("Done\n");

        return 0;

    }
    else{
        printf("Error Loading File");
        fclose(cprog);
    }

}

// Check array line-by-line and remove any lines that start with //, remove anything in between /* and */
void removecomments(char cfile[], int filelength){

    int i, deletesingle, deletemultiple;

    deletesingle = deletemultiple = 0;

    for(i = 0; i <= filelength; ++i){

        if(deletemultiple == 0 && cfile[i] == '/' && cfile[i + 1] == '*'){
            deletemultiple = 1;
            cfile[i] = BLANK;
        }
        if(deletesingle == 0 && cfile[i] == '/' && cfile[i + 1] == '/'){
            deletesingle = 1;
            cfile[i - 1] = BLANK;
        }
        if(deletesingle == 1 && cfile[i] == NEWLINE){
            deletesingle = 0;
        }
        else if(deletemultiple == 1 && cfile[i] == '*' && cfile[i + 1] == '/'){
            cfile[i] = BLANK;
            cfile[i + 1] = BLANK;
            deletemultiple = 0;
        }
        else if(deletesingle == 1 || deletemultiple == 1)
            cfile[i] = BLANK;

        if(i == filelength)
            cfile[i] == '\0';
    }

}