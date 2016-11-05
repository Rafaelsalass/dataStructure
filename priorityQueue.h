#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <stdio.h>
#include "node.h"

/** this class requires you to have and int paramater, to define
* priority (the smaller the value the more important),
* and you also need to implement int getPriority().
*/

using namespace std;

template <class t>
class priorityQueue{

private:
  node<t>* head;
  node<t>* tail;
  node<t>* position;
public:
  priorityQueue();
  bool findPriorityStart(int find);
  bool isEmpty();
  bool setPosition();
  bool firstOcurrence(int find);
  void lastOcurrence(int find);
  void add(t element);
  void removeElement(t &element, bool band = true);
  void print();
};

template <class t>
priorityQueue<t>::priorityQueue(){
  head = tail = position = NULL;
}

template <class t>
bool priorityQueue<t>::isEmpty(){
  return (head == NULL)? true : false;
}

/** Set the position pointer to the head of the queue
* return false is queue is empty.
*/
template <class t>
bool priorityQueue<t>::setPosition(){
  if (this->isEmpty()) {
    cout << "empty queue" << endl;
    return false;
  }
  position = head;
  return true;
}

/** Updates the position pointer to where the start of a priority is.
* return true if it found it.
* return false if don't.
*/
template <class t>
bool priorityQueue<t>::firstOcurrence(int find){
  if(this->setPosition()){
    while(position){
      if (position->getInfo().getPriority() == find) {
        return true;
      }else{
        position = position->getnext();
      }
    }
  }
  return false;
}

/** Updates the position pointer to where the start of a priority should be.
* return true if it found it.
* return false if don't.
*/
template <class t>
bool priorityQueue<t>::findPriorityStart(int find){
  if(this->setPosition()){
    while(position){
      if (position->getInfo().getPriority() == find ||
          find < position->getnext()->getInfo().getPriority()) {
        return true;
      }else{
        position = position->getnext();
      }
    }
  }
  return false;
}

/** Updates the position pointer to
* where the end of a priority is.
*/
template <class t>
void priorityQueue<t>::lastOcurrence(int find){
  if (this->findPriorityStart(find)) {
    while (position) {
      if(position->getnext()->getInfo().getPriority() >
      position->getInfo().getPriority() ||
      position->getnext() == NULL){
          return;
      }else{
        position = position->getnext();
      }
    }
  }
}

template <class t>
void priorityQueue<t>::add(t element){
  node<t>* newNode = new node<t>(element);
  node<t>* aux;
  if (!head) {
    head = tail = position = newNode;
    return;
  }else if (newNode->getInfo().getPriority() <
  head->getInfo().getPriority()) {
    head->setPrevious(newNode);
    newNode->setNext(head);
    head = newNode;
    return;
  }else if (newNode->getInfo().getPriority() >
  tail->getInfo().getPriority() || newNode->getInfo().getPriority() ==
  tail->getInfo().getPriority()) {
    tail->setNext(newNode);
    newNode->setPrevious(tail);
    tail = newNode;
    return;
  }else{
    this->lastOcurrence(element.getPriority());
    if(position){
      aux = position->getnext();
      position->setNext(newNode);
      newNode->setPrevious(position);
      newNode->setNext(aux);
      aux->setPrevious(newNode);
      return;
    }
  }
}


template <class t>
void priorityQueue<t>::removeElement(t &element, bool band){
  node<t>* aux = head;
  node<t>* p;
  if (this->isEmpty()) {
    cout << "queue is empty" << endl;
    return;
  }else if (band) {
    if (head->getnext() == NULL) {
      head = tail = position = NULL;
      return;
    }
    aux = head->getnext();
    aux->setPrevious(NULL);
    delete head;
    head = aux;
    return;
  }else{
    // this is not working
    if(this->firstOcurrence(element.getPriority())){
      aux = position;
      position = position->getPrevious();
      p = position->getnext();
      position->setNext(p);
      p->setPrevious(position);
      delete aux;
      return;
    }else{
      cout << "priority level does not exist" << endl;
    }
  }
}

template <class t>
void priorityQueue<t>::print(){
  if(this->setPosition()){
    while (position){
      cout << position->getInfo() << endl;
      position = position->getnext();
    }
  }
}

#endif
