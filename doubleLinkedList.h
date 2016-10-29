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
  void removeHead();
  void removeTail();
  void orderedPush(t element);
  void fowardPrint();
  void reversePrint();
  bool isEmpty();
};

template <class t>
doubleLinkedList<t>::doubleLinkedList(){
  head = tail = NULL;
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
void doubleLinkedList<t>::fowardPrint(){
  node<t>* p;
  if(!head){
    cout << "doule list is empty" << endl;
    return;
  }
  cout << endl << endl;
  for (p = head; p != NULL; p = p->getnext()) {
    cout << p->getInfo() << endl;
  }
}

template <class t>
void doubleLinkedList<t>::reversePrint(){
  node<t>* p;
  if(!tail){
    cout << "doule list is empty" << endl;
    return;
  }
  cout << endl << endl;
  for (p = tail; p != NULL; p = p->getPrevious()) {
    cout << p->getInfo() << endl;
  }
}

#endif
