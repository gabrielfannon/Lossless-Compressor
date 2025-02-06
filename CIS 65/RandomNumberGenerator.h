#pragma once
#include <iostream>


//CLASS
class random
{
private:

public:
    void random_number(int& reference, int max_range){
        srand(unsigned int(time(NULL))); //seed random number generator
        reference = rand() % max_range; //writes random number
    };
};