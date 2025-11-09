#include "TEdMundo.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _no{
    int info;
    struct _no *ante;
    struct _no *prox;
} TNo;

typedef struct _lista{
    TNo *inicio;
    TNo *final;
    size_t size;
} TEdMundo;

TNo *TNo_create(int info){
    TNo *no = malloc (sizeof(TNo));
    
    if(no) {
        no -> info = info;
        no -> ante = no;
        no -> prox = no;
    }

    return no;
}

void TNo_destroy(TNo **no_ref){
    TNo *no = *no_ref;
    if(no){
        free(no);
        *no_ref = NULL;
    }
}

TEdMundo *TEdMundo_create(){
    TEdMundo *lista = (TEdMundo*) malloc (sizeof(TEdMundo));

    if(lista){
        lista -> inicio = NULL;
        lista -> final = NULL;
        lista -> size = 0;
    }

    return lista;
}

void TEdMundo_destroy(TEdMundo **lista_ref){
TEdMundo *lista = *lista_ref;
    if (!lista) return;
    
    
    if (lista->size > 0) {
        TNo *inicio = lista -> inicio;
        TNo *atual = inicio;

        do {
            TNo *prox = atual -> prox;
            free(atual);
            atual = prox;
        } while (atual != inicio);
    }
    free(lista);
    *lista_ref = NULL;
}

void TEdMundo_add_last(TEdMundo *lista, int info){
    if (!lista) return;

    TNo *novo = TNo_create(info);
    if (!novo) return;

    if (lista -> size == 0) {

        // Primeira inserção: lista com um elemento
        lista -> inicio = novo;
        lista -> final = novo;
        novo -> ante = novo;  // Aponta para si mesmo
        novo -> prox = novo;  // Aponta para si mesmo

    } else {

        // Inserir no final da lista circular
        novo -> ante = lista -> final;
        novo -> prox = lista ->  inicio;
        lista -> final -> prox = novo;
        lista -> inicio -> ante = novo;
        lista -> final = novo;
    }
    lista -> size++;
}

int TEdMundo_simular(TEdMundo *lista, int M){
    if(!lista || lista -> size == 0) return -1;
    if(lista-> size == 1) return lista-> inicio -> info;

    TNo *atual = lista -> inicio;

    while(lista -> size > 1){

        //percorre M - 1 passos
        for(int i = 1; i < M; i++){
            atual = atual -> prox;

        }

        //eliminar o nó atual (M-ésimo)
        TNo *eliminado = atual;
        atual = atual -> prox; //começa a contagem a partir do próximo

        //remover da lista
        eliminado -> ante -> prox = eliminado -> prox;
        eliminado -> prox -> ante = eliminado -> ante;

        //atualizar os ponteiros
        if(eliminado == lista -> inicio){
            lista -> inicio = atual;
        }

        if(eliminado == lista -> final){
            lista -> final = eliminado -> ante;
        }

        TNo_destroy(&eliminado);
        lista -> size--;

        if (lista->size == 1) {
            lista -> inicio -> ante = lista -> inicio;
            lista -> inicio -> prox = lista -> inicio;
        }
    }

    return lista -> inicio -> info;
}