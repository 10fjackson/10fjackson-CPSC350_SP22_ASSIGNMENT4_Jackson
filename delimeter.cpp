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
    bool outcome = true;
    for(int i = 0; i < size; ++i){
        if(text[i] == '{' || text[i] == '(' || text[i] == '['){
            myStack->push(text[i]);
            //cout<<"pushed"<<endl;
        }
        else if(text[i] == '}' || text[i] == ')' || text[i] == ']'){
            char del = myStack->pop();
            //cout<<"popped"<<endl;
            if(del != opposite(text[i])){
                cout<<"Expected " << opposite(del) << " on line: " << __LINE__ << endl;
                outcome = false;
                break;
            }
        }else{
            outcome = true;
        }
    }
    if(!myStack->isEmpty()){
        cout<<"Missing a "<<myStack->peek()<<" delimeter"<<endl;
        outcome = false;
    }
    // \r\n
    if(outcome){
        cout<<"All delimeters in place, Good Job!"<<endl;
    }
}

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

