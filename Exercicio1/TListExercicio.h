#ifndef TLISTEXERCICIO_H
#define TLISTEXERCICIO_H

#include <stdbool.h>

typedef struct _no TNo;
typedef struct _stack Stack;

TNo *TNo_createNFill(int info);
Stack *Stack_create(void);
bool Stack_push(Stack *pilha, int info);
bool Stack_pop(Stack *pilha, int *valor);
int Stack_top(Stack *pilha);
void Stack_destroy(Stack *pilha);
bool Stack_is_empty(Stack *pilha);
bool Stack_is_full(Stack *pilha);

#endif