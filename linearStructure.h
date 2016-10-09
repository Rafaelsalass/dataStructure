#ifndef LINEARSTRUCTURE_H
#define LINEARSTRUCTURE_H
#include <iostream>

using namespace std;

template <class t>
class linearStructure{
private:
  int size, topend;
  t *v;
public:
  linearStructure(int size);
  int remove(t element);
  int add(t element);
  void getSize();
  void print(int from = 0);
};

template <class t>
linearStructure<t>::linearStructure(int size){
  this->size = size;
  v = new t[size];
  if ( v == NULL) cout << "There's no enought space in the memory" << endl;
}

template <class t>
int linearStructure<t>::add(t element){
  if(!v){
    cout << "No enought memory on the vector" << endl;
    return -1;
  }
}

template <class t>
int linearStructure<t>::remove(t element){
  if(!v){
    cout << "No enought memory on the vector" << endl;
    return -1;
  }
}

template <class t>
void linearStructure<t>::print(int from = 0){
  cout << "start:" << endl;
  for (int i = from; i < topend; i++) {
    cout << v[i] << endl;
  }
}

template <class t>
void linearStructure<t>::getSize(){return size;}

#endif
