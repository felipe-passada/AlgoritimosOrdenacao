#include "Estrutura.h"
int listaPessoas(int size){
    PESSOA *pessoa = (PESSOA*) calloc(size, sizeof(PESSOA));
    return pessoa;
}

void liberaPessoas(PESSOA *pessoa){
    free(pessoa);
}
