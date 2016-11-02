#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

#include <iostream>
#include <stdio.h>
#include "node.h"

using namespace std;

template <class t>
class dynamicQueue{

private:
  node<t>* head;
  node<t>* tail;
public:
  dynamicQueue();
  void add(t element);
  void removeElement(t &element);
  void print();
  bool isEmpty();
};

template <class t>
dynamicQueue<t>::dynamicQueue(){
  head = tail = NULL;
}

template <class t>
bool dynamicQueue<t>::isEmpty(){
  return (head == NULL)? true : false;
}

template <class t>
void dynamicQueue<t>::add(t element){
  node<t>* newNode = new node<t>(element);
  if (!head) {
    head = tail = newNode;
    return;
  }
  tail->setNext(newNode);
  tail = newNode;
}

template <class t>
void dynamicQueue<t>::removeElement(t &element){
  node<t>* p;
  if(!head){
    cout << "queue is empty" << endl;
    return;
  }else if (head->getnext() == NULL) {
    element = head->getInfo();
    head = tail = NULL;
    return;
  }
  element = head->getInfo();
  p = head->getnext();
  delete head;
  head = p;
}

template <class t>
void dynamicQueue<t>::print(){
  if(!head){
    cout << "queue is empty" << endl;
    return;
  }
  cout << endl << endl;
  node<t>* p = head;
  while (p) {
    cout << p->getInfo() << endl;
    p = p->getnext();
  }
}

#endif
