#include "hashtable.h"
#include "others.h"
hashTable:: hashTable(int size){
    this->array.resize(size);
    this->size = size;
}

int hashTable:: insert(point* pGiven, int w, vector<int>& rVector, vector<vAndT>& vAndTVector, int k ){
    int key = hashFunction(pGiven, vAndTVector, k, w, rVector);
    list<linkedListNode*> listPtr;
    linkedListNode* nodePtr = new linkedListNode(pGiven, pGiven->pVector[0]);
    listPtr.push_back(nodePtr);
    auto itPos = array.begin() + key;
    if(this->array[key].empty()){
        // empty list == first item...
        this->array.insert(itPos, listPtr);
    }else{
        // list is not empty 
        this->array[key].push_back(nodePtr);
    }
}

int hashTable:: search(point* pGiven){}

int hashTable:: hashFunction(point* pGiven, vector<vAndT> & vAndTForHash, int k, int w, vector<int>& rVector){
    
    // g(p) = ID(p) mod Table_Size
    // ID(p) = (Sum |for i = 1 to k| ( h_i*r_i )) mod M, (M = 2^32 - 5)
    // h_i = lower_bound((v.p + t)/w)   
    int M = myPow(2,31);
    M-=5;
    int res; 
    int vp;
    float vpplust;
    int toLowerBound;
    int idP;
    int gP;
    vector<int> hi(k);
    
    for(int i = 0; i < k; i++){
        vp = std:: inner_product(pGiven->pVector.begin(), pGiven->pVector.end(), vAndTForHash[i].vVector.begin(), 0);
        vpplust = vp + vAndTForHash[i].t;
        toLowerBound = vpplust/w;
        auto itPos = hi.begin() + i;
        hi.insert(itPos, toLowerBound);
    }

    idP = std:: inner_product(hi.begin(), hi.end(), rVector.begin(), 0);
    idP = euclideanRemainder(idP, M);
    gP = euclideanRemainder(idP, this->size);

    return gP;
}

hashTable:: ~hashTable(){

}

void hashTable:: print(){
    for(int i = 0; i < this->size; i++){
        if(!this->array[i].empty()){
            cout << "Bucket: " << i << endl;
            for(std::list<linkedListNode*>::iterator it = (this->array[i]).begin(); it != (this->array[i]).end(); it++){
                point* ptr = (*it)->getPVector();
                for(int k=0; k < ptr->pVector.size(); k++)
                    std::cout << ptr->pVector.at(k) << ' ';
                cout << endl;
            }
        }
    }
}

vector<list<linkedListNode*>> hashTable:: getArray(){
    return this->array;
}