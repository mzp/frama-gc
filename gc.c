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
  inductive In(Object* obj, Node* xs) {
    case InEq:
      \forall Object* obj, Node* xs;
      xs->value == obj ==> In(obj, xs);
   case InNext:
      \forall Object* obj, Node* xs;
      In(obj, xs->next) ==> In(obj, xs);
  }

  inductive Reachable(Object* o1, Object* o2) {
    case Same:
      \forall Object* o;
      Reachable(o,o);
    case ChildrenLeft:
      \forall Object* o1, Object* o2;
      In(o2, o1->children) ==> Reachable(o1, o2);
  }
 */

void mark_phase(){
}

/*@
  requires \valid(object);
  requires (\forall Object* o; Reachable(object, o) ==> (o->marked == false));

  behavior unmark:
    requires (object->marked == false);
    ensures (\forall Object* o; Reachable(object, o) ==> (o->marked == false));

  behavior mark:
   requires object->marked == true;
   ensures (\forall Object* o; Reachable(object, o) ==> (o->marked == true));
 */
void mark(Object* object){
  if(object->marked == false){
    return;
  }else{
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
