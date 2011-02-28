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

  predicate MarksAll(Object* object, bool mark) = \forall Object* o; Reachable(object, o) ==> o->marked == mark;
 */

void mark_phase(){
}

/*@
  requires \valid(object);

  behavior unmarked:
    requires object->marked == false;
    requires MarksAll(object, false);
    ensures  MarksAll(object, true);

  behavior already_marked:
    requires object->marked == true;
    requires MarksAll(object, true);
    ensures  MarksAll(object, true);
 */
void mark(Object* object){
  if(object->marked == false){
    Node* node = object->children;

    object->marked = true;
    while(node){
      mark(node->value);
      node = node->next;
    }
  }
}

void sweep_phase(){}

void new_obj(int size){
}
