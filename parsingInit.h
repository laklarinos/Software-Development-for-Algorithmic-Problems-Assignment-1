#ifndef PARS_INIT
#define PARS_INIT

#include "includes.h"

int** parsInit(char* inputFile, int* numLinesReturn, int* arrayOfElementsPerLineReturn); // opens inputFile nad initializes the 2d array...
void clean(int**);
#endif
