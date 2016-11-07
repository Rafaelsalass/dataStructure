#include "MyLinkedList.h"
#include "doubleLinkedList.h"
#include "dynamicStack.h"
#include "dynamicQueue.h"
#include "priorityQueue.h"
#include <string>

class testClass{
private:
  string name;
  int priority;
public:
  testClass(){};
  testClass(string name, int priority){
    this->name = name;
    this->priority = priority;
  }
  string getName(){return name;}
  int getPriority(){return priority;}
  void setName(string name){this->name = name;}
  void setPriority(int priority){this->priority = priority;}
  bool operator< ( testClass p ) { return this->name < p.getName();}
  bool operator> ( testClass p ) { return this->name > p.getName();}
  bool operator==( testClass p ) { return this->name == p.getName();}
  friend ostream &operator<< (ostream &p, testClass t) {return p << t.getName()
  <<"   " << t.getPriority();}

};
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
  }
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
  }*/

  /*dynamicQueue<int>* queue = new dynamicQueue<int>();
  int x = 0;
  queue->add(23);
  queue->add(12);
  queue->add(56);
  queue->add(234);
  queue->add(121);
  queue->add(78);
  queue->add(56);
  queue->add(234);
  queue->add(121);
  queue->add(78);
  queue->print();

  while (!queue->isEmpty()) {
    queue->removeElement(x);
    cout << "Value of x:" << x << endl;
    queue->print();
  }*/

  priorityQueue<testClass>* pQueue = new priorityQueue<testClass>;
  string name;
  int priority, x;
  testClass aux;
  x = 0;
  while (x < 8) {
    x++;
    cin >> name;
    cin.ignore();
    cin >> priority;
    aux.setName(name);
    aux.setPriority(priority);
    pQueue->add(aux);
    cout << endl;
    pQueue->print();
  }
  /*
  while (!pQueue->isEmpty()) {
    aux.setName("tambores");
    cin >> priority;
    aux.setPriority(priority);
    pQueue->removeElement(aux,false);
    cout << endl;
    pQueue->print();
  }*/

  doubleLinkedList<testClass>* auxDoubleList = new doubleLinkedList<testClass>;

  cin >> priority;
  aux.setName("string name");
  aux.setPriority(priority);
  auxDoubleList = pQueue->removePriority(aux);
  pQueue->print();

  cout << "deleted ones" << endl;
  auxDoubleList->fowardPrint();
  return 0;
}
