#include "LosslessCompressor.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//constant for maximum amount of unique words
const int MAX_SIZE = 999;

//definition for constructor
LosslessCompressor::LosslessCompressor(){};

//definition for Compress() function
void LosslessCompressor::Compress(ifstream& inFile) {

    //variable of individual words within input file
    string word;

    //read a word from the input file
    while (inFile >> word){

        //check array for unique words
        for (int i = 0; i <= MAX_SIZE; i++) {
            if (word == List[i]) {
                //if word already on list, stop
                break;
            }
            else if (List[i].empty()) {
                //if empty space, add new word
                List[i] = word;
                break;
            }
            else {
                //if encountering any other words, loop
                continue;
            }
        }
    }
}

//definition for PrintCompressedData() function
void LosslessCompressor::PrintCompressedData(ifstream& inFile, ofstream& outFile) {
    
    //variable for each word in array
    string word;

    //read a word from input file
    while (inFile >> word) {
        
        //check each word in array
        for (int i = 0; i <= MAX_SIZE; i++) {
            if (word == List[i]) {
                //if word matches, write to output file
                outFile << i + 1 << " ";
                break;
            }
            else if (List[i].empty()) {
                //if i is blank, it is probably the end of the array
                break;
            }
            else {
                //if word doesn't match, iterate to next word
                continue;
            }
        }
    }
    
    //formatting
    outFile << endl << endl;

    //print out a list of each word and the associated number used to compress the data
    for (int i = 0; i <= MAX_SIZE; i++) {
        if (List[i].empty()) {
            //if i is blank, it is probably the end of the array
            break;
        }
        else { //print word and it's index location on the array
            outFile << i + 1 << "\t=\t" << List[i] << endl;
        }
    }
}