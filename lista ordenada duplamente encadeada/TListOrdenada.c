#include "TListOrdenada.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox;
    struct _no *ante;
} TNo;

typedef struct _lista{
    TNo *inicio;
    TNo * final;
} TListOrdenada;

TNo * TNo_create(int info){
    TNo *no = (TNo*) calloc (1, sizeof(TNo));

    no -> ante = NULL;
    no -> prox = NULL;
    no -> info = info;

    return no;
}

TListOrdenada *TListOrdenada_create(){
    TListOrdenada *lista = (TListOrdenada*) calloc (1, sizeof(TListOrdenada));

    lista -> inicio = NULL;
    lista -> final = NULL;

    return lista;
}

void TListOrdenada_destroy(TListOrdenada **lista_ref){
    TListOrdenada *lista = *lista_ref;

    TNo *p = lista -> inicio;
    TNo *aux = NULL;

    while(p != NULL){
        aux = p;
        p = p -> prox;
        free(aux);
    }

    free(lista);
    *lista_ref = NULL;
}

bool TListOrdenada_insert( TListOrdenada *lista, int info){
    if(lista == NULL) return false;


    TNo *novo = TNo_create(info);
    if(novo == NULL) return false;

    //caso1> a lista está vazia
    if(lista -> inicio == NULL){
        lista -> inicio = novo;
        lista -> final = novo;

        return true;
    }

    TNo *atual = lista -> inicio;

    //caso2> inserir no início
    if(info < atual -> info){
        novo -> prox = atual;
        atual -> ante = novo;
        lista -> inicio = novo;

        return true;
    }

    //percore até encotrar a posição
    while(atual -> prox != NULL && atual -> prox -> info < info){
        atual = atual -> prox;
    }

    //caso3> inserir no final
    if (atual -> prox == NULL){
        atual -> prox = novo;
        novo -> ante = atual;
        lista -> final = novo;
        
        return true;
    }

    //caso4> inserir o nó no meio
    TNo *proximo = atual -> prox;

    novo -> prox = proximo;
    novo -> ante = atual;
    atual -> prox = novo;
    proximo -> ante = novo;

    return true;
}


void TListOrdenada_print(const TListOrdenada *lista){
    if (lista == NULL || lista -> inicio == NULL){
        puts("Lista vazia.");
        return;
    }

    TNo *p = lista -> inicio;
    printf("Lista -> ");
    

    while(p != NULL){
        printf("%d -> ", p -> info);
        p = p -> prox;
    }

    puts("");
}

void TListOrdenada_print_reverse(const TListOrdenada *lista){
    if(lista == NULL || lista -> final == NULL){
        puts("Lista vazia");
        return;
    }

    TNo *p = lista -> final;
    printf("Lista reversa -> ");

    while(p != NULL){
        printf("%d -> ", p -> info);
        p = p -> ante;
    }
    puts("");
}