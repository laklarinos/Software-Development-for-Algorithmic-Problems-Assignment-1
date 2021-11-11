#include "parsinginit.h"
#include "cluster.h"
using namespace std;

int main(int argc, char *argv[])
{
    char *inputFile;
    char *outputFile;
    char *confFile;
    char *complete;
    char *method;

    int kLSH;
    int kCUBE;
    int L;
    int M;
    int numberOfNN;
    int rad;
    int w = 3;
    int numOfClusters;
    int probes;
    int numOfLines;
    int numOfElements;
    int numOfDimensions;

    lshConstants lshCon;

    // for query file
    int numOfLinesQ;
    int numOfElementsQ;
    int numOfDimensionsQ;

    int checkArgs = checkCommandLineArguments(argc, argv);
    if (checkArgs)
    {
        exit(1);
    }

    //init arguments
    inputFile = argv[2];
    confFile = argv[4];
    outputFile = argv[6];
    complete = argv[8];
    method = argv[10];

    //read conf file...
    vector<int> vecOfConfArgs;
    string line;
    fstream confFilePtr;
    confFilePtr.open(confFile);
    int counter = 0;

    while (getline(confFilePtr, line))
    {
        stringstream ss(line);
        string s;
        while (getline(ss, s, ' '))
        {
            counter++;
            if (counter % 2 == 0)
            {
                vecOfConfArgs.push_back(stoi(s));
            }
        }
    }

    if (vecOfConfArgs.size() == 6)
    {
        numOfClusters = vecOfConfArgs[0];
        L = vecOfConfArgs[1];
        kLSH = vecOfConfArgs[2];
        M = vecOfConfArgs[3];
        kCUBE = vecOfConfArgs[4];
        probes = vecOfConfArgs[5];
    }
    else
    {
        cout << "ERROR, .conf file should provide 6 arguments.\n";
        return 1;
    }

    fstream inputFilePtr;
    fstream queryFilePtr;
    fstream outputFilePtr;

    vector<point> arrayOfPoints;

    int res = parsInit(inputFile, arrayOfPoints, &numOfLines, &numOfElements);
    numOfDimensions = numOfElements - 1;
    if (res == 1)
    {
        exit(1);
    }

    if (arrayOfPoints.empty())
    {
        exit(1);
    }

    vector<hashTable *> hashTablesArray(L);
    for (int i = 0; i < L; i++)
    {
        hashTablesArray[i] = new hashTable(numOfLines / 4, &lshCon, numOfDimensions);
    }

    // first centroid randomly generated...
    vector<centroid> vecOfCentroids;

    // K-MEANS ++, INITIALIZATION
    initCentroids(vecOfCentroids, numOfClusters, arrayOfPoints);
    // LLOYD, LSH REVERSE, HYPERCUBE REVERSE, ASSIGNMENT

    if (strcmp(method, "Classic") == 0)
    {
        // LLOYD
        
    }
    else if (strcmp(method, "LSH") == 0)
    {
        // LSH REVERSE
    }
    else if (strcmp(method, "Hyper") == 0)
    {
        // HYPERCUBE REVERSE
    }

    return 0;
}
