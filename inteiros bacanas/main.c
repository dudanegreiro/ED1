#include "TIntList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    TIntList *solution = TIntList_create();
    TIntList_insert(solution, n);

    while (n >= 10) {
        TIntList *digitos = TIntList_gerar_digitos(n);
        n = TIntList_soma_quadrado(digitos);
        TIntList_insert(solution, n);
        TIntList_destroy(&digitos); 
    }

    TIntList_print(solution);

    if (n == 1)
        printf("bacana\n");
    else
        printf("non-bacana\n");

    TIntList_destroy(&solution);
    return 0;
}

