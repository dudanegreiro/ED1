#include "TListOrdenada.h"
#include <stdio.h>

int main(){
    TListOrdenada *lista = TListOrdenada_create();

    TListOrdenada_insert(lista, 10);
    TListOrdenada_insert(lista, 5);
    TListOrdenada_insert(lista, 12);
    TListOrdenada_insert(lista, 1);
    TListOrdenada_print(lista);
    TListOrdenada_print_reverse(lista);

    TListOrdenada_destroy(&lista);
    if(lista == NULL){
        puts("Lista foi destruida e h NULL agora!");
    } else {
        puts("Algo deu errado, lista não eh NULL!");
    }


  return 0;  
}