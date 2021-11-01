#include "parsingInit.h"
using namespace std;

int parsInit(char* inputFile, int* numLinesReturn, int* arrayOfElementsPerLineReturn, vector<point>& vec, int& numOfDimensions){
    fstream inputFilePtr;

    inputFilePtr.open(inputFile);
    if(!inputFilePtr){
        cout << "Error,  file does not exist\n";
        return 1;
    }

    int numOfLines = 0;
    int numOfElements = 0;
    char* pch;
    ssize_t read;
    string line;
    ssize_t len = 0; 
    int lineCounter = 0; 
    int elementCounter = 0;

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
        return 1;
    }

    elementsPerLine = 0;
    istringstream is(line);
    string token;

    while(getline(is, token, ' ')){
        // printf("Retrieved line of length %zu:\n", read);
        if(token != "\r")
        {
            elementsPerLine++; // +1 because of ID...
        }
    }

    numOfDimensions = elementsPerLine-1;
    inputFilePtr.close();
    inputFilePtr.open(inputFile);

    if(!inputFilePtr){
        cout << "Problem when opening the file\n";
        return 1;
    }

    lineCounter = 0;
    while (getline(inputFilePtr,line)) 
    {
        istringstream is(line);
        elementCounter = 0;
        vector<int> vct;
        auto itPos = vec.begin() + lineCounter;
        while (getline(is, token, ' '))
        {
            if(token != "\r")
            {
                auto itPos1 = vct.begin()+elementCounter;
                vct.insert(itPos1, stoi(token));
                elementCounter++;
            }
        }
        point pt(vct);
        vec.insert(itPos, pt);
        lineCounter++;
    }
    
    *numLinesReturn = numOfLines;
    *arrayOfElementsPerLineReturn = elementsPerLine;
    return 0;
}