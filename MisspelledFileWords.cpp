#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/*
Assignment: Program that takes in input file and outputs all the misspelled words in the file (misspelled if word does not appear in dict.txt - provided)
*/

int main() {
    string a[200];
    int i = 0;
    string word;
    bool correct = false;
    ifstream ifile;
    ifile.open("input.txt"); //open the first input file
    if (ifile.fail()){
        cout<<"Input file opening failed"<<endl;
        exit(1); //check if file opened
    }

    while (ifile >> a[i]) {
        i++; //put all the words from the input file into an array of strings
    }
    ifile.close(); //close the input file
    
    for (int x = 0; x<i;x++){
        ifile.open("dict.txt"); //open the dictionary file
        if (ifile.fail()){
            cout<<"Input file opening failed"<<endl;
            exit(1); //check if file opened
        }
        while (ifile >> word){ //set a string equal to each word 
            if (a[x] == word){ //check if the strings from the input file match any words from the dictionary
                correct = true;
            }
        }
        ifile.close(); //close the dictionary file
        if (correct == false){ 
            cout<<a[x]<<endl; //if the string did not match any words from the dictionary then print it out
        }
        correct = false;
    }
    
    return 0;
}