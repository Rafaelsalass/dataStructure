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
  int x;
  while(true){
    cin >> x;
    dLinkedList->orderedPush(x);
    dLinkedList->fowardPrint();
  }
  return 0;
}
