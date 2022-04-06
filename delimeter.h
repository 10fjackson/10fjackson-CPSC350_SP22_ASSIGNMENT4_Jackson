#ifndef DELIMETER_H
#define DELIMETER_H
#include <iostream>
#include "Genstack.h"
using namespace std;


class Delimeter{
    public:
        //constrcutors
        Delimeter();
        ~Delimeter();
        //auxilary functions
        void delimeterMatching(string text);
        char opposite(char c);



    private:
        GenStack<char> *myStack;
        int size;
        


};

#endif
