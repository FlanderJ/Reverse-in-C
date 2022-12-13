// Jarmo Flander, 9.9.2022. Käyttöjärjestelmät ja systeemiohjelmointi.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 255
#define MAX_FILE 255

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