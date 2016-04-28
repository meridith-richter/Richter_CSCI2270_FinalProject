#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>
#include <string>
#include "LinkedList.h"

using namespace std;

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
        Ingredient * getItemByName(string itemName);
        void printTable();
        Ingredient *returnItem(int index);
        //histogram version of printing
        void printHistogram();
        int getLength();
        int getNumberOfItems();
        ~HashTable();
    };

#endif
