#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>

using namespace std;

class GenStack{
  public:
    GenStack(); // default
    GenStack(int maxSize); // overloaded
    ~GenStack(); //destructor

    //core functions
    void push(char data);
    char pop();
    char peek(); //aka top()

    //aux functions
    bool isEmpty();
    bool isFull();
    int getSize();

  private:
    char *myStack;
    int top();
    int mSize();

};
template <typename T>
GenStack<T>::GenStack(){
  mSize = 64;//default size
  top = -1;
  myStack = new T[mSize];
} // default
template <typename T>
GenStack<T>::GenStack(int maxSize){
  mSize = maxSize;//parameter of max size
  top = -1;
  myStack = new T[mSize];
} // overloaded

template <typename T>
GenStack<T>::~GenStack(){
  delete[] myStack;
} //destructor
//core functions

template <typename T>
void GenStack<T>::push(T data){
  //check if stack is is full
  if(isFull()){
    cout<< "stack is resizing"<<endl;
    T *temp = new T[2*mSize];
    for(int i = 0; i< mSize;++i){
      temp[i] = myStack[i];
    }
    mSize *= 2;
    delete[] myStack;
    myStack = temp;
  }
  myStack[++top] = data;
}

template <typename T>
char GenStack<T>::pop(){
  //make sure stack is not empty before proceeding
  if(isEmpty()){
    throw runtime_error("Stack is empty, nothing to pop");
  }

  return myStack[top--];
}

template <typename T>
char GenStack<T>::peek(){
  //make sure stack is not empty before proceeding
  if(isEmpty()){
    throw runtime_error("Stack is empty, nothing to peek");
  }

  return myStack[top];
} //aka top()

template <typename T>
//aux functions
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

template <typename T>
bool GenStack<T>::isFull(){
  return (top == mSize-1);
}

template <typename T>
int GenStack<T>::getSize(){
  return top + 1;
}

#endif