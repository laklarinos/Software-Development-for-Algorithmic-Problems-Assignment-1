#ifndef PARS_INIT
#define PARS_INIT
    #include "includes.h"
    #include "others.h"
    using namespace std;
    int parsInit(char* inputFile, int* numLinesReturn, int* arrayOfElementsPerLineReturn, vector<point>& vec, int& numOfDimensions); // opens inputFile nad initializes the 2d array...
    void clean(int**);
#endif
