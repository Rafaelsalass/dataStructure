#include "MyLinkedList.h"


int main(int argc, char const *argv[]) {
  MyLinkedList<int> *linkedList;
  linkedList = new MyLinkedList<int>();

  linkedList->orderedPush(5);
  linkedList->orderedPush(33);
  linkedList->orderedPush(25);
  linkedList->orderedPush(12);
  linkedList->orderedPush(3);
  linkedList->orderedPush(11);
  linkedList->orderedPush(34);
  linkedList->orderedPush(76);
  linkedList->orderedPush(34);
  linkedList->orderedPush(23);
  linkedList->orderedPush(54);
  linkedList->orderedPush(120);
  linkedList->orderedPush(30);
  linkedList->orderedPush(142);
  linkedList->orderedPush(39);
  linkedList->print();
  return 0;
}
