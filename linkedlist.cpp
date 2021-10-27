#include "linkedlist.h"
using namespace std;
//display the list
void printList() {
//    struct linkedListNode *ptr = head;
//    ptr->
//    printf("\n[ ");
	
//    //start from the beginning
//    while(ptr != NULL) {
//       printf("(%d,%d) ",ptr->key,ptr->key);
//       ptr = ptr->next;
//    }
	
//    printf(" ]");
}

//insert link at the first location
void insertFirst(int key, int** pVectorGiven) {
   // //create a link
   //struct linkedListNode *link = (struct linkedListNode*) malloc(sizeof(struct linkedListNode));
	
   // link->key = key;
   // link->data = data;
	
   // //point it to old first linkedListNode
   // link->next = head;
	
   // //point first to new first linkedListNode
   // head = link;
}

//delete first item
struct linkedListNode* deleteFirst() {

   // //save reference to first link
   // struct linkedListNode *tempLink = head;
	
   // //mark next to first link as first 
   // head = head->next;
	
   // //return the deleted link
   // return tempLink;
}

//is list empty
bool isEmpty() {
   // return head == NULL;
}

int length() {
   // int length = 0;
   // struct linkedListNode *current;
	
   // for(current = head; current != NULL; current = current->next) {
   //    length++;
   // }
	
   // return length;
}

//find a link with given key
struct linkedListNode* find(int key) {

   // //start from the first link
   // struct linkedListNode* current = head;

   // //if list is empty
   // if(head == NULL) {
   //    return NULL;
   // }

   // //navigate through list
   // while(current->key != key) {
	
   //    //if it is last linkedListNode
   //    if(current->next == NULL) {
   //       return NULL;
   //    } else {
   //       //go to next link
   //       current = current->next;
   //    }
   // }      
	
   // //if data found, return the current Link
   // return current;
}

//delete a link with given key
struct linkedListNode* delete(int key) {

   // //start from the first link
   // struct linkedListNode* current = head;
   // struct linkedListNode* previous = NULL;
	
   // //if list is empty
   // if(head == NULL) {
   //    return NULL;
   // }

   // //navigate through list
   // while(current->key != key) {

   //    //if it is last linkedListNode
   //    if(current->next == NULL) {
   //       return NULL;
   //    } else {
   //       //store reference to current link
   //       previous = current;
   //       //move to next link
   //       current = current->next;
   //    }
   // }

   // //found a match, update the link
   // if(current == head) {
   //    //change first to point to next link
   //    head = head->next;
   // } else {
   //    //bypass the current link
   //    previous->next = current->next;
   // }    
	
   // return current;
}