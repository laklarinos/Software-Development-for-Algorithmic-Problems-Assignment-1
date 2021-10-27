#ifndef LINKEDLIST
#define LINKEDLIST
#include "includes.h"
using namespace std;
class linkedListNode{
   
   private:
      int** pVector;
      int key;
      struct linkedListNode *next; 
   
   public:
      void printList();
      void insertFirst(int key, int** pVectorGiven);
      struct linkedListNode* deleteFirst();
      bool isEmpty();
      int length();
      struct linkedListNode* find(int key);
      struct linkedListNode* delete(int key);
};

#endif