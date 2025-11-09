#ifndef TCIRCLIST_H
#define TCIRCLIST_H


#include <stdbool.h>

typedef struct _circ_no TNo;
typedef struct _circ_lista TCircList;

TNo *TNo_create(int info);
TCircList *TCircList_create();
void TCircList_destroy(TCircList **no_ref);
bool TCircList_is_empty(const TCircList *lista);
void TCircList_add_first(TCircList *lista, int info);
void TCircList_add_last(TCircList *lista, int info);
void TCircList_printf(const TCircList *lista);
void TCircList_printf_v2(const TCircList *lista);
void TCircList_inverted_printf(const TCircList *lista);

void TCircList_remove(TCircList *lista, int info);


#endif