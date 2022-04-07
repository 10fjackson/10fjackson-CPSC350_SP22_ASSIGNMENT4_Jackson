#include "Delimeter.h"
#include <iostream>

Delimeter::Delimeter(){
    myStack = new GenStack<char>();
    size = 0;
}

Delimeter::~Delimeter(){

}

void Delimeter::delimeterMatching(string text){
    size = text.length();
    cout<<size<<endl;
    bool outcome = true; // boolean for wether there are errors
    for(int i = 0; i < size; ++i){
        //look for an opening delimeter
        if(text[i] == '{' || text[i] == '(' || text[i] == '['){
            myStack->push(text[i]);
            //cout<<"pushed"<<endl;
        }
        //check for a closed delimeter
        else if(text[i] == '}' || text[i] == ')' || text[i] == ']'){
            char del = myStack->pop();
            //cout<<"popped"<<endl;
            if(del != opposite(text[i])){
                //if the popped item doesnt have a closing delimeter
                cout<<"Expected " << opposite(del) << " on line: " << __LINE__ << endl;
                outcome = false;
                break;
            }
        }else{
            //if nothing is wrong
            outcome = true;
        }
    }
    if(!myStack->isEmpty()){
        cout<<"Missing a "<<myStack->peek()<<" delimeter"<<endl;
        outcome = false;
    }
    // check for line is \r\n
    if(outcome){
        cout<<"All delimeters in place, Good Job!"<<endl;
    }
}
//returns the opposite delimeter
char Delimeter::opposite(char c){
    if(c == '{'){
        return '}';
    }
    else if(c == '('){
        return ')';
    }
    else if(c == '['){
        return ']';
    }
    else if(c == '}'){
        return '{';
    }
    else if(c == ')'){
        return '(';
    }
    else if(c == ']'){
        return '[';
    }
    else{
        return c;
    }
}

