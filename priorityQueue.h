#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <stdio.h>
#include "node.h"
#include "doubleLinkedList.h"

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
  doubleLinkedList<t>* removePriority(t &element);
  void print();
private:
  void addHead(t element);
  void addTail(t element);
  void removeHead();
  void removeTail();
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
  }else{
    cout << "priority does not exist" << endl;
  }
}

template <class t>
void priorityQueue<t>::addHead(t element){
  node<t>* newNode = new node<t>(element);
  head->setPrevious(newNode);
  newNode->setNext(head);
  head = newNode;
}

template <class t>
void priorityQueue<t>::addTail(t element){
  node<t>* newNode = new node<t>(element);
  tail->setNext(newNode);
  newNode->setPrevious(tail);
  tail = newNode;
}

template <class t>
void priorityQueue<t>::removeHead(){
  node<t>* p;
  if (head->getnext() == NULL) {
    head = tail = NULL;
    return;
  }
  p = head->getnext();
  p->setPrevious(NULL);
  delete head;
  head = p;
}

template <class t>
void priorityQueue<t>::removeTail(){
  node<t>* p;
  p = tail->getPrevious();
  p->setNext(NULL);
  delete tail;
  tail = p;
}

/** this metho will add elements to the priority queue by looking
* the parameter "int priority" in the objects that is working with
*/
template <class t>
void priorityQueue<t>::add(t element){
  node<t>* newNode = new node<t>(element);
  node<t>* aux;
  if (!head) {
    head = tail = position = newNode;
    return;
  }else if (newNode->getInfo().getPriority() <
  head->getInfo().getPriority()) {
    this->addHead(element);
    return;
  }else if (newNode->getInfo().getPriority() >
  tail->getInfo().getPriority() || newNode->getInfo().getPriority() ==
  tail->getInfo().getPriority()) {
    this->addTail(element);
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

/** this metho will remove elements to the priority queue by looking
* the parameter "int priority" if band is true
* else it will remove ass a normar queue by deleting the head.
*/
template <class t>
void priorityQueue<t>::removeElement(t &element, bool band){
  node<t>* aux = head;
  node<t>* p;
  if (this->isEmpty()) {
    cout << "queue is empty" << endl;
    return;
  }else if (band) {
    element = head->getInfo();
    this->removeHead();
    return;
  }else{
    if(this->firstOcurrence(element.getPriority())){
      if (position == head) {
        element = head->getInfo();
        this->removeHead();
        return;
      }else if (position == tail) {
        element = tail->getInfo();
        this->removeTail();
        return;
      }
      element = position->getInfo();
      aux = position;
      position = position->getPrevious();
      p = aux->getnext();
      position->setNext(p);
      p->setPrevious(position);
      delete aux;
      return;
    }else{
      cout << "priority level does not exist" << endl;
    }
  }
}

/** this will take the priority of the element that you send to it
* and delete all the elements with the same priority
*/
template <class t>
doubleLinkedList<t>* priorityQueue<t>::removePriority(t &element){
  doubleLinkedList<t>* auxList = new doubleLinkedList<t>;
  if (this->isEmpty()) {
    cout << "queue is empty" << endl;
  }else{
    while (this->firstOcurrence(element.getPriority())){
      this->removeElement(element, false);
      auxList->orderedPush(element);
    }
  }
  return auxList;
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
