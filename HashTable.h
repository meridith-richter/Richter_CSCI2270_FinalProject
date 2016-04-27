#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>
#include <string>

using namespace std;

struct Ingredient{
    string classification;
    string name;
    string product;
    Ingredient *next;
};

class LinkedList{
    private:
        Ingredient * head;
        int length;

    public:
        LinkedList();
        //insert new at end of current list
        void insertItem(Ingredient * newItem);
        //true if success
        bool removeItem(string itemName);
        //return NULL if not found
        Ingredient *getItem(string itemName);
        void printList(int index);
        int getLength();
        ~LinkedList();
};

class HashTable{
    private:
        LinkedList *array;
        int length;

    public:
        HashTable(int tableLength);
        int hash(string itemName);
        void insertItem(Ingredient *newItem);
        bool removeItem(string itemName);
        //return NULL if not found
        Ingredient * getItemByKey(string itemName);
        void printTable();
        //histogram version of printing
        void printHistogram();
        int getLength();
        int getNumberOfItems();
        ~HashTable();
    };

#endif
