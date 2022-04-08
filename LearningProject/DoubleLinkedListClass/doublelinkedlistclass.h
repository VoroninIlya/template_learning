#ifndef DOUBLELINKEDLISTCLASS_H
#define DOUBLELINKEDLISTCLASS_H

#include "ListClass/listclass.h"
#include "dllnodeclass.h"

using namespace std;

// ====================================================
// Double Linked List Class Implementation ============
// ========================================= Voronin.IV

// ====================================================
// Double Linked List Class declaration ===============
template <typename T>
class DoubleLinkedListClass : public ListClass<T>{
public:
    DoubleLinkedListClass();
    void printList();
    void insertToHead(int,T);
    void insertToTail(int,T);
    bool isEmpty();
    int length();

    DLLNodeClass<T> deleteFromHead();
    DLLNodeClass<T> deleteFromTail();
    DLLNodeClass<T> deleteNode(int key);
    DLLNodeClass<T> getNode(int key);

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
    DLLNodeClass<T> *head;
    DLLNodeClass<T> *tail;
};
// ====================================================
// Linked List Class constructor ======================
template <typename T>
DoubleLinkedListClass<T>::DoubleLinkedListClass(){
    this->head    = NULL;
    this->tail    = NULL;
}
// ====================================================
// Insert node to head ================================
template <typename T>
void DoubleLinkedListClass<T>::insertToHead(int key,
                                      T data){
    DLLNodeClass<T> *NewNode =
            new DLLNodeClass<T>(key,data,this->head,NULL);
    if (this->head != NULL){
        this->head->setPtrPrev(NewNode);
    }
    this->head = NewNode;
    if (this->length() == 1){
       this->tail = this->head;
    }
}
// ====================================================
// Insert node to tail ================================
template <typename T>
void DoubleLinkedListClass<T>::insertToTail(int key,
                                      T data){
    DLLNodeClass<T> *NewNode =
            new DLLNodeClass<T>(key,data,NULL,NULL);
    if (this->tail != NULL){
        this->tail->setPtrNext(NewNode);
    }
    NewNode->setPtrPrev(this->tail);
    this->tail = NewNode;
    if (this->head == NULL){
       this->head = this->tail;
    }
}
// ====================================================
// Delete node from head ==============================
template <typename T>
DLLNodeClass<T> DoubleLinkedListClass<T>::deleteFromHead(){
    try{
        if (this->head == NULL){
          throw 0;
        }
        DLLNodeClass<T> tempNode = *this->head;
        delete this->head;
        if (tempNode.getPtrNext() != NULL){
            this->head = tempNode.getPtrNext();
            this->head->setPtrPrev(NULL);
        }else{
            this->head = NULL;
            this->tail = NULL;
        }
        return tempNode;
    }catch(int x) {
        cout << "\r\nDelete error: "
                "head pointer is NULL" << endl;
        DLLNodeClass<T> *node = new DLLNodeClass<T> (0, 0, NULL, NULL);
        return *node;
    }
}
// ====================================================
// Delete node from tail ==============================
template <typename T>
DLLNodeClass<T> DoubleLinkedListClass<T>::deleteFromTail(){
    try{
        if (this->tail == NULL){
          throw 0;
        }
        DLLNodeClass<T> tempNode = *this->tail;
        delete this->tail;
        if (tempNode.getPtrPrev() != NULL){
            this->tail = tempNode.getPtrPrev();
            this->tail->setPtrNext(NULL);
        }else{
            this->head = NULL;
            this->tail = NULL;
        }
        return tempNode;
    }catch(int x) {
        cout << "\r\nDelete error: "
                "tail pointer is NULL" << endl;
        DLLNodeClass<T> *node = new DLLNodeClass<T> (0, 0, NULL, NULL);
        return *node;
    }
}
// ====================================================
// Delete node by the key =============================
template <typename T>
DLLNodeClass<T> DoubleLinkedListClass<T>::deleteNode(int key){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        DLLNodeClass<T> *current = this->head;
        while(current->getKey() != key){
           if(current->getPtrNext() == NULL){
              throw 1;
           } else {
               current = current->getPtrNext();
           }
        }
        DLLNodeClass<T> result = *current;
        if (current == this->head){
            this->head = current->getPtrNext();
            this->head->setPtrPrev(NULL);
            delete current;
        }else if (current == this->tail){
            this->tail = current->getPtrPrev();
            this->tail->setPtrNext(NULL);
            delete current;
        }else{
            current->getPtrPrev()->setPtrNext(current->getPtrNext());
            current->getPtrNext()->setPtrPrev(current->getPtrPrev());
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
        DLLNodeClass<T> *node = new DLLNodeClass<T> (0, 0, NULL, NULL);
        return *node;
    }
}
// ====================================================
// Check empty state ==================================
template <typename T>
bool DoubleLinkedListClass<T>::isEmpty(){
   return (this->head == NULL);
}
// ====================================================
// Return length of the list ==========================
template <typename T>
int DoubleLinkedListClass<T>::length(){
   int result = 0;
   DLLNodeClass<T> *current = this->head;
   while(current != NULL){
       result++;
       current = current->getPtrNext();
   }
   return result;
}
// ====================================================
// Get node by the key ================================
template <typename T>
DLLNodeClass<T> DoubleLinkedListClass<T>::getNode(int key){
    try{
       if(this->head == NULL) {
           throw 0;
       }
       DLLNodeClass<T> *current = this->head;
       while(current->getKey() != key){
          if(current->getPtrNext() == NULL){
             throw 1;
          }else{
             current = current->getPtrNext();
          }
       }
       DLLNodeClass<T> result = *current;
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
        DLLNodeClass<T> *node =
                new DLLNodeClass<T> (0, NULL, NULL, NULL);
        return *node;
    }
}
// ====================================================
// Display the liste ==================================
template <typename T>
void DoubleLinkedListClass<T>::printList(){
   DLLNodeClass<T> *ptr = this->head;
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
void DoubleLinkedListClass<T>::BubbleSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int i, j, k, tempKey, sorted_flag;
        T tempData;
        DLLNodeClass<T> *current;
        DLLNodeClass<T> *next;

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
void DoubleLinkedListClass<T>::SelectionSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int i, tempKey;
        T             tempData;
        DLLNodeClass<T> *UnsortedArea;
        DLLNodeClass<T> *Current;
        DLLNodeClass<T> *Minimum;

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
void DoubleLinkedListClass<T>::InsertionSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int i;
        DLLNodeClass<T> *SortedAreaTail   = this->head;

        int sorted_nodes   = 1;

        while(SortedAreaTail->getPtrNext() != NULL){

            DLLNodeClass<T> *SortedCurrent    = this->head;
            DLLNodeClass<T> *Current =
                    SortedAreaTail->getPtrNext();

            for(i = 0; i < sorted_nodes; i++){
                if(SortingCondition(SortedCurrent->getData(),
                                    Current->getData())){
                    SortedAreaTail->setPtrNext(
                                    Current->getPtrNext());
                    if (Current->getPtrNext() != NULL){
                        Current->getPtrNext()->setPtrPrev(SortedAreaTail);
                    }
                    if (SortedCurrent == this->head){
                        Current->setPtrPrev(NULL);
                        Current->setPtrNext(SortedCurrent);
                        SortedCurrent->setPtrPrev(Current);
                        this->head = Current;
                    }else{
                        Current->setPtrNext(SortedCurrent);
                        Current->setPtrPrev(SortedCurrent->getPtrPrev());
                        SortedCurrent->getPtrPrev()->setPtrNext(Current);
                        SortedCurrent->setPtrPrev(Current);
                    }
                    break;
                }else{
                    if(SortedCurrent == SortedAreaTail){
                      SortedAreaTail = Current;
                    }else{
                      SortedCurrent =
                              SortedCurrent->getPtrNext();
                    }
                }
            }
            sorted_nodes++;
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
void DoubleLinkedListClass<T>::GnomeSort(
    bool (*const SortingCondition)(T preNodeData,
                                   T currNodeData)){
    try{
        if(this->head == NULL) {
           throw 0;
        }
        int tempKey;
        T   tempData;
        DLLNodeClass<T> *preCurrent = this->head;
        DLLNodeClass<T> *Current    = this->head;

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

                if (preCurrent->getPtrPrev() != NULL){
                    Current = preCurrent->getPtrPrev();
                }else{
                    Current    = this->head;
                }
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
void DoubleLinkedListClass<T>::QuickSort(bool (*SortingCondition)
               (T preNodeData,T currNodeData)){

}
#endif // DOUBLELINKEDLISTCLASS_H
