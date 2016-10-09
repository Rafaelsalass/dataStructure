#ifndef STACK_H
#define STACK_H
#include "linearStructure.h"

template <class t>
class stack : private linearStructure<t>{
public:
  stack(int size);
  virtual int deleteElement();
  virtual int add(t element);
  void print();
};

template <class t>
stack<t>::stack(int size):linearStructure<t>(size){}

template <class t>
int stack<t>::deleteElement(){
  linearStructure<t>::deleteElement();
  if(linearStructure<t>::topend == -1){
    cout << "The stack is already empty" << endl;
    return 0;
  }
  linearStructure<t>::topend --;
  return 1;
}

template <class t>
int stack<t>::add(t element){
  linearStructure<t>::add(element);
  if (linearStructure<t>::topend == linearStructure<t>::size - 1){
    cout << "The stack is full" << endl;
    return 0;
    }
    linearStructure<t>::v[++linearStructure<t>::topend] = element;
}

template <class t>
void stack<t>::print(){
  linearStructure<t>::print();
}

#endif
