#include "hashtable.h"
hashTable:: hashTable(int size, lshConstants* lshCon, int numOfDimensions){
    this->array.resize(size);
    this->size = size;
    this->lshCon = lshCon;
    this->rVector.resize(lshCon->k);

    for(int j = 0; j <  lshCon->k; j++){
        auto itPos = this->rVector.begin() + j;
        this->rVector.insert(itPos, rand()%10000);
    }

    // produce...
    std::random_device rd; 
    std::mt19937 gen(rd());

    // uniform distribution
    std::random_device rd1;
    std::mt19937 gen1(rd1());
    
    this->vAndTVector.resize(lshCon->k);
    int sample;

    for(int j = 0; j < lshCon->k; j++){
        std::uniform_real_distribution<float> uniDis(0, lshCon->w - 1);
        auto itPos1 = this->vAndTVector.begin() + j;
        vAndT vAndTNode;
        vAndTNode.t = uniDis(gen1);
        vAndTNode.vVector.resize(numOfDimensions);        
        for(int z = 0; z < numOfDimensions; z++){
            std::normal_distribution<float> normDis(0, 1);
            sample = (int)round(normDis(gen)); 
            auto itPos2 = vAndTNode.vVector.begin() + z;
            vAndTNode.vVector.insert(itPos2, sample);
        }
        this->vAndTVector.insert(itPos1, vAndTNode);
    }
}

int hashTable:: insert(point* pGiven){
    int key = hashFunction(pGiven);
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

int hashTable:: hashFunction(point* pGiven){
    
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
    vector<int> hi(lshCon->k);
    
    for(int i = 0; i < lshCon->k; i++){
        vAndT* tempVAndT = &(this->vAndTVector[i]);
        vp = std:: inner_product(pGiven->pVector.begin(), pGiven->pVector.end(), tempVAndT->vVector.begin(), 0);
        vpplust = vp + tempVAndT->t;
        toLowerBound = vpplust/lshCon->w;
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
                std::cout << ptr->pVector.at(0) << ' ';                    
                cout << endl;
            }
            cout << "\n";
        }
    }
}

vector<list<linkedListNode*>> hashTable:: getArray(){
    return this->array;
}

list<linkedListNode>* hashTable:: findNeighbors(point* pGiven){
    // given a point we find its nearest neighbors
    int key = hashFunction(pGiven);
    list<linkedListNode*> ::iterator it;
    int c = 0;
    for (it = this->array[key].begin(); it != this->array[key].end(); ++it){
        c++;
        cout << "\nNeighbor #" << c << " is: \n";
        point* pointPtr = (*it)->getPVector();
        for(int j = 0; j < pointPtr->pVector.size(); j++)
            cout << pointPtr->pVector[j] << " ";
        cout << "\n";
    }
    cout << "\n\n";
}