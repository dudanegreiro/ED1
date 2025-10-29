#include "TSortedList.h"
#include <stdio.h>

typedef struct _no{
    int info;
    struct _no *prox;
} TNo;

typedef struct _lista{
    TNo *inicio;
} TSortedList;

TNo *TNo_createNFill(int info){
    TNo *novo = malloc (sizeof(TNo));

    if(novo != NULL){
        novo -> info = info;
        novo -> prox = NULL;
    }
    return novo;
}

TSortedList *TSortedList_create(){
    TSortedList *nova = malloc (sizeof(TSortedList));

    if(nova != NULL){
        nova -> inicio = NULL;
    }
    
    return nova;
}

bool TSortedList_insert(TSortedList *lista, int info){
    TNo *novo = TNo_createNFill(info);
    if(novo == NULL) return false;

    //TODO: Fazer a inserção ordenada

    //caso1> a lista está vazia 
    if (lista -> inicio == NULL){
        lista -> inicio = novo;
        return true;
    }

    //caso2> inserir no incício(menor que o primeiro)
    if(info < lista -> inicio -> info){
        novo -> prox = lista -> inicio;
        lista -> inicio = novo;
        return true;
    }

    //caso3> inserir no meio ou no final
    TNo *p = lista -> inicio;
    TNo *prev = NULL; //nó anterior

    while(p != NULL && p -> info < info){
        prev = p;
        p = p -> prox;
    }

    //p == NULL ou p -> info >= info
    novo -> prox = p;
    prev -> prox = novo;
    return true;
}
void TSortedList_print(TSortedList *lista){
    if(lista != NULL) {
        TNo *aux = lista -> inicio;
        while(aux != NULL){
            printf("%p: [info: %d, prox: %p] ->\n", aux, aux -> info, aux -> prox);
            aux = aux -> prox;
        }
    }
}