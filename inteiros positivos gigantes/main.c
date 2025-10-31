#include "TBigIntList.h"
#include <stdio.h>

int main(){
    TBigIntList *l1 = TBigIntList_converter_string("123123123123123123123121");
    TBigIntList *l2 = TBigIntList_converter_string("1231231028310298301298301298301298301298310298310293812098301283019283012983019283012983019283102983102983102983");

    //teste
    //TBigIntList *l1 = TBigIntList_converter_string("99");
    //TBigIntList *l2 = TBigIntList_converter_string("1");
    
    printf("L1: "); TBigIntList_print(l1);
    printf("L2: "); TBigIntList_print(l2);

    TBigIntList *soma = TBigIntList_somar_listas(l1, l2);
    printf("Soma: "); TBigIntList_print(soma);

    TBigIntList_destroy(&l1);
    TBigIntList_destroy(&l2);
    TBigIntList_destroy(&soma);


    return 0;
}