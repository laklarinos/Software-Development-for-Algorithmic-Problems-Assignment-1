#include "parsinginit.h"
#include "hashtable.h"

using namespace std;
#define HYPER_CUBE

int main(int argc, char *argv[])
{
    char *inputFile;
    char *outputFile;
    char *queryFile;

    int k;
    int M;
    int numberOfNN;
    int probes;
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
    if (checkArgs)
    {
        exit(1);
    }

    //define arguments
    inputFile = argv[2];
    queryFile = argv[4];
    outputFile = argv[12];
    k = atoi(argv[6]);
    M = atoi(argv[8]);
    probes = atoi(argv[10]);
    numberOfNN = atoi(argv[14]);
    rad = atoi(argv[16]);

    lshCon.k = k;
    lshCon.w = w;
    lshCon.L = M;

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
    // now lets start the insertion...

    hashTable *hashT;
    hashT = new hashTable(myPow(2, k), &lshCon, numOfDimensions);

    for (int i = 0; i < numOfLines; i++)
        hashT->insert(&arrayOfPoints[i]);

    inputFile = "query_small_id";

    vector<point> arrayOfQueryPoints;
    res = parsInit(inputFile, arrayOfQueryPoints, &numOfLinesQ, &numOfElementsQ);

    numOfDimensionsQ = numOfElementsQ - 1;
    if (res == 1)
    {
        exit(1);
    }

    if (arrayOfQueryPoints.empty())
    {
        exit(1);
    }

    vector<kNearest> list;
    vector<kNearest> listTrue;
    vector<kNearest> listR;

    list.resize(numOfLinesQ);
    listTrue.resize(numOfLinesQ);
    listR.resize(numOfLinesQ);

    outputFile = "output.txt";
    ofstream outputFileStream;

    outputFileStream.open(outputFile, std::ios_base::app);
    // we have initialized an array of objects-points from query file...
    // now let's find their nearest neighbors...
    for (int i = 0; i < numOfLinesQ; i++)
    {
        initKNearest(numberOfNN, &(list[i]));
        initKNearest(numberOfNN, &(listTrue[i]));
        initKNearest(0, &(listR[i]));

        hashT->findKNeighbors(&(arrayOfQueryPoints[i]), &list[i], probes, M);
        hashT->findKNeighborsTrue(&(arrayOfQueryPoints[i]), &listTrue[i], probes, M);
        hashT->findNeighborsR(&(arrayOfQueryPoints[i]), &listR[i], rad, probes, M);

        outputFileStream << "Query: " << arrayOfQueryPoints[i].pVector[0] << endl;
        int tempId = -1;
        for (int z = 0; z < list[i].size; z++)
        {
            if (list[i].dist[z] != MAXFLOAT)
            {
                // we have a neighbor
                outputFileStream << "Nearest neighbor-" << z + 1 << ": " << list[i].nearestPoints[z]->pVector[0] << endl;
                outputFileStream << "distanceCube: " << list[i].dist[z] << endl;
                if (list[i].dist[z] != MAXFLOAT)
                {
                    // we have a neighbor
                    outputFileStream << "distanceTrue: " << listTrue[i].dist[z] << endl
                                     << endl;
                }
            }
        }
        outputFileStream << "R-nearest neigbors: " << endl;
        for (int w = 0; w < listR[i].size; w++)
        {
            outputFileStream << "item_id: " << listR[i].nearestPoints[w]->pVector[0] << endl;
        }
        outputFileStream << "\n////////////////////////////////////////////////////////////\n";
    }
    outputFileStream.close();
    return 1;
}
