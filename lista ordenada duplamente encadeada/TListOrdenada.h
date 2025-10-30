#ifndef TLISTORDENADA_H
#define TLISTORDENADA_H

#include <stdbool.h>

typedef struct _no TNo;
typedef struct _lista TListOrdenada;

TNo * TNo_create(int info);
TListOrdenada *TListOrdenada_create();
void TListOrdenada_destroy(TListOrdenada **lista_ref);
bool TListOrdenada_insert(TListOrdenada *lista, int info);
void TListOrdenada_print(const TListOrdenada *lista);
void TListOrdenada_print_reverse(const TListOrdenada *lista);


#endif 