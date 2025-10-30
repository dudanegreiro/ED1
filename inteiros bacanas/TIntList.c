#include "TIntList.h"
#include <stdio.h>


typedef struct _no{
    int info;
    struct _no *prox;
} TNo;

typedef struct _lista{
    TNo *inicio;
} TIntList;

TNo *TNo_createNFill(int info){
    TNo *no = (TNo*) calloc (1, sizeof(TNo));

    if(no != NULL){
        no -> info = info;
        no -> prox = NULL;
    }

    return no;
}

TIntList *TIntList_create(){
    TIntList *novo = (TIntList*) calloc (1, sizeof(TIntList));

    if(novo != NULL){
        novo -> inicio = NULL;
    }

    return novo;
}

bool TIntList_insert(TIntList *lista, int info){
    TNo *novo = TNo_createNFill(info);
    if(novo == NULL) return false;

    //caso2> lista vazia
    if(lista -> inicio == NULL){
        lista -> inicio = novo;
        return true;
    }

    //caso2> percorrer até o final 
    TNo *atual = lista -> inicio;

    while(atual -> prox != NULL){
        atual = atual -> prox;
    }
    atual -> prox = novo;
    return true;
}

void TIntList_destroy(TIntList **lista_ref){
    if(lista_ref == NULL || *lista_ref == NULL) return;

    TIntList *lista = *lista_ref;
    TNo *p = lista -> inicio;
    TNo *aux = NULL;

    while(p != NULL){
        aux = p;
        p = p -> prox;
        free(aux);
    }

    free(lista);
}

TIntList *TIntList_gerar_digitos(int n){
    TIntList *lista = TIntList_create();

    while(n > 0){
        int digito = n % 10;

        TIntList_insert(lista, digito);
        n /= 10;
    }
    
    return lista;
}

int TIntList_soma_quadrado(TIntList *lista){
    int soma = 0;
    TNo *p = lista -> inicio;

    while( p != NULL){
        soma += p -> info * p -> info;
        p = p -> prox;
    }
    
    return soma;
}

void TIntList_print(TIntList *lista){
    TNo *p = lista -> inicio;

    while(p != NULL){
        printf("%d, ", p -> info);
        p = p -> prox;
    }
    puts("");
}