#include "MyLinkedList.h"
#include "doubleLinkedList.h"

int main(int argc, char const *argv[]) {
  /*MyLinkedList<int> *linkedList;
  linkedList = new MyLinkedList<int>();
  linkedList->removeTail();
  linkedList->orderedPush(5);
  linkedList->orderedPush(33);
  linkedList->orderedPush(25);
  linkedList->orderedPush(12);
  linkedList->orderedPush(39);
  linkedList->addHead(21);
  linkedList->addTail(90);
  linkedList->print();
  linkedList->removeHead();
  linkedList->print();
  while (!linkedList->isEmpty()) {
    linkedList->removeTail();
    linkedList->print();
  }
  linkedList->removeTail();
  linkedList->print();*/
  doubleLinkedList<int> *dLinkedList;
  dLinkedList = new doubleLinkedList<int>();

  dLinkedList->addHead(20);
  dLinkedList->addHead(23);
  dLinkedList->addHead(27);
  dLinkedList->addHead(21);
  dLinkedList->fowardPrint();
  dLinkedList->addTail(23);
  dLinkedList->fowardPrint();
  dLinkedList->addTail(12);
  dLinkedList->fowardPrint();
  dLinkedList->addTail(65);
  dLinkedList->fowardPrint();
  return 0;
}
