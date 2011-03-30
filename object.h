#ifndef OBJECT_H
#define OBJECT_H

typedef enum _bool { false = 0, true = 1 } bool ;

#ifndef NULL
#define NULL 0
#endif


struct Object;


typedef struct Object{
  bool marked;
  unsigned int size;
  struct Object* children;
} Object;

#endif
