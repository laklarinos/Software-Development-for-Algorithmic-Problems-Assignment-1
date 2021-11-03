#include "linkedlist.h"
using namespace std;

///// linked list node //////
linkedListNode:: linkedListNode(point* pGiven, int key){
    this->pVector = pGiven;
    this->key = key;
}
point* linkedListNode::getPVector(){
    return this->pVector;
}
int linkedListNode:: getKey(){
    return this->key;
}

linkedListNode:: linkedListNode(){}