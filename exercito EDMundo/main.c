#include "TEdMundo.h"
#include <stdio.h>

int main(){
    int N, M;

    while(scanf("%d %d", &N, &M) == 2){
        TEdMundo *circulo = TEdMundo_create();

        for(int i = 1; i <= N; i++) {
            TEdMundo_add_last(circulo, i);
        }

        int posicao = TEdMundo_simular(circulo, M);
        printf("%d\n", posicao);

        TEdMundo_destroy(&circulo);
    }
    return 0;
}