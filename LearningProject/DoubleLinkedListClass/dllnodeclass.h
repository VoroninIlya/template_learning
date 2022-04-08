#ifndef DLLNODECLASS_H
#define DLLNODECLASS_H

#include "nodeclass/nodeclass.h"

template <typename T>
class DLLNodeClass : public NodeClass<T>{
public:
    DLLNodeClass(int, T, DLLNodeClass<T>*, DLLNodeClass<T>*);
    ~DLLNodeClass(){}
    void setPtrNext(DLLNodeClass<T>*);
    DLLNodeClass<T>* getPtrNext();
    void setPtrPrev(DLLNodeClass<T>*);
    DLLNodeClass<T>* getPtrPrev();
private:
    DLLNodeClass<T> *prev;
    DLLNodeClass<T> *next;
};
// ====================================================
// Node Class constructor =============================
template <typename T>
DLLNodeClass<T>::DLLNodeClass(int key, T data,
    DLLNodeClass<T>* next, DLLNodeClass<T>* prev){
    this->setKey(key);
    this->setData(data);
    this->next = next;
    this->prev = prev;
}
// ====================================================
// Node Class destructor ==============================
//template <typename T>
//DLLNodeClass<T>::~DLLNodeClass(){}
// ====================================================
// Get pointer to next node ===========================
template <typename T>
DLLNodeClass<T>* DLLNodeClass<T>::getPtrNext(){
    return this->next;
}
// ====================================================
// Set pointer to next node ===========================
template <typename T>
void DLLNodeClass<T>::setPtrNext(DLLNodeClass<T>* new_next){
    this->next = new_next;
}
// ====================================================
// Get pointer to previous node =======================
template <typename T>
DLLNodeClass<T>* DLLNodeClass<T>::getPtrPrev(){
    return this->prev;
}
// ====================================================
// Set pointer to previous node =======================
template <typename T>
void DLLNodeClass<T>::setPtrPrev(DLLNodeClass<T>* new_prev){
    this->prev = new_prev;
}
#endif // DLLNODECLASS_H
