#ifndef LLNODECLASS_H
#define LLNODECLASS_H

#include "nodeclass/nodeclass.h"

using namespace std;
// ====================================================
// Node Class Implementation ==========================
// ========================================= Voronin.IV

// ====================================================
// Node Class declaration =============================
template <typename T>
class LLNodeClass : public NodeClass<T>{
public:
    LLNodeClass(int, T, LLNodeClass<T>*);
    ~LLNodeClass(){}
    void setPtrNext(LLNodeClass<T>*);
    LLNodeClass<T>* getPtrNext();
private:
    LLNodeClass<T> *next;
};
// ====================================================
// Node Class constructor =============================
template <typename T>
LLNodeClass<T>::LLNodeClass(int key, T data,
                        LLNodeClass<T>* next){
    this->setKey(key);
    this->setData(data);
    this->next = next;
}
// ====================================================
// Get pointer to next node ===========================
template <typename T>
LLNodeClass<T>* LLNodeClass<T>::getPtrNext(){
    return this->next;
}
// ====================================================
// Set pointer to next node ===========================
template <typename T>
void LLNodeClass<T>::setPtrNext(LLNodeClass<T>* new_next){
    this->next = new_next;
}
#endif // LLNODECLASS_H
