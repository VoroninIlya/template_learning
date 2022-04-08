#ifndef NODECLASS_H
#define NODECLASS_H

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>

using namespace std;

// ====================================================
// Node Class declaration =============================
template <typename T>
class NodeClass{
public:
    NodeClass();
    ~NodeClass(){}
    void PrintNode();
    T getData(void);
    void setData(T);
    int getKey(void);
    void setKey(int);
private:
    int           key;
    T             data;
};
// ====================================================
// Node Class constructor =============================
template <typename T>
NodeClass<T>::NodeClass(){
}
// ====================================================
// Get the node data ===================================
template <typename T>
T NodeClass<T>::getData(){
    return this->data;
}
// ====================================================
// Set the node data ===================================
template <typename T>
void NodeClass<T>::setData(T new_data){
    this->data = new_data;
}
// ====================================================
// Get the node key ===================================
template <typename T>
int NodeClass<T>::getKey(){
    return this->key;
}
// ====================================================
// Set the node key ===================================
template <typename T>
void NodeClass<T>::setKey(int new_key){
    this->key = new_key;
}
// ====================================================
// Display the node ===================================
template <typename T>
void NodeClass<T>::PrintNode(){
    printf("Key: %d, Data: %d",
           this->getKey(),this->getData());
}
template <>
void NodeClass<double>::PrintNode(){
    printf("Key: %d, Data %2.2f",
           this->getKey(),this->getData());
}
template <>
void NodeClass<char*>::PrintNode(){
    printf("Key: %d, Data: %s",
           this->getKey(),this->getData());
}
#endif // NODECLASS_H
