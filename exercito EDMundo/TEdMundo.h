#ifndef TEDMUNDO_H
#define TEDMUNDO_H

#include <stdbool.h>

typedef struct _no TNo;
typedef struct _lista TEdMundo;

TNo *TNo_create(int info);
void TNo_destroy(TNo **no_ref);

TEdMundo *TEdMundo_create();
void TEdMundo_destroy(TEdMundo **lista_ref);

void TEdMundo_add_last(TEdMundo *lista, int info);
int TEdMundo_simular(TEdMundo *lista, int M);
#endif