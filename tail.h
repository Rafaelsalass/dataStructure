#ifndef TAIL_H
#define TAIL_H
#include "linearStructure.h"

template <class t>
class tail : public linearStructure<t>{
public:
  tail(int size);
  virtual int deleteElement();
  virtual int add(t element);
  void print();
};

template <class t>
tail<t>::tail(int size):linearStructure<t>(size){}

template <class t>
int tail<t>::deleteElement(){
  linearStructure<t>::deleteElement();
  if (linearStructure<t>::topend == -1){
    cout << "The tail is already empty" << endl;
    return 0;
  }
  for (int i = 0; i < linearStructure<t>::topend; i++) {
    linearStructure<t>::v[linearStructure<t>::topend] = linearStructure<t>::v[linearStructure<t>::topend + 1];
  }
  linearStructure<t>::topend --;
  return 1;
}

template <class t>
int tail<t>::add(t element){
  linearStructure<t>::add(element);
  if(linearStructure<t>::topend == linearStructure<t>::size - 1){
    cout << "The tail is full" << endl;
    return 0;
  }
  linearStructure<t>::v[linearStructure<t>::topend + 1] = element;
  linearStructure<t>::topend ++;
  return 1;
}

template <class t>
void tail<t>::print(){
  linearStructure<t>::print();
}

#endif
