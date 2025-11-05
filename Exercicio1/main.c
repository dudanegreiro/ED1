#include "TListExercicio.h"
#include <stdio.h>
#include <string.h>

int main(){
    Stack *pilha = Stack_create();

    char input[50];
    fgets(input, 50, stdin);

    for(int i = 0; i < strlen(input); i++){
        if(input[i] == ' ' || input[i] == '.'){
            int temp;
            while (Stack_pop(pilha, &temp))
                printf("%c", temp);
            putchar(' ');
        }
        else 
            if(!Stack_push(pilha, input[i])) {}
    }
    putchar('\n');
    Stack_destroy(pilha);
    return 0;
}