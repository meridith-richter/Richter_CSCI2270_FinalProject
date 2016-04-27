#include "HashTable.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

void printMenu(){
    cout<<"**************MENU**************"<<endl;
    cout<<"1. Analyze cosmetic product ingredients"<<endl;
    cout<<"2. Instructions"<<endl;
    cout<<"3. Quit"<<endl;
}

int main(){
    int result;

    printMenu();

    //initialize ingredient list
    HashTable ht(26);

    while(result != 3){
        cin>>result;

        //search through pasted ingredients to find troublesome ones
        if(result == 1){
            cin.ignore();
            cout<<"Enter the name of the cosmetic product:"<<endl;
            string prodName;
            getline(cin, prodName);
            cout<<"Please enter the filename here:"<<endl;
            string filename;
            getline(cin, filename);
            ifstream infile(filename.c_str());

            //file open check
            if(!infile.is_open()){
                cout<<"File did not successfully open"<<endl;
                main();
            }
            //do the analysis
            else{
                cin.ignore();
                while(!infile.eof()){
                    string line;
                    getline(infile, line, ',');
                    //cout<<line<<endl;
                }
                printMenu();
            }
        }
        //instructions
        if(result == 2){
            cin.ignore();
            cout<<endl;
            cout<<"**********INSTRUCTIONS**********"<<endl;
            cout<<"Copy/paste the ingredient list of the cosmetic\nproduct of interest into a text file.\nDelete the period at the end of the list,\nbut leave all commas. Save that file in the same\nfolder as this program and remember its name.\nWhen prompted, enter that name with its .txt extension."<<endl;
            cout<<endl;
            printMenu();
        }
        //quit
        else if(result == 3){
            cin.ignore();
            cout<<"Thank you, goodbye!"<<endl;
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
