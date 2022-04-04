#include <fstream> // for file-access
#include "GenStack.h"
#include <iostream>

using namespace std; 

int main(int argc, char* argv[])
{ 
    string text = "";
    if (argc > 1) {
        cout << "argv[1] = " << argv[1] << endl; 
    } else {
        cout << "No file name entered. Exiting...";
        return -1;
    }
    ifstream infile(argv[1]); //open the file
    
    if (infile.is_open() && infile.good()) {
        cout << "File is now open!\nContains:\n";
        string line = "";
        while (getline(infile, line)){
            text += line;
            text += '\n';
        }
        
    } else {
        cout << "Failed to open file..";
    }

    
    return 0;
}