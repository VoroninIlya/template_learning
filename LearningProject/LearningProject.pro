QT += core
QT -= gui

CONFIG += c++

TARGET = LearningProject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    SortingConditions/sortingconditions.cpp

HEADERS += \
    LinkedListClass/linkedlistclass.h \
    LinkedListClass/llnodeclass.h \
    SortingConditions/sortingconditions.h \
    DoubleLinkedListClass/doublelinkedlistclass.h \
    DoubleLinkedListClass/dllnodeclass.h \
    ListClass/listclass.h \
    NodeClass/nodeclass.h
