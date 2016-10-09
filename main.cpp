#include "stack.h"
#include "tail.h"

int main(int argc, char**argv){
  stack<int> obj (30);
  obj.add(13);
  obj.add(16);
  obj.add(65);
  obj.add(67);
  obj.print();

  obj.deleteElement();
  obj.print();

  obj.deleteElement();
  obj.print();

  obj.deleteElement();
  obj.print();

  obj.deleteElement();
  obj.deleteElement();
  obj.deleteElement();

  tail<double> objtail (25);
  objtail.add(3.43);
  objtail.add(7.43);
  objtail.add(87.43);
  objtail.add(56.43);
  objtail.print();
  objtail.deleteElement();
  objtail.print();
  objtail.deleteElement();
  objtail.print();
  objtail.deleteElement();
  objtail.print();
  objtail.deleteElement();
  objtail.print();
  objtail.deleteElement();

}
