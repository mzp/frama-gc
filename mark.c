#include "object.h"

/*@
  inductive Reachable{L}(Object* o1, Object* o2) {
    case Same:
      \forall Object* o;
      Reachable(o,o);
    case Children:
      \forall Object* o1, Object* o2, unsigned int i;
      0 <= i && i < o1->size ==> Reachable(o1->children + i, o2) ==> Reachable(o1, o2);
  }

  // the children of marked object should be marked. See also http://pastebin.com/xGyfGXx9
  predicate MarksAll{L}(Object* object) = \forall Object* o, Object* s; Reachable(object, o) ==> o->marked==true;

  predicate Consistent{L}(Object* object) = \forall Object* o, Object* s; Reachable(object, o) ==> o->marked==true ==> MarksAll(o);
 */

/*@
  requires \valid_range(objects, 0, size + 1);
  requires \forall unsigned int i; 0 <= i && i < size ==> \valid(objects+i) && Consistent(objects+i);
  ensures \forall unsigned int i; 0 <= i && i < size ==> MarksAll(objects+i);
 */
void each(Object* objects, unsigned int size){
  unsigned int i;
  /*@
    loop invariant (\forall unsigned int j; 0 <= j && j < i ==> MarksAll(objects+j)) && Consistent(objects+i);
    loop variant size - i;
   */
  for(i = 0; i < size; i++) {
    mark(objects+i);
  }
}

/*@
  requires \valid(object);
  requires \valid_range(object->children, 0, object->size + 1);
  requires Consistent(object);

  assigns \nothing;

  ensures MarksAll(object);
 */
void mark(Object* object){
  if(object->marked == false){
    object->marked = true;
    each(object->children, object->size);
    object->marked = true;
  }
}

