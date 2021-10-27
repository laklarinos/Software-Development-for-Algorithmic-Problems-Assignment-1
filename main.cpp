#include "includes.h"
#include "parsingInit.h"
#include "others.h"
using namespace std;
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
    int arrayOfElementsPerLine;

    int checkArgs = checkCommandLineArguments(argc, argv);        
    if(checkArgs){
        exit(1);
    }

    //define arguments
    inputFile = argv[2];
    queryFile = argv[4];
    outputFile = argv[10];
    k = atoi(argv[6]);
    L = atoi(argv[8]);
    numberOfNN = atoi(argv[12]);
    rad = atoi(argv[14]);

    fstream inputFilePtr;
    fstream queryFilePtr;
    fstream outputFilePtr;

    /// all good 
    // open files
    int** arrayOfPointersToLinesElements;; 

    arrayOfPointersToLinesElements = parsInit(inputFile, &numOfLines, &arrayOfElementsPerLine); // we call parsInit to read inputFIle 
                                                        // and initialize the 2d array 
                                                        // if NULL, error
    if(arrayOfPointersToLinesElements == NULL){
        exit(1);
    }

    for(int i = 0; i < numOfLines; i++){
        for(int j = 0; j < arrayOfElementsPerLine; j++){
            cout << arrayOfPointersToLinesElements[i][j] << endl;
        }
        printf("\n\n");
    }

    exit(1);
}