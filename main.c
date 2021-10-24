#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include "parsingInit.h"
#include "others.h"

int main(int argc,char *argv[])
{
    char* inputFile;
    char* outputFile;
    char* queryFile;
    
    int k;
    int L;
    int numberOfNN;
    int rad;
    int numOfLines;
    int* arrayOfElementsPerLine;

    int checkArgs = checkCommandLineArguments(argc, argv);        
    if(checkArgs){
        exit(1);
    }

    inputFile = argv[2];
    queryFile = argv[4];
    outputFile = argv[10];
    k = atoi(argv[6]);
    L = atoi(argv[8]);
    numberOfNN = atoi(argv[12]);
    rad = atoi(argv[14]);

    FILE* inputFilePtr;
    FILE* queryFilePtr;
    FILE* outputFilePtr;

    /// all good 
    // open files
    int** arrayOfPointersToLinesElements;; 

    arrayOfPointersToLinesElements = parsInit(inputFile, &numOfLines, &arrayOfElementsPerLine); // we call parsInit to read inputFIle 
                                                        // and initialize the 2d array 
                                                        // if NULL, error
    if(arrayOfPointersToLinesElements == NULL){
        exit(1);
    }

    // for(int i = 0; i < numOfLines; i++){
    //     for(int j = 0; j < arrayOfElementsPerLine[i]; j++){
    //         printf("%d ", arrayOfPointersToLinesElements[i][j]);
    //     }
    //     printf("\n\n");
    // }

    queryFilePtr = fopen(queryFile,"r");
    if( queryFilePtr == 0){
        perror("Problem when opening : ");
    }

    outputFilePtr = fopen(outputFile,"r");
    if( outputFilePtr == 0){
        perror("Problem when opening : ");
    }
    //now we have the number of lines and the number of elements per line...

    //fclose(inputFilePtr);
    fclose(queryFilePtr);
    fclose(outputFilePtr);
    exit(1);
}