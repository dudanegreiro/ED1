#include "TListExercicio.h"
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

typedef struct _stack{
    TNo *topo;
} Stack;

//CRIA O NÓ
TNo *TNo_createNFill(int info){
    TNo *novo = (TNo*) malloc (sizeof(TNo));
    if(novo){
        novo -> info = info;
        novo -> prox = NULL;
    }
    return novo;
}

//CRIA A PILHA
Stack *Stack_create(){
    Stack *nova = (Stack*) malloc (sizeof(Stack));
    if(nova){
        nova -> topo = NULL;
    }
    return nova;
}

//EMPILHA
bool Stack_push(Stack *pilha, int info){
    if ( pilha != NULL){
        TNo *novo = TNo_createNFill(info);

        if(novo == NULL) return false;

        novo -> prox = pilha -> topo;
        pilha -> topo = novo;
        return true;
    }
    return false;
}

//DESEMPILHA (REMOVE E RETORNA VALOR)
bool Stack_pop(Stack *pilha, int *valor){
    if(!pilha || !pilha -> topo) return false;

    TNo *rem = pilha -> topo;
    *valor = rem -> info;
    pilha -> topo = rem -> prox;

    free(rem);
    return true;

}

//DESTROI PILHA
void Stack_destroy(Stack *pilha){
    if(pilha != NULL){
        TNo *aux;

        while(pilha -> topo){
            aux = pilha -> topo;
            pilha -> topo = pilha -> topo -> prox;
            free(aux);
        }
        free(pilha);
    }
}

//CONSULTA TOPO SEM REMOVER
int Stack_top(Stack *pilha){
    if(pilha && pilha -> topo) return pilha -> topo -> info;
    return -1;
}

//VERIFICA SE ESTÁ VAZIA
bool Stack_is_empty(Stack *pilha){
    if(pilha != NULL){
        return pilha -> topo == NULL;
    }
    return true;
}

//VERIFICA SE ESTÁ CHEIA (EM PILHA DINÂMICA: NUNCA)
bool Stack_is_full(Stack *pilha){
    if(pilha != NULL){
        return false;
    }
    return true;
}
