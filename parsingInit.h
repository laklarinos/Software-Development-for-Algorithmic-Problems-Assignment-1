#ifndef PARS_INIT
#define PARS_INIT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

int** parsInit(char* inputFile, int* numLinesReturn, int** arrayOfElementsPerLineReturn); // opens inputFile nad initializes the 2d array...
void clean(int**);
#endif
