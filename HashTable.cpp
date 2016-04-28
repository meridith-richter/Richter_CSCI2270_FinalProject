#include <iostream>
#include "LinkedList.h"


using namespace std;

//alphabet arrays for classification
char UPalphaArr[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char LOWalphaArr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//HashTable class implementation
HashTable::HashTable(int tableLength){
    if(tableLength <= 0){
       tableLength = 10;
    }
    array = new LinkedList[tableLength];
    length = tableLength;
}

//dictates hash value
int HashTable::hash(string itemName){
    int value = 0;
    for(int i = 0; i < 26; i++){
        if(itemName[1] == UPalphaArr[i] || itemName[1] == LOWalphaArr[i]){
            value = i + 1;
        }
    }
    //cout<<itemName<<" ";
    //cout<<value<<" ";
    return value;
}
void HashTable::insertItem(Ingredient *newItem){
    int index = hash(newItem->name);
    //cout<<newItem->classification<<endl;
    array[index].insertItem(newItem);
}

//true if success
bool HashTable::removeItem(string itemName){
    int index = hash(itemName);
    return array[index].removeItem(itemName);
}

Ingredient *HashTable::getItemByName(string itemName){
    int index = hash(itemName);
    return array[index].getItem(itemName);
}

void HashTable::printTable(){
    for(int i = 0; i < length; i++){
        array[i].printList(i + 1);
    }
}

Ingredient *HashTable::returnItem(int index){
    string name = array[index].returnHead();
    Ingredient *item = getItemByName(name);
    return item;
}

//histogram
void HashTable::printHistogram(){
    cout<<endl;
    cout<<"Table Contains ";
    cout<<getNumberOfItems()<<" Items:"<<endl;
    for(int i = 0; i < length; i++){
        cout<<i + 1<<": ";
        array[i].histogramPrintList(i);
        cout<<endl;
    }
    cout<<endl;
}

int HashTable::getLength(){
    return length;
}

int HashTable::getNumberOfItems(){
    int itemCount = 0;
    for(int i = 0; i < length; i++){
        itemCount += array[i].getLength();
    }
    return itemCount;
}

HashTable::~HashTable(){
    delete []array;
}
