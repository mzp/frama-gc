#include <stdio.h>
#include "mark.h"

int main(){
  // a -> b -> d
  //      c -> e
  Object a,b,c,d,e;
  Node   a_1, a_2, b_1, c_1;

  a.marked = false;
  a.children = &a_1;
  a_1.value = &b;
  a_1.next = &a_2;
  a_2.value = &c;
  a_2.next = 0;

  b.marked = false;
  b.children = &b_1;
  b_1.value = &d;
  b_1.next = 0;

  c.marked = false;
  c.children = &c_1;
  c_1.value  = &e;
  c_1.next = 0;

  d.marked = false;
  d.children = 0;

  e.marked = false;
  e.children = 0;

  mark(&b);

  printf("a:%d b:%d c:%d d:%d e:%d\n",
	 a.marked,
	 b.marked,
	 c.marked,
	 d.marked,
	 e.marked);

}
