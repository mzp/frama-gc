typedef int bool;
#define NULL 0
const bool true = 1;
const bool false = 1;

struct Object;

typedef struct Node{
  struct Object* value;
  struct Node* next;
} Node;

typedef struct Object{
  Node* children;
  bool marked;
} Object;


/*@
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

  // the children of marked object should be marked. See also http://pastebin.com/xGyfGXx9
  predicate Consistent(Object* object) = \forall Object* o, Object* s; Reachable(object, o) ==> o->marked==true ==> Reachable(o, s) ==> s->marked==true;
 */

/*@
  requires \valid(object);
  requires Consistent(object);
  ensures Consistent(object);
  ensures object->marked != false;
 */
void mark(Object* object){
  if(object->marked == false){
    Node* node = object->children;
    object->marked = true;
    while(node){
      node = node->next;
    }
  }
}

void mark_phase(){}

void sweep_phase(){}

void new_obj(int size){
}
