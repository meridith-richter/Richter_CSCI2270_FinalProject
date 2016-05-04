#include "LinkedList.h"

//LinkedList Class implementation
LinkedList::LinkedList(){
    head = new Ingredient;
    head->next = NULL;
    length = 0;
}

// Inserts an item (end of list)
void LinkedList::insertItem(Ingredient *newItem){
    if(!head->next){
        head->next = newItem;
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
        if((temp != head) && (temp->name == itemName)){
            return temp;
        }
        cursor = temp->next;
    }
    return NULL;
}

void LinkedList::printList(int index){
    Ingredient *temp = head;
    Ingredient *cursor = head;
    while(cursor){
        temp = cursor;
        if(temp != head){
            cout<<temp->name<<endl;
        }
        cursor = temp->next;
    }
}

Ingredient *LinkedList::returnHead(int index){
    Ingredient *temp = head;
    Ingredient *cursor = head;
    while(cursor){
        temp = cursor;
        if(temp != head){
            //cout<<temp->name<<endl;
            return temp;
        }
        cursor = temp->next;
    }
}

void LinkedList::histogramPrintList(int index){
    Ingredient *temp = head;
    Ingredient *cursor = head;
    while(cursor){
        temp = cursor;
        if(temp != head){
            cout<<"|"<<temp->name<<" ";
        }
        cursor = temp->next;
    }
}

int LinkedList::getLength(){
    return length;
}

LinkedList::~LinkedList(){
    Ingredient *temp = head;
    Ingredient *cursor = head;
    while(cursor){
        temp = cursor;
        cursor = temp->next;
        if(cursor){
            delete temp;
        }
    }
}

