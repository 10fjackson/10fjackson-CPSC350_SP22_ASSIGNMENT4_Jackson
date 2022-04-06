#include <fstream> // for file-access
#include "Delimeter.h"
#include <iostream>

using namespace std; 

int main(int argc, char* argv[])
{ 
    string text = "";
    if (argc > 1) {
        cout << "argv[1] = " << argv[1] << endl; 
    } else {
        cout << "No file name entered";
        return -1;
    } // takes command line argument
    ifstream infile(argv[1]); //open the file
    
    if (infile.is_open() && infile.good()) { // checks if file is good
        //cout << "File is now open!\nContains:\n";
        cout << "File is now open!"<<endl;
        string line = "";
        while (getline(infile, line)){
            text += line;
            //text += '\n';
        }
        //cout<< text <<endl;
    } else {
        cout << "Failed to open file"<<endl;
    }
    Delimeter *d = new Delimeter();
    d->delimeterMatching(text);
    delete d;

    return 0;
}