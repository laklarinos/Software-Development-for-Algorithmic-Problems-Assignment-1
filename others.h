#ifndef OTHERS
#define OTHERS

#include "includes.h"

typedef struct vAndT{
    std::vector<int> vVector;
    float t;
}vAndT;

class point{
    private:
        int dimensions;
    public:
        std::vector<int> pVector;
        std::vector<int>* getVector();
        int getDimensions();
        point(std::vector<int> pVector);
        ~point();
};

bool checkCommandLineArguments(int argcInt, char* argvArray[]);
int euclideanRemainder(int a, int b);
int myPow(int x, int p);
#endif