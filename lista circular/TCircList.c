#include "TCircList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _circ_no{
    int info;
    struct _circ_no *ante;
    struct _circ_no *prox;
} TNo;

typedef struct _circ_lista{
    TNo *inicio;
    TNo *final;
    size_t size;
} TCircList;

TNo *TNo_create(int info){
    TNo *no = (TNo*) malloc (sizeof(TNo));
    if(no){
        no -> info = info;
        no -> ante = no;
        no -> prox = no;
    }
    return no;
}

void TNo_destroy(TNo **no_ref) {
    TNo *no = *no_ref;
    if (no) {
        free(no);
        *no_ref = NULL;
    }
}

TCircList *TCircList_create(){
    TCircList *lista = (TCircList*)malloc(sizeof(TCircList));
    if (lista) {
        lista->inicio = NULL;
        lista->final = NULL;
        lista->size = 0;
    }
    return lista;
}

void TCircList_destroy(TCircList **lista_ref){
   TCircList *lista = *lista_ref;
    if (!lista) return;

    TNo *p = lista->inicio;
    if (p) {
        TNo *temp;
        do {
            temp = p;
            p = p->prox;
            TNo_destroy(&temp);
        } while (p != lista->inicio);
    }

    free(lista);
    *lista_ref = NULL;
}

void TCircList_destroy_v2(TCircList **lista_ref){
    TCircList *lista = *lista_ref;

    TNo *p = lista -> inicio;
    TNo *aux = NULL;

    for(int i = 0; i < lista -> size; i++){
        aux = p;
        p = p -> prox;
        TNo_destroy(&aux);
    }

    free(lista);

    *lista_ref = NULL;
}

bool TCircList_is_empty(const TCircList *lista){
    return lista -> size == 0;
}

void TCircList_add_first(TCircList *lista, int info){
    TNo *novo = TNo_create(info);
    if (!novo) return;

    if(TCircList_is_empty(lista)){
        lista->inicio = novo;
        lista->final = novo;
        
    } else{
        novo->prox = lista->inicio;
        novo->ante = lista->final;
        lista->inicio->ante = novo;
        lista->final->prox = novo;
        lista->inicio = novo;
    }
    
   lista->size++;
}

void TCircList_add_last(TCircList *lista, int info){
    if(TCircList_is_empty(lista)){
        puts("Lista -> NULL");
        puts("Lista -> final");
    } else{
        TNo *p = lista -> inicio;

        printf("Lista -> ");

        do {
            printf("%d -> ", p -> info);
            p = p -> prox;

        } while(p != lista -> inicio);

        printf("\nLista -> final -> %d\n", lista -> final -> info);
    }
    printf("Size: %lu\n\n", lista -> size);
}

void TCircList_printf(const TCircList *lista) {
    if (TCircList_is_empty(lista)) {
        printf("Lista -> NULL\n");
        printf("Lista -> final-> NULL\n");
        return;
    } else{
        TNo *p = lista -> inicio;

        printf("Lista -> ");

        do {
            printf("%d -> ", p -> info);
            p = p -> prox;
        } while(p != lista -> inicio);

        printf("\nLista -> final -> %d\n", lista -> final -> info);
    }

    printf("Size: %lu\n\n", lista -> size);

}

void TCircList_printf_v2(const TCircList *lista){
    if(TCircList_is_empty(lista)){
        printf("Lista -> NULL\n");
        printf("Lista -> final -> NULL\n");
    } else{
        TNo *p = lista -> inicio;
        printf("Lista -> ");

        for(int i = 0; i < lista -> size; i++){
            printf("%d -> ", p -> info);
            p = p -> prox;
        }
        printf("\nLista -> final -> %d\n", lista -> final -> info);
    }
    printf("Size: %lu\n\n", lista -> size);
}

void TCircList_inverted_printf(const TCircList *lista){
    if(TCircList_is_empty(lista)){
        printf("Lista -> NULL\n");
        printf("Lista -> final -> NULL\n");

    } else{
        TNo *p = lista -> final;
        printf("Lista(reversa) ->");

        for(int i = 0; i < lista -> size; i++){
            printf("%d -> ", p -> info);
            p = p -> ante;
        }

        printf("\nLista -> inicio -> %d\n", lista -> inicio -> info);
    }

    printf("Size: %lu\n\n");
}