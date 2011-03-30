#include "object.h"
/*
  // xs contains obj.
  inductive In(Object* obj, Node* xs) {
    case InEq:
      \forall Object* obj, Node* xs;
      xs->value == obj ==> In(obj, xs);
   case InNext:
      \forall Object* obj, Node* xs;
      In(obj, xs->next) ==> In(obj, xs);
  }

  // o1->next->next->...->next = o2
  inductive Reachable(Object* o1, Object* o2) {
    case Same:
      \forall Object* o;
      Reachable(o,o);
    case Children:
      \forall Object* o1, Object* o2, Object* o3;
      In(o3, o1->children) ==> Reachable(o3, o2) ==> Reachable(o1, o2);
  }

  inductive ValidNode{L}(Node* node) {
    case VNil{L}:
      ValidNode(NULL);
    case VCons{L}:
      \forall Node* node;
         \valid(node)        &&
         \valid(node->value) &&
	 ValidNode(node->value->children) ==> ValidNode{L}(node->next) ==> ValidNode(node);
  }

  // the children of marked object should be marked. See also http://pastebin.com/xGyfGXx9
  predicate Consistent(Object* object) = \forall Object* o, Object* s; Reachable(object, o) ==> o->marked==true ==> Reachable(o, s) ==> s->marked==true;

  predicate MarksAll(Object* object) = \forall Object* o, Object* s; Reachable(object, o) ==> o->marked==true;
 */

/*
  requires \valid(object);
  requires ValidNode(object->children);
  requires Consistent(object);

  behavior marked:
    assumes object->marked == true;
    ensures MarksAll(object);
    ensures object->marked == true;

  behavior unmarked:
    assumes object->marked == false;
    ensures MarksAll(object);
    ensures object->marked == true;

  disjoint behaviors;
 */
void mark(Object* object){
  if(object->marked == false){
    int i = 0;
    object->marked = true;

    for(i = 0; i < object->size; i++){
      mark(object->children+i);
    }
  }
}

