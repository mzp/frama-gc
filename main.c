#include <stdio.h>
#include "mark.h"

int main(){
  // a -> b -> d
  //      c -> e
  Object a;
  Object ac[2];
  Object bc[1];
  Object cc[1];

  a.marked = false;
  a.children = ac;
  a.size = 2;

  ac[0].marked = false;
  ac[0].children = bc;
  ac[0].size = 1;

  ac[1].marked = false;
  ac[1].children = cc;
  ac[1].size = 1;

  bc[0].marked = false;
  bc[0].size = 0;

  cc[0].marked = false;
  cc[0].size = 0;

  mark(&a);

  printf("a:%d b:%d c:%d d:%d e:%d\n",
	 a.marked,
	 ac[0].marked,
	 ac[1].marked,
	 bc[0].marked,
	 cc[0].marked);
}

