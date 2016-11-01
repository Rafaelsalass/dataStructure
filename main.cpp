#include "MyLinkedList.h"
#include "doubleLinkedList.h"
#include "dynamicStack.h"

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
  linkedList->print();
  doubleLinkedList<int> *dLinkedList;
  dLinkedList = new doubleLinkedList<int>();
  int x;
  while(true){
    cin >> x;
    dLinkedList->orderedPush(x);
    dLinkedList->fowardPrint();
  }*/
  dynamicStack<int>* stack = new dynamicStack<int>();
  int x, y;
  y = 0;
  stack->add(23);
  stack->add(12);
  stack->add(56);
  stack->add(234);
  stack->add(121);
  stack->add(78);
  while (y < 10) {
    stack->removeElement(x);
    stack->print();
    cout << endl;
    y++;
  }
  return 0;
}
