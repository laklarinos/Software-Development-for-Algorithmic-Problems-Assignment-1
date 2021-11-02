#include "includes.h"
#include "parsingInit.h"
#include "others.h"
#include "hashtable.h"

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
    int w = 3;

    int numOfLines;
    int numOfElements;
    int numOfDimensions;

    lshConstants lshCon;

    // for query file
    int numOfLinesQ;
    int numOfElementsQ;
    int numOfDimensionsQ;

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

    lshCon.k = k;
    lshCon.w = w;
    lshCon.L = L;

    fstream inputFilePtr;
    fstream queryFilePtr;
    fstream outputFilePtr;

    vector<point> arrayOfPoints;

    int res = parsInit(inputFile, arrayOfPoints, &numOfLines, &numOfElements); 
    numOfDimensions = numOfElements - 1;
    if(res == 1){
        exit(1);
    }

    if(arrayOfPoints.empty()){
        exit(1);
    }

    // return 1;
    
    // now lets start the insertion...

    vector<hashTable*> hashTablesArray(L);
    for(int i = 0; i < L; i++){
        hashTablesArray[i] = new hashTable(numOfLines/4, &lshCon, numOfDimensions);
    }

    for(int i = 0; i < numOfLines; i++){
        for(int j = 0; j < L; j++){
            hashTablesArray[j]->insert(&arrayOfPoints[i]);
        }
    }

    // for(int i = 0; i < L; i++){
    //     cout << "HASH TABLE: " << i << endl;
    //     cout << "----------" << endl;
    //     hashTablesArray[i]->print();
    //     cout<< endl;
    // }

    // we have initialized our hash tables...
    // now we need to read the query file, 
    // and for a q point we ought to create the following output:
    // -------------------------------------------------------
    // Query: query_id
    // Nearest neighbor-1: item_id
    // distanceLSH: <double> [ή distanceHypercube αντίστοιχα]
    // distanceTrue: <double>
    // ...
    // Nearest neighbor-N: item_id
    // distanceLSH: <double> [ή distanceHypercube αντίστοιχα]
    // distanceTrue: <double>
    // tLSH: <double>
    // tTrue: <double>
    // R-near neighbors:
    // item_id_A
    // item_id_B
    // . . .
    // item_id_Z

    // first things first 
    // read query_file line by line...

    vector<point> arrayOfQueryPoints;
    res = parsInit(inputFile, arrayOfQueryPoints, &numOfLinesQ, &numOfElementsQ);
    numOfDimensionsQ = numOfElementsQ - 1; 
    if(res == 1){
        exit(1);
    }

    if(arrayOfQueryPoints.empty()){
        exit(1);
    }
    // we have initialized an array of objects-points from query file...
    // now let's find their nearest neighbors...
    for(int i = 0; i < L; i++){
        cout << "HASH #" << i << endl;
        cout << "----------------\n\n";
        cout << "POINT: " << endl;
        for(int j = 0; j < arrayOfQueryPoints[0].pVector.size(); j++){
            cout << arrayOfQueryPoints[0].pVector[j] << " ";
        }
        cout << endl << endl;
        hashTablesArray[i]->findNeighbors(&arrayOfQueryPoints[0]);
    }

    exit(1);
}
