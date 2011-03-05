#ifndef OBJECT_H
#define OBJECT_H

typedef enum _bool { false = 0, true = 1 } bool ;

#define NULL 0


struct Object;

typedef struct Node{
  struct Object* value;
  struct Node* next;
} Node;

typedef struct Object{
  Node* children;
  bool marked;
} Object;

#endif
