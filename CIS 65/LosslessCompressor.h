#pragma once

#include <iostream>
#include <string>
using namespace std;

class LosslessCompressor{
private:

    //maximum number of unique words the compressor can store
    static const int MAX_SIZE = 999;

    //array to contain unique words from input file
    string List[MAX_SIZE];

public:
    //Constructor
    LosslessCompressor();

    /*************************************************************************
    * Function Name: Compress()
    * Parameters: An open text file
    * Return Value: void
    * Purpose: To add all unique words from an open text file to an array
    *************************************************************************/
    void Compress(ifstream& inFile);

    /*************************************************************************
    * Function Name: PrintCompressedData()
    * Parameters: An open input text file, an open output text file
    * Return Value: void
    * Purpose: To read each word in an input file and write to an output file
    * it's numerical companion.
    *************************************************************************/
    void PrintCompressedData(ifstream& inFile, ofstream& outFile);
};
