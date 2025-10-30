#ifndef TINTLIST_H
#define TINTLIST_H

#include <stdbool.h>
#include <stdlib.h>


typedef struct _no TNo;
typedef struct _lista TIntList;

TNo *TNo_createNFill(int);
TIntList *TIntList_create();
bool TIntList_insert(TIntList *, int);
void TIntList_destroy(TIntList **);
TIntList *TIntList_gerar_digitos(int);
int TIntList_soma_quadrado(TIntList *);
void TIntList_print(TIntList *);

#endif