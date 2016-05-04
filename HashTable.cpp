#include <iostream>
#include "LinkedList.h"
#include "HashTable.h"

using namespace std;

//int for counter check
int index = 0;

//additional index
int i = 0;

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

//dictates hash value, will be organized alphabetically
int HashTable::hash(string itemName){
    int value = 0;
    for(int i = 0; i < 26; i++){
        if(itemName[1] == UPalphaArr[i] || itemName[1] == LOWalphaArr[i]){
            value = i;
        }
    }
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
        array[i].printList(i);
    }
}

Ingredient *HashTable::getList(int index){
    Ingredient *newHead = array[index].returnHead(index);
    return newHead;
}

//function to compare each item of the user's file which is in the same alphabetical category
//of the bad ingredients list to those ingredients with the same alphabetical classification
void HashTable::compare(Ingredient *userHead, Ingredient *fileHead){
    Ingredient *temp = userHead;
    Ingredient *compTemp = fileHead;
    //cout<<temp->name<<endl;
    while(temp != NULL){
        //cout<<temp->name<<endl;
        compTemp = fileHead;
        while(compTemp != NULL){
            //cout<<compTemp->name<<endl;
            //cout<<"Comparing..."<<temp->name<<" to"<<compTemp->name<<endl;
            if(compTemp->name == temp->name){
                cout<<"MATCH: WARNING contains"<<compTemp->name<<endl;
                strArr[i] = compTemp->name;
                i++;
            }
            compTemp = compTemp->next;
        }
        temp = temp->next;
    }
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

void HashTable::setUpstrArr(){
    //initialize string array
    for(int j = 0; j < 30; j++){
        strArr[j] = "-1";
    }
}

HashTable::~HashTable(){
    delete []array;
}


