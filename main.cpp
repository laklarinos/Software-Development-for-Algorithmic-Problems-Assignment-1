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
    int arrayOfElementsPerLine;
    int numOfDimensions;

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

    vector<point> arrayOfPointersToLinesElements;

    int res = parsInit(inputFile, &numOfLines, &arrayOfElementsPerLine, arrayOfPointersToLinesElements, numOfDimensions); 
    if(res == 1){
        exit(1);
    }

    if(arrayOfPointersToLinesElements.empty()){
        exit(1);
    }

    // before proceeding to initialization we need to compute some values...
    // vector r may be the same for every g funtion...
    // thus Im gonna create a 3*k array of random integers...
    // Pick k out of it randomly and use them as R vector for a specific point...

    vector<int> rVectors(k);
    for(int i = 0; i < L; i++){
        srand (time(NULL));
        for(int j = 0; j <  k; j++){
            auto itPos = rVectors.begin() + j;
            rVectors.insert(itPos, rand()%10000);
        }
    }

    // GENERAL INFO:
    // for every p, I need L g_i functions...
    // every g_i function needs k h_i functions and k r_i values...
    // every h_i needs a pair of v, t vectors...
    // v, t must change between h_i...
    // v, d-vector ∼ N (0, 1) d has coordinates by the standard normal distribution
    // real t is not a vector, is a real single percition (float) uniformly ∈ R [0, w)
    
    // Idea: 
    // Create an array of arrays of pairs of v and t
    // vAndT is a struct defined in others.h which demonstrates
    // a v, t pair. 

    // this is our array
    // for every hash table we want k pairs of v, t
    // thus the size of vL is L.
    // each one of L indexes has an array of k size 
    // each one of the k indexes has a (v,t) pair...
    vector<vector<vAndT>> vL(L);

    // normal distribution
    std::random_device rd; 
    std::mt19937 gen(rd());

    // uniform distribution
    std::random_device rd1;
    std::mt19937 gen1(rd1());

    int sample;

    for(int i = 0; i < L; i++){
        auto itPos = vL.begin() + i;
        vector<vAndT> vAndTVector(k);
        for(int j = 0; j < k; j++){
            
            std::uniform_real_distribution<float> uniDis(0, w-1);
            auto itPos1 = vAndTVector.begin() + j;
            vAndT vAndTNode;
            vAndTNode.t = uniDis(gen1);
            vAndTNode.vVector.resize(L-1);
            
            for(int z = 0; z < numOfDimensions; z++){
                std::normal_distribution<float> normDis(0, 1);
                sample = (int)round(normDis(gen)); 
                auto itPos2 = vAndTNode.vVector.begin() + z;
                vAndTNode.vVector.insert(itPos2, sample);
            }
            vAndTVector.insert(itPos1, vAndTNode);
        }
        vL.insert(itPos, vAndTVector);
    }

    // for(int i = 0; i < L; i++){
    //     for( int j = 0; j < k; j++){
    //         cout << "Hash: "<<i << " Bucket: " << j << endl;
    //         cout << "------------\n";
    //         for(int z = 0; z < numOfDimensions; z++){
    //             cout << vL[i][j].vVector[z] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    // return 1;
    
    // now lets start the insertion...
    vector<hashTable*> hashTablesArray(L);
    for(int i = 0; i < L; i++){
        hashTablesArray[i] = new hashTable(numOfLines/4);
    }

    for(int i = 0; i < numOfLines; i++){
        for(int j = 0; j < L; j++){
            hashTablesArray[j]->insert(&arrayOfPointersToLinesElements[i], w, rVectors, vL[j], k);
        }
    }

    // for(int i = 0; i < L; i++){
    //     cout << "HASH TABLE: " << i << endl;
    //     cout << "----------" << endl;
    //     hashTablesArray[i]->print();
    //     cout<< endl;
    // }

    exit(1);
}
