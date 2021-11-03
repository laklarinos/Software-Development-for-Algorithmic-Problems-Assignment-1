#ifndef LINKEDLIST
#define LINKEDLIST
#include "includes.h"
#include "others.h"
using namespace std;

class linkedListNode{
   private:
      point* pVector;
      int key;
   public:
      linkedListNode(point* pGiven, int key);
      linkedListNode();
      point* getPVector();
      int getKey();
};

#endif

