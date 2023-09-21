#include "item.h"

typedef struct c_stack * stack;

stack newStack(void);

int emptyStack(stack s);

int pop(stack s);

int push(stack s, item val);

item top(stack s);