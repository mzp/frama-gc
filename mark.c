#include "object.h"
/*@
  inductive Reachable(Object* o1, Object* o2) {
    case Same:
      \forall Object* o;
      Reachable(o,o);
    case Children:
      \forall Object* o1, Object* o2, unsigned int i;
      0 <= i && i < o1->size ==> Reachable(o1->children + i, o2) ==> Reachable(o1, o2);
  }

  // the children of marked object should be marked. See also http://pastebin.com/xGyfGXx9
  predicate Consistent(Object* object) = \forall Object* o, Object* s; Reachable(object, o) ==> o->marked==true ==> Reachable(o, s) ==> s->marked==true;

  predicate MarksAll(Object* object) = \forall Object* o, Object* s; Reachable(object, o) ==> o->marked==true;
 */

/*@
  requires \valid(object);
  requires \valid_range(object->children, 0, object->size + 1);

  requires Consistent(object);

  behavior marked:
    assumes object->marked == true;
    ensures MarksAll(object);

  behavior unmarked:
    assumes object->marked == false;
    ensures MarksAll(object);

  disjoint behaviors;
 */
void mark(Object* object){
  if(object->marked == false){
    unsigned int i = 0;
    object->marked = true;

    /*@
      loop invariant \valid(object->children+i) && i <= object->size;
      loop variant object->size - i;
     */
    for(i = 0; i < object->size; i++){
      mark(object->children+i);
    }
  }
}

