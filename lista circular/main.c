#include "TCircList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(){
    TCircList *lista = TCircList_create();
    TCircList_printf_v2(lista);
    TCircList_inverted_printf(lista);

    puts("Adding...");
    TCircList_add_first(lista, 7);
    TCircList_add_first(lista, 5);
    TCircList_add_first(lista, 4);
    TCircList_add_first(lista, 7);
    TCircList_add_first(lista, 10);
    TCircList_printf(lista);
    TCircList_inverted_printf(lista);


    TCircList_destroy(&lista);
    return 0;
}