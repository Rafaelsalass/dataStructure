#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "node.h"

template <class t>
class doubleLinkedList{
private:
  node<t>* head;
  node<t>* tail;

public:
  doubleLinkedList();
  void addHead(t element);
  void addTail(t element);
  void removeHead(t &element);
  void removeTail(t &element);
  void orderedPush(t element);
  void fowardPrint();
  void reversePrint();
  node<t>* getHead();
  bool isEmpty();
};

template <class t>
doubleLinkedList<t>::doubleLinkedList(){
  head = tail = NULL;
}

template <class t>
node<t>* doubleLinkedList<t>::getHead(){
  return head;
}

template <class t>
bool doubleLinkedList<t>::isEmpty(){
  return (head == NULL)? true : false;
}

template <class t>
void doubleLinkedList<t>::addHead(t element){
  node<t>* newNode = new node<t>(element);
  if (!head) {
    head = tail = newNode;
    return;
  }
  head->setPrevious(newNode);
  newNode->setNext(head);
  head = newNode;
}

template <class t>
void doubleLinkedList<t>::addTail(t element){
  node<t>* newNode = new node<t>(element);
  if (!tail) {
    head = tail = newNode;
    return;
  }
  tail->setNext(newNode);
  newNode->setPrevious(tail);
  tail = newNode;
}

template <class t>
void doubleLinkedList<t>::removeHead(t &element){
  node<t>* p;
  if(!head){
    cout << "double list is empty" << endl;
    return;
  }else if (head->getnext() == NULL) {
    element = head->getInfo();
    head = tail = NULL;
    return;
  }
  element = head->getInfo();
  p = head->getnext();
  p->setPrevious(NULL);
  delete head;
  head = p;
}

template <class t>
void doubleLinkedList<t>::removeTail(t &element){
  node<t>* p;
  if(!tail){
    cout << "double list is empty" << endl;
    return;
  }else if (tail->getPrevious() == NULL) {
    element = tail->getInfo();
    head = tail = NULL;
    return;
  }
  element = tail->getInfo();
  p = tail->getPrevious();
  p->setNext(NULL);
  delete tail;
  tail = p;
}

template <class t>
void doubleLinkedList<t>::orderedPush(t element){
  node<t>* newNode = new node<t>(element);
  node<t>* previous;
  node<t>* next;
  if(this->isEmpty()){
    head = tail = newNode;
    return;
  }else if(element < head->getInfo()){
    this->addHead(element);
    return;
  }else if(element > tail->getInfo()){
    this->addTail(element);
    return;
  }
  next = head->getnext();
  while (element > next->getInfo()) {
    next = next->getnext();
  }
  previous = next->getPrevious();
  previous->setNext(newNode);
  newNode->setPrevious(previous);
  newNode->setNext(next);
  next->setPrevious(newNode);
}

template <class t>
void doubleLinkedList<t>::fowardPrint(){
  node<t>* p;
  if(!head){
    cout << "double list is empty" << endl;
    return;
  }
  cout << endl;
  for (p = head; p != NULL; p = p->getnext()) {
    cout << p->getInfo() << endl;
  }
}

template <class t>
void doubleLinkedList<t>::reversePrint(){
  node<t>* p;
  if(!tail){
    cout << "double list is empty" << endl;
    return;
  }
  cout << endl << endl;
  for (p = tail; p != NULL; p = p->getPrevious()) {
    cout << p->getInfo() << endl;
  }
}

#endif
