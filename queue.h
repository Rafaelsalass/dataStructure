#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdio.h>

using namespace std;

template<class t>
class queue{

private:
  int size, end;
  t *v;

public:
  queue(int n);
  int add(t element);
  int remove(t &element);
  void print();
};

template<class t>
queue<t>::queue(int n){
  size = n;
  end = -1;
  v = new t[size];
  if(!v)
    cout << "not enought memory" << endl;
}

template<class t>
int queue<t>::add(t element){
  if (!v) {
    cout << "no enought memory" << endl;
    return -1;
  }
  if (end == size - 1) {
    cout << "queue is full" << endl;
    return 0;
  }
  v[++end] = element;
  return 1;
}

template<class t>
int queue<t>::remove(t &element){
  if (!v) {
    cout << "no enought memory" << endl;
    return -1;
  }
  if (end == -1) {
    cout << "queue is already empty" << endl;
    return 0;
  }

  element = v [0];
  for (int i = 0; i < end; i++) {
    v[i] = v[i + 1];
  }
  end --;
  return 1;
}


template<class t>
void queue<t>::print(){
  for (int i = 0; i < end; i++) {
    cout << v[i] << endl;
  }
}
#endif
