#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>

using namespace std;

//struct Ingredient definition
struct Ingredient{
    string classification;
    string name;
    Ingredient *next;
};

class LinkedList{
    private:
        int length;

    public:
        LinkedList();
        Ingredient *head;
        //insert new at end of current list
        void insertItem(Ingredient *newItem);
        //true if success
        bool removeItem(string itemName);
        //return NULL if not found
        Ingredient *getItem(string itemName);
        void printList(int index);
        string returnHead();
        void histogramPrintList(int index);
        int getLength();
        ~LinkedList();
};

#endif // LINKEDLIST_H
