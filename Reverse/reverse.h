#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 255
#define MAX_FILE 255
/* Linked list structrure */
typedef struct lines {
    char line[MAX_STRING];
    struct lines *pNext;
} LINES;

LINES *readFile(char *fileName, LINES *pStart);
LINES *createList(LINES *pStart, char *lineToBeAdded);
void writeToFile(char *fileName, LINES *pStart);
void ownPrint(LINES *pStart);
LINES *askUser(LINES *pStart);
void freeMemory(LINES *pStart);
