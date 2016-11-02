#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <stdio.h>
#include "node.h"

/* this class requires you to have and int paramater, to define
priority (from 0, the smaller the value the more important),
and you also need to implement int getPriority()
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
  bool firstOcurrence(int find);
  bool isEmpty();
  void add(t element);
  void remove(t &element, bool band = true, int find = 0);
  bool setPosition();
};

template <class t>
priorityQueue<t>::priorityQueue(){
  head = tail = position = NULL;
}

template <class t>
bool priorityQueue<t>::isEmpty(){
  return (head == NULL)? true : false;
}


/* Set the position pointer to the head of the queue
return false is queue is empty.
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

/* Updates the position pointer to the first ocurrence
of the int value you hit.
return true if it found it.
return false if don't.
*/
template <class t>
bool priorityQueue<t>::firstOcurrence(int find){
  if(this->setPosition()){
    while(position){
      if (position->getInfo()->getPriority() == find) {
        return true;
      }else{
        position = position->getnext();
      }
    }
  }
  return false;
}


#endif