#include "quick.h"
void Ordena_quickSort(struct PESSOA *ps, int inicio,int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(ps, inicio, fim);
        Ordena_quickSort(ps, inicio, pivo - 1);
        Ordena_quickSort(ps, pivo + 1, fim);
    }
}

int particiona(struct PESSOA *ps, int inicio,int fim){
    int esq, dir;
    struct PESSOA pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = ps[inicio];
    while(esq < dir){
        while(ps[esq].id <= pivo.id){
            esq++;
        }
        while(ps[dir].id > pivo.id){
            dir--;
        }
        if(esq < dir){
            aux = ps[esq];
            ps[esq] = ps[dir];
            ps[dir] = aux;
        }

    }
    ps[inicio] = ps[dir];
    ps[dir] = pivo;
    return dir;
}
