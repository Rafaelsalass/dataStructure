#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <iostream>
#include <stdlib.h>
#include "node.h"
using namespace std;

template <class t>
class circularQueue{
public:
  int front;
  int end;
  int size;
  t *v;
  circularQueue(int n);
  void insert(t element);
  t remove();
  void deleteQueue();
  t fronQueue();
  bool isEmpty();
  bool isFull();
  int next(int r);
};


template <class t>
circularQueue<t>::circularQueue(int n){
  size = n;
  front = 0;
  end = size - 1;
  v = new t[size];
}

template <class t>
int circularQueue<t>::next(int r){
  int aux;
  aux = (r + 1) % size;
  return aux;
}

template <class t>
bool circularQueue<t>::isEmpty(){
  return front == next(end);
}

template <class t>
bool circularQueue<t>::isFull(){
  return front == next(next(end));
}

template <class t>
t circularQueue<t>::fronQueue(){
  if (!isEmpty()) {
    return v[front];
  }else{
    throw "empty queue";
  }

}

template <class t>
void circularQueue<t>::deleteQueue(){
  front = 0;
  end = size - 1;
}

template <class t>
t circularQueue<t>::remove(){
  if (!isEmpty()) {
    t element = v[front];
    front = next(front);
    return element;
  }else{
    throw "empty queue";
  }
}

template <class t>
void circularQueue<t>::insert(t element){
  if (!isFull()) {
    end = next(end);
    v[end] = element;
  }else{
    throw "full queue";
  }
}





#endif
