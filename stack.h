#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <stdio.h>

using namespace std;

template <class t>
class stack{

private:
  int size;
  t *v;
  int top;

public:
  stack(int n);
  int add(t element);
  int remove(t &element);
  void print();

};

template <class t>
stack<t>::stack(int n){
  size = n;
  top = -1;
  v = new t[size];
  if(!v)
    cout << "not enought memory" << endl;

}

template <class t>
int stack<t>::add(t element){
  if (!v) {
    cout << "no enought memory" << endl;
    return -1;
  }
  if (top == size - 1) {
    cout << "stack is full" << endl;
    return 0;
  }

  v[++top] = element;
  return 1;
}

template <class t>
int stack<t>::remove(t &element){
  if (!v) {
    cout << "no enought memory" << endl;
    return -1;
  }
  if (top == -1) {
    cout << "stack is already empty" << endl;
    return 0;
  }
  element = v [top];
  top --;
  return 1;
}

template <class t>
void stack<t>::print(){
  for (int i = 0; i < top; i++) {
    cout << v[i] << endl;
  }
}
#endif
