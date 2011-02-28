typedef struct Object{
  void* value;
  struct Object* next;
} Object;

static int index = 0;
static Object roots[100];




