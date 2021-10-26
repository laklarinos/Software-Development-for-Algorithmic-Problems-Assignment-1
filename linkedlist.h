#ifndef LINKEDLIST
#define LINKEDLIST
#include "includes.h"

typedef struct linkedListNode {
   int** pVector;
   int key;
   struct linkedListNode *next; 
}linkedListNode;

void printList();
void insertFirst(int key, int data);
struct linkedListNode* deleteFirst();
bool isEmpty();
int length();
struct linkedListNode* find(int key);
struct linkedListNode* delete(int key);

#endif