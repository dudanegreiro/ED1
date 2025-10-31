#include "TBigIntList.h"
#include <stdio.h>
#include <string.h>

typedef struct _no {
    long int info;
    struct _no *prox;
    struct _no *ante;
} TNo;

typedef struct _lista{
    TNo *inicio;
    TNo *final;
} TBigIntList;

TNo *TNo_create(long int info){
    TNo * no = (TNo*) malloc (sizeof(TNo));
    if (!no) {
        perror("Erro ao alocar no");
        exit(EXIT_FAILURE);
    }

    no -> ante = NULL;
    no -> prox = NULL;
    no -> info = info;

    return no;
}

TBigIntList *TBigIntList_create(){
    TBigIntList *lista = (TBigIntList*) malloc (sizeof(TBigIntList));
    if (!lista) {
        perror("Erro ao alocar lista");
        exit(EXIT_FAILURE);
    }

    lista -> inicio = NULL;
    lista -> final = NULL;

    return lista;
}


void TBigIntList_add_first(TBigIntList *lista, long int info){
    TNo *novo = TNo_create(info);
    if(lista -> inicio == NULL){
        lista -> inicio = novo;
        lista -> final = novo;
    } else {
        novo -> prox = lista -> inicio;
        lista -> inicio -> ante = novo;
        lista -> inicio = novo;
    }
}

void TBigIntList_destroy(TBigIntList **lista_ref){
    TBigIntList *lista  = *lista_ref;
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

//conversão de string para lista
TBigIntList *TBigIntList_converter_string(const char *string){
    TBigIntList*lista = TBigIntList_create();
    int len = strlen (string);

    for(int i = 0; i < len; i++){
        char c = string[i];
        if(c >= '0' && c <= '9'){
            TBigIntList_add_first(lista, c - '0');
        }
    }
    return lista;
}

//soma as listas
TBigIntList *TBigIntList_somar_listas(TBigIntList *lista1, TBigIntList *lista2){
    TBigIntList *resultado = TBigIntList_create();

    TNo *p = lista1 -> final;
    TNo *q = lista2 -> final;
    int passar = 0;

    while(p != NULL || q != NULL || passar > 0){
        int soma = passar;

        if(p != NULL){
            soma += p -> info ;
            p = p -> ante;
        }

        if(q != NULL){
            soma += q -> info;
            q = q -> ante;
        }
        
        TNo *novo = TNo_create(soma % 10);
        passar = soma / 10;
        
        novo -> prox = resultado -> inicio;
        if(resultado -> inicio != NULL){
            resultado -> inicio -> ante = novo;
        } else{
            resultado -> final = novo;
        }
        resultado -> inicio = novo;
    }    
    return resultado;
}

void TBigIntList_print(const TBigIntList *lista){
    if(lista == NULL || lista -> inicio == NULL){
        return;
    }
    
    for(TNo *p = lista -> inicio; p != NULL; p = p -> prox){
        printf("%ld", p -> info);
    }

    puts("");
}