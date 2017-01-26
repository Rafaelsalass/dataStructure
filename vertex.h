#ifndef VERTEX_H
#define VERTEX_H
#include <string>
using namespace std;

template <class t>
class vertex{
private:
  string name;
  int number;
  t info;
public:
  vertex();
  vertex(string name);
  vertex(string name, int number);
  vertex(string name, int number, t info);
  vertex(string name, t info);
  string getName(){ return name;}
  int getNumber(){  return number;}
  t getInfo(){  return info;}
  void setName(string name){  this->name = name;}
  void setNumber(int number){ this->number = number;}
  void setInfo(t info){ this->info = info;}
  bool equals(string name);
};

template <class t>
vertex<t>::vertex(){
}

template <class t>
vertex<t>::vertex(string name){
  this->name = name;
  this->number = -1;
}

template <class t>
vertex<t>::vertex(string name, int number, t info){
  this->name = name;
  this->number = number;
  this->info = info;
}

template <class t>
vertex<t>::vertex(string name, t info){
  this->vertex(name);
  this->info = info;
}

template <class t>
bool vertex<t>::equals(string name){
  return (this->name == name) ? true : false;
}

#endif
