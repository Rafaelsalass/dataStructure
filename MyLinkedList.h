#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
#include <stdlib.h>
#include "node.h"
using namespace std;

template <class t>
class MyLinkedList{
private:
  node<t>* head;

public:
  MyLinkedList();
  void addHead(t element);
  void addTail(t element);
  node<t>* lastNode();
  node<t>* search(t element);
  void removeHead();
  void removeTail();
  void orderedPush(t element);
  void print();
  bool isEmpty();
};

template <class t>
MyLinkedList<t>::MyLinkedList(){
  head = NULL;
}

template <class t>
bool MyLinkedList<t>::isEmpty(){
  return (head == NULL)? true : false;
}

template <class t>
void MyLinkedList<t>::addHead(t element){
  node<t>* newNode;
  newNode = new node<t>;
  newNode->setInfo(element);
  newNode->setNext(head);
  head = newNode;
}

template <class t>
node<t>* MyLinkedList<t>::lastNode(){
  node<t>* p = head;
  if (!p) {
    cout << "List is empty" << endl;
    return NULL;
  }
  while (p->getnext() != NULL) {
    p = p->getnext();
  }
  return p;
}

template <class t>
void MyLinkedList<t>::addTail(t element){
  node<t>* last = this->lastNode();
  node<t>* newNode;
  newNode = new node<t>();
  newNode->setInfo(element);
  last->setNext(newNode);
}

template <class t>
void MyLinkedList<t>::removeHead(){
  node<t>* aux = head;
  if (!aux) {
    cout << "List is empty" << endl;
    return;
  }
  head = head->getnext();
  delete aux;
}

template <class t>
void MyLinkedList<t>::removeTail(){
  node<t>* aux;
  node<t>* p = head;
  if (!p) {
    cout << "List is empty" << endl;
    return;
  }
  if(head->getnext() == NULL){
    head = NULL;
    return;
  }
  while (p->getnext()->getnext() != NULL) {
    p = p->getnext();
  }
  aux = p->getnext();
  p->setNext(NULL);
  delete aux;
}

template <class t>
node<t>* MyLinkedList<t>::search(t element){
  node<t>* p;

  if (!p) {
    cout << "List is empty" << endl;
    return NULL;
  }
  for(p = head; p != NULL; p = p->getnext()){
    if (p->getInfo() == element) {
      return p;
    }
  }
  return NULL;
}

template <class t>
void MyLinkedList<t>::orderedPush(t element){
  node<t>* newNode = new node<t>(element);
  if (!head) {
    head = newNode;
  }
  else if (head->getInfo() > element) {
    newNode->setNext(head);
    head = newNode;
  }
  else{
    node<t> *previous, *p;
    previous = p = head;
    while (p->getnext() != NULL && element > p->getInfo()) {
      previous = p;
      p = p->getnext();
    }
    if (element > p->getInfo()) {
      previous = p;
    }

    newNode->setNext(previous->getnext());
    previous->setNext(newNode);
  }
}

template <class t>
void MyLinkedList<t>::print(){
  node<t>* p;
  p = head;
  if (!p) {
    cout << "List is empty" << endl;
    return;
  }
  cout << endl << endl;
  for(p = head; p != NULL; p = p->getnext()){
    cout << p->getInfo() << endl;
  }
}
#endif
