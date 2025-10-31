#ifndef TBIGINTLIST_H
#define TBIGINTLIST_H

#include <stdlib.h>

typedef struct _no TNo;
typedef struct _lista TBigIntList;

TNo *TNo_create(long int info);
TBigIntList *TBigIntList_create();
void TBigIntList_add_first(TBigIntList *lista, long int info);
void TBigIntList_destroy(TBigIntList **lista_ref);
TBigIntList *TBigIntList_converter_string(const char *string);
TBigIntList *TBigIntList_somar_listas(TBigIntList *lista1, TBigIntList *lista2);
void TBigIntList_print(const TBigIntList *lista);

#endif