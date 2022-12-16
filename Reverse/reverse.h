#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX_STRING 4095


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
