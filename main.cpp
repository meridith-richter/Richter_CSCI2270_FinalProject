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
    cout<<"1. Instructions"<<endl;
    cout<<"2. Analyze your cosmetic product ingredients"<<endl;
    cout<<"3. Print list of submitted product ingredients"<<endl;
    cout<<"4. Print list of comparative bad ingredients"<<endl;
    cout<<"5. Quit"<<endl;
}

//keep track of indexes used
bool htboolArr[26] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
bool compHTboolArr[26] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

int main(int argc, char *argv[]){
    //for user in
    int result;

    //start menu
    printMenu();

    //check for first line in, without space in front of ingredient
    int check = 0;

    //build user file hash table
    ifstream infile(argv[1]);

    //initialize user-supplied ingredient list
    HashTable ht(26);

    //file open check
    if(!infile.is_open()){
        cout<<"Your file "<<argv[1]<<" did not successfully open"<<endl;
    }
    else{
        while(!infile.eof()){
            string line;
            getline(infile, line, ',');
            Ingredient *newIngredient = new Ingredient();
            int boolResult2;
            //if first ingredient in, add space to make it even with others
            if(check == 0){
                string space2add = " ";
                line.insert(0, space2add);
                newIngredient->name = line;
                newIngredient->classification = line[1];
                int boolResult2 = ht.hash(line);
                htboolArr[boolResult2] = true;
                ht.insertItem(newIngredient);
            }
            //if rest of ingredients, no adjustment
            else{
                newIngredient->name = line;
                newIngredient->classification = line[1];
                boolResult2 = ht.hash(line);
                htboolArr[boolResult2] = true;
                ht.insertItem(newIngredient);
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
                int boolResult;
                if(check == 0){
                    string space2add = " ";
                    line.insert(0, space2add);
                    newIngredient->name = line;
                    newIngredient->classification = line[1];
                    boolResult = ht.hash(line);
                    compHTboolArr[boolResult] = true;
                    compHT.insertItem(newIngredient);
                }
                //if rest of ingredients, no adjustment
                else{
                    newIngredient->name = line;
                    newIngredient->classification = line[1];
                    boolResult = ht.hash(line);
                    compHTboolArr[boolResult] = true;
                    compHT.insertItem(newIngredient);
                }
                check++;
            }


            //main program implementation
            while(result != 5){

                cin>>result;

                //instructions
                if(result == 1){
                    cin.ignore();
                    cout<<endl;
                    cout<<"**********INSTRUCTIONS**********"<<endl;
                    cout<<"Copy/paste the ingredient list of the cosmetic\nproduct of interest into a text file.\nDelete the period at the end of the list,\nand any other additional words/periods which are not ingredients or commas\nbut leave all commas. Save that file in the same\nfolder as this program and remember its name.\nAs a command line argument, enter that name with its .txt extension."<<endl;
                    cout<<endl;
                    string getridofcin;
                    printMenu();
                }
                //search through submitted ingredients to find troublesome ones, compare to bad ingredient list
                if(result == 2){
                    cin.ignore();
                    //ht.printHistogram();
                    //compHT.printHistogram();
                    for(int i = 0; i < 26; i++){
                        if(htboolArr[i] == true && compHTboolArr[i] == true){
                            Ingredient *htHead = ht.getList(i);
                            //cout<<"head for your list"<<htHead->name<<endl;
                            Ingredient *compHead = compHT.getList(i);
                            //cout<<"head for bad list"<<compHead->name<<endl;
                            ht.compare(htHead, compHead);
                        }
                    }
                    printMenu();

                }
                else if(result == 3){
                    cin.ignore();
                    cout<<"Submitted Ingredient Table Contains:"<<endl;
                    ht.printTable();
                    cout<<"Table Contains "<<ht.getNumberOfItems()<<" ingredients."<<endl;
                    printMenu();
                }
                //print list of bad ingredients
                else if(result == 4){
                    cin.ignore();
                    cout<<"Bad Ingredient Table Contains:"<<endl;
                    compHT.printTable();
                    cout<<"Table Contains "<<compHT.getNumberOfItems()<<" ingredients."<<endl;
                    printMenu();
                }
                //quit
                else if(result == 5){
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
