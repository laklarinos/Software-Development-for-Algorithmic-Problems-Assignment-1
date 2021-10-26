#include "hashtable.h"

int hashCode(int key) {
   return key % SIZE;
}

DataItem *search(int key) {
//    //get the hash 
//    int hashIndex = hashCode(key);  
	
//    //move in array until an empty 
//    while(hashArray[hashIndex] != NULL) {
	
//       if(hashArray[hashIndex]->key == key)
//          return hashArray[hashIndex]; 
			
//       //go to next cell
//       ++hashIndex;
		
//       //wrap around the table
//       hashIndex %= SIZE;
//    }        
	
//    return NULL;        
}

void insert(int key,int data) {

//    DataItem *item = (DataItem*) malloc(sizeof(DataItem));
//    item->data = data;  
//    item->key = key;

//    //get the hash 
//    int hashIndex = hashCode(key);

//    //move in array until an empty or deleted cell
//    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
//       //go to next cell
//       ++hashIndex;
		
//       //wrap around the table
//       hashIndex %= SIZE;
//    }
	
//    hashArray[hashIndex] = item;
}

DataItem* delete(DataItem* item) {
//    int key = item->key;

//    //get the hash 
//    int hashIndex = hashCode(key);

//    //move in array until an empty
//    while(hashArray[hashIndex] != NULL) {
	
//       if(hashArray[hashIndex]->key == key) {
//          DataItem* temp = hashArray[hashIndex]; 
			
//          //assign a dummy item at deleted position
//          hashArray[hashIndex] = dummyItem; 
//          return temp;
//       }
		
//       //go to next cell
//       ++hashIndex;
		
//       //wrap around the table
//       hashIndex %= SIZE;
//    }      
	
//    return NULL;        
}

void display() {

//    for(int i = 0; i<SIZE; i++) {
	
//       if(hashArray[i] != NULL)
//          printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
//       else
//          printf(" ~~ ");
//    }
	
//    printf("\n");
}
