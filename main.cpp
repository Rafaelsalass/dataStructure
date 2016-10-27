#include "MyLinkedList.h"


int main(int argc, char const *argv[]) {
  MyLinkedList<int> *linkedList;
  linkedList = new MyLinkedList<int>();

  linkedList->orderedPush(5);
  linkedList->orderedPush(25);
  linkedList->orderedPush(12);
  linkedList->orderedPush(3);
  linkedList->orderedPush(33);
  linkedList->print();
  return 0;
}
