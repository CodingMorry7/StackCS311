#ifndef stack_H
#define stack_H

//INSTRUCTION:
//Stack class - header file template (by Yoshii) based on Notes-1
//You must complete the ** parts and then complete stack.cpp
//EMACS HINT:
//  control-S does searches
//  Tab on each line will indent perfectly for C++

// =======================================================
// HW#: HW1P1 stack
// Your name: Chris Morikawa
// Compiler:  g++ 
// File type: headher file stack.h
//=======================================================

//----- Globally setting up the aliases ----------------

const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef int el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
  el_t     el[MAX];       // el is  an array of el_t's
  int      top;           // top is index to the top of stack
  
 public: // prototypes to be used by the client
  // Note that no parameter variables are given
  
  // exception handling classes  
  class Overflow{};   // thrown when the stack overflows
  class Underflow{};  // thrown when the stack underflows
  
  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (pass by ref)
  void pop(el_t&);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: provide variable to receive the top element (pass by ref).
  void topElem(el_t&);
  
  // ** Must add good comments for each function - See Notes1B

  //PURPOSE: checks to see if the stack is empty, or no elements in the stack.
  // PARAMETER: No parameter
  bool isEmpty();
  //PURPOSE: checks to see if the statck is full, or the stack reached its capacity.
  // PARAMETER: No parameter
  bool isFull();
  //PURPOSE: will display all the current elements in the stack without changing the stack.
  //ALGORITHM: Starts at the top of the stack, goes through the
  //stack and outputs each element till it reaches the bottom of the stack.
  //LOCAL VARIABLES: int i
  // PARAMETER: No parameter
  void displayAll();
  //PURPOSE: pops all the elements from the stack til it is empty.
  //ALGORITHM: Goes through the stack and pops each element until the stack is empty.
  // PARAMETER: No parameter
  void clearIt();
  
};  
#endif
// Note: semicolon is needed at the end of the header file

