#include <QCoreApplication>

#include "LinkedListClass/linkedlistclass.h"
#include "DoubleLinkedListClass/doublelinkedlistclass.h"
#include "SortingConditions/sortingconditions.h"

using namespace std;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    char str[20][100] = {0};

    DoubleLinkedListClass<char*>  *sDLList =
            new DoubleLinkedListClass<char*>();
    strcpy(str[0],"Ivan");
    sDLList->insertToTail(1,str[0]);
    strcpy(str[1],"Yuriy");
    sDLList->insertToTail(2,str[1]);
    strcpy(str[2],"Maxim");
    sDLList->insertToTail(3,str[2]);
    strcpy(str[3],"Alexandr");
    sDLList->insertToTail(4,str[3]);
    strcpy(str[4],"Boris");
    sDLList->insertToTail(5,str[4]);
    strcpy(str[5],"Andrey");
    sDLList->insertToTail(6,str[5]);
    strcpy(str[6],"Ilya");
    sDLList->insertToTail(7,str[6]);
    strcpy(str[7],"Mihail");
    sDLList->insertToTail(8,str[7]);
    strcpy(str[8],"Marat");
    sDLList->insertToTail(9,str[8]);
    strcpy(str[9],"Semyon");
    sDLList->insertToTail(10,str[9]);
    strcpy(str[10],"Dmitriy");
    sDLList->insertToHead(0,str[10]);

    DLLNodeClass<char*> deleted_node = sDLList->deleteNode(3);
    if (deleted_node.getData() != NULL){
        cout << "\r\nDeleted Node - ";
        deleted_node.PrintNode();
    }
    delete &deleted_node;

    cout << "\r\nUnsorted List =======================" << endl;
    sDLList->printList();

    sDLList->BubbleSort(&AlphaBethSorting);
    cout << "\r\nAlphabetically Sorted List by BubbleSort==========" << endl;
    sDLList->printList();

    sDLList->SelectionSort(&iAlphaBethSorting);
    cout << "\r\nInverse Alphabetically Sorted List by SelectionSort==========" << endl;
    sDLList->printList();

    sDLList->InsertionSort(&AlphaBethSorting);
    cout << "\r\nAlphabetically Sorted List by InsertionSort==========" << endl;
    sDLList->printList();

    sDLList->GnomeSort(&AlphaBethSorting);
    cout << "\r\nAlphabetically Sorted List by GnomeSort==========" << endl;
    sDLList->printList();

    DLLNodeClass<char*> found_node = sDLList->getNode(400);
    if (found_node.getData() != NULL){
        cout << "\r\nNode found - ";
        found_node.PrintNode();
    }
    delete &found_node;

    return a.exec();
}

