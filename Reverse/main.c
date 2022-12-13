#include "reverse.h"

int main (int args, char *argv[]) {
    LINES *pStart = NULL;
    
    // Check if too many arguments:
    if (args > 3) {
        fprintf(stderr,"usage: reverse <input> <output>\n");
        exit(1);
    }

    // If there are 2 input arguments given, then read from file and ride to another:
    else if (args == 3) {
        // Check that the input and output files are not the same:
        if ((strcmp(argv[1],argv[2]) == 0)) {
            fprintf(stderr, "Input and output file must differ\n");
            exit(1);
        }
        pStart = readFile(argv[1], pStart);
        writeToFile(argv[2], pStart);
        freeMemory(pStart);
    }

    // If only one file is given as input, then read that and print the content in reverse order:
    else if (args == 2) {
        pStart = readFile(argv[1], pStart);
        ownPrint(pStart);
        freeMemory(pStart);
    }

    // If no input given, then ask for the user to give lines that are then printed in reverse order:
    else if (args == 1) {
        pStart = askUser(pStart);
        ownPrint(pStart);
        freeMemory(pStart);
    }

    return 0;
}