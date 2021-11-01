
#ifndef HASH
#define HASH
    #include "includes.h"
    #include "linkedlist.h"
    #include "others.h"

    class hashTable{
        private:
            vector<list<linkedListNode*>> array;
            int size;
        public:
            int insert(point* pGiven, int w, vector<int>& rVector, vector<vAndT>& vAndTVector, int k);
            int search(point* pGiven);
            int hashFunction(point* pGiven, vector<vAndT> & vAndTForHash, int k, int w, std:: vector<int> &rVector);
            ~hashTable();
            hashTable(int size);
            vector<list<linkedListNode*>> getArray();
            void print();
    };
    
#endif