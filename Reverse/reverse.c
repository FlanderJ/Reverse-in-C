#include "reverse.h"

// This function reads the lines of the given input file:
LINES *readFile(char *fileName, LINES *pStart) {
    FILE *file;
    size_t n=0;
    char *buf;
    if ((file = fopen(fileName, "r")) == NULL) {
        fprintf(stderr,"error: cannot open file '%s.'\n", fileName);
        exit(1);
    }
    // For each line in the file call function that adds the line into linked list structure.
    while ((getline(&buf,&n,file)) != EOF) {
        pStart = createList(pStart, buf);
    }
    fclose(file);
    free(buf);

    // Add line change character to the end of the first line, because it is not there in the first place:
    //memset(&pStart->line+(strlen(pStart->line)),'\n',sizeof(char));
    return pStart;
}

// This function adds lines given to it as input to linked list:
LINES *createList(LINES *pStart, char *lineToBeAdded) {
    LINES *pNew;

    if ((pNew = malloc(sizeof(LINES))) == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    strcpy(pNew->line,lineToBeAdded);

    // Make the new pointer to be the first one:
    if (pStart == NULL) {
        pNew->pNext = NULL;
        pStart = pNew;
    }

    // Make the pointer of the new memoryplace to point to "first" memoryplace:
    else {
        pNew->pNext = pStart;
    }
    
    // Allways return the new pointer:
    return pNew;
}

// This function writes all lines added into the linked list to a new file:
void writeToFile(char *fileName, LINES *pStart) {
    FILE *file;
    LINES *ptr;

    if ((file = fopen(fileName, "w")) == NULL) {
        fprintf(stderr,"error: cannot open file '%s.'\n", fileName);
        exit(1);
    }

    // Traverse through the list and write the lines into given output file:
    ptr = pStart;
    while(ptr != NULL) {
        fprintf(file,"%s",ptr->line);
        ptr = ptr->pNext;
    }
    fclose(file);
}

// This function prints each line added to the linked list to standard output:
void ownPrint(LINES *pStart) {
    LINES *ptr;

    // Traverse through the linked list and print every line:
    ptr = pStart;
    while (ptr != NULL) {
        fprintf(stdout,"%s",ptr->line);
        ptr = ptr->pNext;
    }
    return;
}

// This function asks user to give lines that will be printed in reverse order printed
LINES *askUser(LINES *pStart) {
    char *buf;
    size_t n=0;
    printf("Without input arguments this program will print all lines in reverse order, that user gives in stdin.\n");
    printf("Input the lines you want print in reverse order:\n");
    
    while (getline(&buf,&n,stdin) != EOF) {
        pStart = createList(pStart,buf);
    }
    free(buf);
    return pStart;
}

// This function frees all memory allocated with malloc:
void freeMemory(LINES *pStart) {
    LINES *ptr;

    ptr = pStart;
    while(ptr != NULL) {
        pStart = ptr->pNext;
        free(ptr);
        ptr = pStart;
    }
    return;
}
