#include "parsingInit.h"
using namespace std;
int** parsInit(char* inputFile, int* numLinesReturn, int* arrayOfElementsPerLineReturn){
    fstream inputFilePtr;

    inputFilePtr.open(inputFile);
    if(!inputFilePtr){
        cout << "Error,  file does not exist\n";
        return NULL;
    }

    int numOfLines = 0;
    int numOfElements = 0;
    char* pch;
    ssize_t read;
    string line;
    ssize_t len = 0; 
    int lineCounter = 0; 
    int elementCounter = 0;

    int** arrayOfPointersToLinesElements; // has pointers to int* arrays that contains line's elements
    int elementsPerLine;

    while (getline(inputFilePtr, line)) 
    {
        numOfLines++;
    }
    //we close and reopen so that we can start from beggining.
    inputFilePtr.close();
    inputFilePtr.open(inputFile);
    if(!inputFilePtr){
        cout << "Error when opening the file\n";
        return NULL;
    }

    arrayOfPointersToLinesElements = (int**)malloc(numOfLines*sizeof(int*));
    if(arrayOfPointersToLinesElements == NULL){
        cout << "Error when malloc\n";
        return NULL;
    }

    elementsPerLine = 0;
    istringstream is(line);
    string token;

    while (getline(is, token, ' '))
    // printf("Retrieved line of length %zu:\n", read);
    {
        if(token != "\r")
        {
            elementsPerLine++; // +1 because of ID...
        } 
        //printf(" element = %d\n",numOfElements);
    }

    cout << elementsPerLine << endl;

    inputFilePtr.close();
    inputFilePtr.open(inputFile);
    if(!inputFilePtr){
        return NULL;
    }

    lineCounter = 0;
    while (getline(inputFilePtr,line)) 
    {
        istringstream is(line);
        // printf("Retrieved line of length %zu:\n", read);
        elementCounter = 0;
        arrayOfPointersToLinesElements[lineCounter] = (int*) malloc(elementsPerLine*sizeof(int));
        while (getline(is, token, ' '))
        {
            if(token != "\r")
            {
                arrayOfPointersToLinesElements[lineCounter][elementCounter] = stoi(token);
            }
            elementCounter++;
        }
        lineCounter++;
        //printf("%d num elements\n",numOfElements);
    }
    *numLinesReturn = numOfLines;
    *arrayOfElementsPerLineReturn = elementsPerLine;
    return arrayOfPointersToLinesElements;
}