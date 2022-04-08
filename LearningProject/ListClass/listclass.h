#ifndef LISTCLASS_H
#define LISTCLASS_H

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>

template <typename T>
class ListClass{
public:
    ListClass();
    virtual void printList() = 0;
    virtual void insertToHead(int,T) = 0;
    virtual void insertToTail(int,T) = 0;
    virtual bool isEmpty() = 0;
    virtual int  length() = 0;

    virtual void BubbleSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData)) = 0;
    virtual void SelectionSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData)) = 0;
    virtual void InsertionSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData)) = 0;
    virtual void GnomeSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData)) = 0;
    virtual void QuickSort(bool (*SortingCondition)
                   (T preNodeData,T currNodeData)) = 0;

};
// ====================================================
// List Class constructor =============================
template <typename T>
ListClass<T>::ListClass(){
}
#endif // LISTCLASS_H