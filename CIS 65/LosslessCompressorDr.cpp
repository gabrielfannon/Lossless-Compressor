/*************************************************************************
* Program Name: Lossless Compressor
* Created Date: 02/01/2025
* Created By: Gabriel Stomberg-Fannon
* Purpose: To read an input file and 'compress' each unique word into
* an array. Then write compressed data to an output file with a key of
* each word and its' associated number.
* Acknowledgements:
*************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "LosslessCompressor.h"
using namespace std;

/*************************************************************************
* Function Name: main()
* Parameters: None
* Return Value: int
* Purpose: To open desired input and output files and appropriately send 
* them to the lossless compressor.
*************************************************************************/
int main()
{
    try {

	   ifstream inFile;       // file containing operations
	   ofstream outFile;      // file containing output
	   string inFileName = "InFile3.txt";     // input file external name
	   string outFileName = "MyOutFile.txt";    // output file external name
	   LosslessCompressor Compressor; //object of our class

	   inFile.open(inFileName); //open input file

	   Compressor.Compress(inFile); //send input file to compressor

	   inFile.close(); //close input file to refresh cursor location
	   inFile.open(inFileName); //re-open
    	   outFile.open(outFileName); //open output file to write compression data to

	   Compressor.PrintCompressedData(inFile, outFile); //send input file and output file to print function

	   inFile.close(); //close files
	   outFile.close();

    }
    catch (exception& e) { //buckshot error handling
	   cerr << e.what() << endl;
    }

    //Program is done
    return 0;
}