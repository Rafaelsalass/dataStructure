#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include <string>
#include "vertex.h"
using namespace std;

template <class t>
class graphMatrix{

private:
  int maxVertex;
  int numVertex;
  vertex<t>* vertexs;
  int** matrixAd;
public:
  graphMatrix(int maxVertex);
  graphMatrix();
  int getNumVertex();
  void setNumVertex(int numVertex);
  void newVertex(string name, t info);
  void newArch(string vertexA, string vertexB);
  int searchByName(string name);
};

template <class t>
graphMatrix<t>::graphMatrix(int maxVertex){
  typedef int* pint;
  this->maxVertex = maxVertex;
  vertexs = new vertex<t>[maxVertex];
  matrixAd = new pint[maxVertex];
  numVertex = 0;
  for (int i = 0; i < maxVertex; i++) {
    matrixAd[i] = new int[maxVertex];
  }
}

template <class t>
graphMatrix<t>::graphMatrix(){
  this->maxVertex = 1;
  graphMatrix(maxVertex);
}

template <class t>
int graphMatrix<t>::getNumVertex(){
  return numVertex;
};

template <class t>
void graphMatrix<t>::setNumVertex(int numVertex){
  this->numVertex = numVertex;
}

template <class t>
void graphMatrix<t>::newVertex(string name, t info){
  bool exits = searchByName(name) >= 0;
  if(!exits){
    vertex<t> v;
    v.setName(name);
    v.setInfo(info);
    v.setNumber(numVertex);
    vertexs[numVertex++] = v;
  }
}

template <class t>
int graphMatrix<t>::searchByName(string name){
    int i;
    bool found = false;
    for (i = 0; (i < numVertex) && !found;) {
      found = vertexs[i].equals(name);
      if(!found){
        i++;
      }
    }
    return (i < numVertex) ? i : -1;
}

template <class t>
void graphMatrix<t>::newArch(string vertexA, string vertexB){
  
}

#endif
