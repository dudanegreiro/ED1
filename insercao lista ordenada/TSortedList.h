#ifndef  TSORTEDLIST_H
#define TSORTEDLIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct _no TNo;
typedef struct _lista TSortedList;

TNo *TNo_createNFill(int);
TSortedList *TSortedList_create();
bool TSortedList_insert(TSortedList *, int);
void TSortedList_print(TSortedList *);

#endif