#include "parsingInit.h"

int** parsInit(char* inputFile, int* numLinesReturn, int** arrayOfElementsPerLineReturn){
    FILE * inputFilePtr;

    inputFilePtr = fopen(inputFile,"r");
    if( inputFilePtr == 0){
        printf("Error when opening inputFile\n");
        return NULL;
    }

    int numOfLines = 0;
    int numOfElements = 0;
    char* pch;
    ssize_t read;
    char* line;
    ssize_t len = 0; 
    int lineCounter = 0; 
    int elementCounter = 0;

    int** arrayOfPointersToLinesElements; // has pointers to int* arrays that contains line's elements
    int* arrayOfElementsPerLine;

    while ((read = getline(&line, &len, inputFilePtr)) != -1) 
    {
        numOfLines++;
    }
    //we close and reopen so that we can start from beggining.
    fclose(inputFilePtr);
    inputFilePtr = fopen(inputFile,"r");
    if( inputFilePtr == 0){
        printf("Error when opening inputfile\n");
        return NULL;
    }

    arrayOfElementsPerLine = (int*)malloc(numOfLines*sizeof(int));
    if(arrayOfElementsPerLine == NULL){
        printf("Error when Malloc\n");
        return NULL;
    }

    arrayOfPointersToLinesElements = (int**)malloc(numOfLines*sizeof(int*));
    if(arrayOfPointersToLinesElements == NULL){
        printf("Error when Malloc\n");
        return NULL;
    }

    while ((read = getline(&line, &len, inputFilePtr)) != -1) 
    {
        arrayOfElementsPerLine[lineCounter] = 0;
        // printf("Retrieved line of length %zu:\n", read);
        pch = strtok (line," ");
        while (pch != NULL)
        {
            if(*pch != '\r')
            {
                arrayOfElementsPerLine[lineCounter]++; // +1 because of ID...
            } 
            pch = strtok (NULL, " ");
            //printf(" element = %d\n",numOfElements);
        }
        arrayOfElementsPerLine[lineCounter] = arrayOfElementsPerLine[lineCounter];
        arrayOfPointersToLinesElements[lineCounter] = (int*)malloc(arrayOfElementsPerLine[lineCounter]*sizeof(int));
        if(arrayOfPointersToLinesElements[lineCounter] == NULL){
            printf("Error when Malloc\n");
            return NULL;
        }
        //printf("%d num elements\n",numOfElements);
        lineCounter++;
    }


    fclose(inputFilePtr);
    inputFilePtr = fopen(inputFile,"r");
    if( inputFilePtr == 0){
        return NULL;
    }

    lineCounter = 0;
    while ((read = getline(&line, &len, inputFilePtr)) != -1) 
    {
        // printf("Retrieved line of length %zu:\n", read);
        pch = strtok (line," ");
        elementCounter = 0;
        while (pch != NULL)
        {
            if(*pch != '\r')
            {
                arrayOfPointersToLinesElements[lineCounter][elementCounter] = atoi(pch);
            } 
            pch = strtok (NULL, " ");
            //printf(" element = %d\n",numOfElements);
            elementCounter++;
        }
        lineCounter++;
        //printf("%d num elements\n",numOfElements);
    }
    *numLinesReturn = numOfLines;
    *arrayOfElementsPerLineReturn = arrayOfElementsPerLine;
    return arrayOfPointersToLinesElements;
}