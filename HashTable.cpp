#include <iostream>
#include "HashTable.h"

using namespace std;

#include "HashTable.h"

//LinkedList Class implementation
LinkedList::LinkedList(){
    head = new Ingredient;
    head->next = NULL;
    length = 0;
}

// Inserts an item (end of list)
void LinkedList::insertItem(Ingredient *newItem){
    if(!head -> next){
        head -> next = newItem;
        length++;
        return;
    }
    Ingredient *temp = head;
    Ingredient *cursor = head;
    while(cursor){
        temp = cursor;
        cursor = temp->next;
    }
    temp->next = newItem;
    newItem->next = NULL;
    length++;
}

bool LinkedList::removeItem(string itemName)
{
    if(!head->next){
        return false;
    }
    Ingredient *temp = head;
    Ingredient *cursor = head;
    while(cursor){
        if(cursor->name == itemName){
            temp->next = cursor->next;
            delete cursor;
            length--;
            return true;
        }
        temp = cursor;
        cursor = temp->next;
    }
    return false;
}

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
Ingredient *LinkedList::getItem(string itemName){
    Ingredient *temp = head;
    Ingredient *cursor = head;
    while(cursor){
        temp = cursor;
        if((temp != head) && (temp->name == itemName))
            return temp;
        cursor = temp->next;
    }
    return NULL;
}

void LinkedList::printList(int index){
    if(length == 0){
        //cout <<"empty"<<endl;
        return;
    }
    Ingredient *temp = head;
    Ingredient *cursor = head;
    while(cursor){
        temp = cursor;
        if(temp != head){
            cout<<index<<":";
            cout <<temp->name<<":";
            if(temp-> next){
                cout <<endl;
            }
        }
        cursor = temp->next;
    }
    cout<<endl;
}

int LinkedList::getLength(){
    return length;
}

LinkedList::~LinkedList(){
    Ingredient * temp = head;
    Ingredient * cursor = head;
    while (cursor){
        temp = cursor;
        cursor = temp->next;
        if(cursor){
            delete temp;
        }
    }
}

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
    for(int i = 0; i < itemName.length(); i++){
        value += itemName[i];
    }
    return value % 26;
}
void HashTable::insertItem(Ingredient *newItem){
    int index = hash(newItem->name);
    array[index].insertItem(newItem);
}

//true if success
bool HashTable::removeItem(string itemName){
    int index = hash(itemName);
    return array[index].removeItem(itemName);
}

Ingredient *HashTable::getItemByKey(string itemName){
    int index = hash(itemName);
    return array[index].getItem(itemName);
}


void HashTable::printTable(){
    //cout << "\n\nHash Table:\n";
    for(int i = 0; i < length; i++){
        //cout<< i + 1 << ":";
        array[i].printList(i + 1);
    }
}

//histogram
void HashTable::printHistogram(){
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfItems() << " Items total\n";
    for(int i = 0; i < length; i++){
        cout << i + 1 << ":\t";
        for(int j = 0; j < array[i].getLength(); j++){
            cout << " X";
        }
        cout << "\n";
    }
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
