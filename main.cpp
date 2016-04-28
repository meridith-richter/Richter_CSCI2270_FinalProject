#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "HashTable.h"
#include <limits.h>

//Meridith Richter
//Project: CSCI 2270
//Prof. Hoenigman
//April 27, 2016

using namespace std;

void printMenu(){
    cout<<"**************MENU**************"<<endl;
    cout<<"1. Analyze cosmetic product ingredients"<<endl;
    cout<<"2. Instructions"<<endl;
    cout<<"3. Print histogram of your product's ingredient hash table"<<endl;
    cout<<"4. Print histogram of bad ingredient hash table"<<endl;
    cout<<"5. Print list of bad ingredients in compared list"<<endl;
    cout<<"6. Quit"<<endl;
}

int main(int argc, char *argv[]){

    int result;

    printMenu();

    //check for first line in, without space in front of ingredient
    int check = 0;

    //build user file hash table
    ifstream infile(argv[1]);

    //initialize ingredient list
    HashTable ht(26);

    //file open check
    if(!infile.is_open()){
        cout<<"Your file did not successfully open"<<endl;
    }
    else{
        while(!infile.eof()){
            string line;
            getline(infile, line, ',');
            Ingredient *newIngredient = new Ingredient();
            //if first ingredient in, add space to make it even with others
            if(check == 0){
                string space2add = " ";
                line.insert(0, space2add);
                newIngredient->name = line;
                newIngredient->classification = line[1];
                ht.insertItem(newIngredient);
            }
            //if rest of ingredients, no adjustment
            else{
                newIngredient->name = line;
                newIngredient->classification = line[1];
                ht.insertItem(newIngredient);
                //cout<<line<<endl;
            }
            check++;
        }

        //build internal bad ingredients file hash table
        ifstream myfile("listFile.txt");

        //initialize ingredient list
        HashTable compHT(26);

        //reset check
        check = 0;

        //file open check
        if(!myfile.is_open()){
            cout<<"File to compare did not successfully open"<<endl;
        }
        else{
            while(!myfile.eof()){
                string line;
                getline(myfile, line, ',');
                Ingredient *newIngredient = new Ingredient();
                //if first ingredient in, add space to make it even with others
                if(check == 0){
                    string space2add = " ";
                    line.insert(0, space2add);
                    newIngredient->name = line;
                    newIngredient->classification = line[1];
                    compHT.insertItem(newIngredient);
                }
                //if rest of ingredients, no adjustment
                else{
                    newIngredient->name = line;
                    newIngredient->classification = line[1];
                    compHT.insertItem(newIngredient);
                    //cout<<line<<endl;
                }
                check++;
            }


            //main program implementation
            while(result != 6){

                cin>>result;

                //search through pasted ingredients to find troublesome ones
                if(result == 1){
                    cin.ignore();
                    //call compare function for each item
                    for(int i = 0; i < 26; i++){
                       Ingredient *item = ht.returnItem(i + 1);
                       cout<<item->name<<endl;
                    }

                    printMenu();
                }
                //instructions
                if(result == 2){
                    cin.ignore();
                    cout<<endl;
                    cout<<"**********INSTRUCTIONS**********"<<endl;
                    cout<<"Copy/paste the ingredient list of the cosmetic\nproduct of interest into a text file.\nDelete the period at the end of the list,\nand any other additional words/periods which are not ingredients or commas\nbut leave all commas. Save that file in the same\nfolder as this program and remember its name.\nAs a command line argument, enter that name with its .txt extension."<<endl;
                    cout<<endl;
                    printMenu();
                }
                //print histogram of ingredient list
                else if(result == 3){
                    cin.ignore();
                    ht.printHistogram();
                    printMenu();
                }
                //print histogram of bad ingredient list
                else if(result == 4){
                    cin.ignore();
                    compHT.printHistogram();
                    printMenu();
                }
                //print list of bad ingredients
                                //print histogram of bad ingredient list
                else if(result == 5){
                    cin.ignore();
                    cout<<"Bad Ingredient Table Contains:"<<endl;
                    compHT.printTable();
                    printMenu();
                }
                //quit
                else if(result == 6){
                    cin.ignore();
                    cout<<"Thank you, goodbye!"<<endl;
                    ht.~HashTable();
                    compHT.~HashTable();
                    exit(0);
                }
                //catch all
                else{
                    cin.ignore();
                    cout<<"Please enter a valid number option"<<endl;
                    printMenu();
                }
            }
        }
    }
}
