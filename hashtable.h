#include "includes.h"
#define SIZE 20

// Struct to store data of each item
// typedef struct DataItem {
//    int data;   
//    int key;
// } DataItem;

typedef struct item

DataItem* hashArray[SIZE]; 
DataItem* dummyItem;
DataItem* item;

// Structs prototypes
struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

// Function prototypes
int hashCode(int key);
struct DataItem *search(int key);
void insert(int key,int data);
struct DataItem* delete(struct DataItem* item);
void display();