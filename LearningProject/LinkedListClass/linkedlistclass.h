#ifndef LINKEDLISTCLASS_H
#define LINKEDLISTCLASS_H

#include "ListClass/listclass.h"
#include "llnodeclass.h"

using namespace std;

// ====================================================
// Linked List Class Implementation ===================
// ========================================= Voronin.IV

// ====================================================
// Linked List Class declaration ======================
template <typename T>
class LinkedListClass : public ListClass<T>{
public:
    LinkedListClass();
    void printList();
    void insertToHead(int,T);
    void insertToTail(int,T);
    bool isEmpty();
    int length();
    LLNodeClass<T> deleteFromHead();
    LLNodeClass<T> deleteFromTail();
    LLNodeClass<T> deleteNode(int key);
    LLNodeClass<T> getNode(int key);

    void BubbleSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData));
    void SelectionSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData));
    void InsertionSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData));
    void GnomeSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData));
    void QuickSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData));

private:
    LLNodeClass<T> *head;
    LLNodeClass<T> *tail;
};
// ====================================================
// Linked List Class constructor ======================
template <typename T>
LinkedListClass<T>::LinkedListClass(){
    this->head    = NULL;
    this->tail    = NULL;
}
// ====================================================
// Insert node to head ================================
template <typename T>
void LinkedListClass<T>::insertToHead(int key,
                                      T data){
    LLNodeClass<T> *NewNode =
            new LLNodeClass<T>(key,data,this->head);
    this->head = NewNode;
    if (length() == 1){
       this->tail = this->head;
    }
}
// ====================================================
// Insert node to tail ================================
template <typename T>
void LinkedListClass<T>::insertToTail(int key,
                                      T data){
    LLNodeClass<T> *NewNode =
            new LLNodeClass<T>(key,data,NULL);
    if (this->tail != NULL){
        this->tail->setPtrNext(NewNode);
    }
    this->tail = NewNode;
    if (this->head == NULL){
       this->head = this->tail;
    }
}
// ====================================================
// Delete node from head ==============================
template <typename T>
LLNodeClass<T> LinkedListClass<T>::deleteFromHead(){
    try{
        if (this->head == NULL){
          throw 0;
        }
        LLNodeClass<T> tempNode = *this->head;
        delete this->head;
        if (tempNode.getPtrNext() != NULL){
            this->head = tempNode.getPtrNext();
        }else{
            this->head = NULL;
            this->tail = NULL;
        }
        return tempNode;
    }catch(int x) {
        cout << "\r\nDelete error: "
                "head pointer is NULL" << endl;
        LLNodeClass<T> *node = new LLNodeClass<T> (0, 0, NULL);
        return *node;
    }
}
// ====================================================
// Delete node from tail ==============================
template <typename T>
LLNodeClass<T> LinkedListClass<T>::deleteFromTail(){
    try{
        if (this->tail == NULL){
          throw 0;
        }
        LLNodeClass<T> tempNode = *this->tail;
        LLNodeClass<T> *preTail = this->head;

        int size = this->length();
        if (size > 1){
            for(int i = 0; i < size-2; i++){
                preTail = preTail->getPtrNext();
            }
        }
        if (preTail->getPtrNext() != NULL){
            preTail->setPtrNext(NULL);
        }else{
            preTail = NULL;
            this->head = NULL;
        }
        delete this->tail;
        this->tail = preTail;
        return tempNode;
    }catch(int x) {
        cout << "\r\nDelete error: "
                "tail pointer is NULL" << endl;
        LLNodeClass<T> *node = new LLNodeClass<T> (0, 0, NULL);
        return *node;
    }
}
// ====================================================
// Delete node by the key =============================
template <typename T>
LLNodeClass<T> LinkedListClass<T>::deleteNode(int key){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        LLNodeClass<T> *current = this->head;
        LLNodeClass<T> *previous = NULL;
        while(current->getKey() != key){
           if(current->getPtrNext() == NULL){
              throw 1;
           } else {
               previous = current;
               current = current->getPtrNext();
           }
        }
        LLNodeClass<T> result = *current;
        if (current == this->head){
            this->head = this->head->getPtrNext();
            delete current;
        }else{
            previous->setPtrNext(current->getPtrNext());
            delete current;
        }
        return result;
    }catch(int x) {
        if (x == 0){
            cout << "\r\nDelete error: "
                    "head pointer is NULL" << endl;
        }
        if (x == 1){
            cout << "\r\nDelete error: "
                    "key wasn't found" << endl;
        }
        LLNodeClass<T> *node = new LLNodeClass<T> (0, 0, NULL);
        return *node;
    }
}
// ====================================================
// Check empty state ==================================
template <typename T>
bool LinkedListClass<T>::isEmpty(){
   return (this->head == NULL);
}
// ====================================================
// Return length of the list ==========================
template <typename T>
int LinkedListClass<T>::length(){
   int result = 0;
   LLNodeClass<T> *current = this->head;
   while(current != NULL){
       result++;
       current = current->getPtrNext();
   }
   return result;
}
// ====================================================
// Get node by the key ================================
template <typename T>
LLNodeClass<T> LinkedListClass<T>::getNode(int key){
    try{
       if(this->head == NULL) {
           throw 0;
       }
       LLNodeClass<T> *current = this->head;
       while(current->getKey() != key){
          if(current->getPtrNext() == NULL){
             throw 1;
          }else{
             current = current->getPtrNext();
          }
       }
       LLNodeClass<T> result = *current;
       return result;
    }catch(int x) {
        if (x == 0){
            cout << "\r\ngetNode: "
                    "head pointer is NULL" << endl;
        }
        if (x == 1){
            cout << "\r\ngetNode: "
                    "key wasn't found" << endl;
        }
        LLNodeClass<T> *node =
                new LLNodeClass<T> (0, NULL, NULL);
        return *node;
    }
}
// ====================================================
// Display the liste ==================================
template <typename T>
void LinkedListClass<T>::printList(){
   LLNodeClass<T> *ptr = this->head;
   int number = 0;
   while(ptr != NULL){
      cout << "No.: " << number << " ";
      number++;
      ptr->PrintNode();
      if (ptr == this->head){
          cout << " - head";
      }
      if (ptr == this->tail){
          cout << " - tail";
      }
      cout << "\r\n";
      ptr = ptr->getPtrNext();
   }
}
// ====================================================
// Bubble Sort sorting algorithm ======================
template <typename T>
void LinkedListClass<T>::BubbleSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int i, j, k, tempKey, sorted_flag;
        T tempData;
        LLNodeClass<T> *current;
        LLNodeClass<T> *next;

        int size = this->length();
        k = size;

        for (i = 0 ; i < size - 1 ; i++, k--){
            current = this->head;
            next = this->head->getPtrNext();
            sorted_flag = 1;
            for ( j = 1 ; j < k ; j++ ){
                if(SortingCondition(current->getData(),
                                    next->getData())){
                    sorted_flag = 0;
                    tempData = current->getData();
                    current->setData(next->getData());
                    next->setData(tempData);
                    tempKey = current->getKey();
                    current->setKey(next->getKey());
                    next->setKey(tempKey);
                }
                current = current->getPtrNext();
                next = next->getPtrNext();
            }
            if (sorted_flag == 1){
                break;
            }
        }
    }catch(int x) {
        if (x == 0){
            cout << "\r\nBubble Sort: "
                    "head pointer is NULL" << endl;
        }
    }
}
// ====================================================
// Selection Sort sorting algorithm ===================
template<typename T>
void LinkedListClass<T>::SelectionSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int i, tempKey;
        T             tempData;
        LLNodeClass<T> *UnsortedArea;
        LLNodeClass<T> *Current;
        LLNodeClass<T> *Minimum;

        int size = this->length();

        UnsortedArea = this->head;
        Minimum = UnsortedArea;
        Current = UnsortedArea;

        for (i = 0 ; i < size; i++) {
            while(Current != NULL) {
                if (SortingCondition(Minimum->getData(),
                                     Current->getData())) {
                    Minimum = Current;
                }
                Current = Current->getPtrNext();
            }
            if (Minimum != UnsortedArea) {
                tempData = Minimum->getData();
                Minimum->setData(UnsortedArea->getData());
                UnsortedArea->setData(tempData);
                tempKey = Minimum->getKey();
                Minimum->setKey(UnsortedArea->getKey());
                UnsortedArea->setKey(tempKey);
            }
            UnsortedArea = UnsortedArea->getPtrNext();
            Current = UnsortedArea;
            Minimum = UnsortedArea;
        }
    }catch(int x) {
        if (x == 0){
            cout << "\r\nSelection Sort: "
                    "head pointer is NULL" << endl;
        }
    }
}
// ====================================================
// Insertion Sort sorting algorithm ===================
template<typename T>
void LinkedListClass<T>::InsertionSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int i, tempKey;
        T             tempData;
        LLNodeClass<T> *SortedAreaTail   = this->head;

        int size = this->length();
        int sorted_nodes   = 1;
        int unsorted_nodes = size;

        while(SortedAreaTail->getPtrNext() != NULL){

            LLNodeClass<T> *preSortedCurrent = this->head;
            LLNodeClass<T> *SortedCurrent    = this->head;
            LLNodeClass<T> *Current =
                    SortedAreaTail->getPtrNext();

            for(i = 0; i < sorted_nodes; i++){
                if(SortingCondition(SortedCurrent->getData(),
                                    Current->getData())){
                    SortedAreaTail->setPtrNext(
                                Current->getPtrNext());
                    if (SortedCurrent != this->head){
                        preSortedCurrent->setPtrNext(Current);
                        Current->setPtrNext(SortedCurrent);
                    }else{
                        this->head = Current;
                        Current->setPtrNext(SortedCurrent);
                    }
                    break;
                }else{
                    if(SortedCurrent == SortedAreaTail){
                      SortedAreaTail = Current;
                    }else{
                      preSortedCurrent = SortedCurrent;
                      SortedCurrent =
                              SortedCurrent->getPtrNext();
                    }
                }
            }
            sorted_nodes++;
            unsorted_nodes--;
        }

    }catch(int x) {
        if (x == 0){
            cout << "\r\nInsertion Sort: "
                    "head pointer is NULL" << endl;
        }
    }
}
// ====================================================
// Gnome Sort sorting algorithm =======================
template<typename T>
void LinkedListClass<T>::GnomeSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int i, tempKey;
        T             tempData;
        LLNodeClass<T> *preCurrent = this->head;
        LLNodeClass<T> *Current    = this->head;

        while(Current->getPtrNext() != NULL){
            preCurrent = Current;
            Current = Current->getPtrNext();
            if(SortingCondition(preCurrent->getData(),
                                Current->getData())){
                tempData = preCurrent->getData();
                preCurrent->setData(Current->getData());
                Current->setData(tempData);
                tempKey = preCurrent->getKey();
                preCurrent->setKey(Current->getKey());
                Current->setKey(tempKey);

                preCurrent = this->head;
                Current    = this->head;
            }
        }
    }catch(int x) {
        if (x == 0){
           cout << "\r\nGnome Sort: "
                   "head pointer is NULL" << endl;
        }
    }
}
// ====================================================
// Gnome Sort sorting algorithm =======================
template<typename T>
void LinkedListClass<T>::QuickSort(bool (*SortingCondition)
               (T preNodeData,T currNodeData)){
    cout << "\r\nQuick Sort is impossible for linked list"
            "double linked list must be used" << endl;
}

#endif // LINKEDLISTCLASS_H
