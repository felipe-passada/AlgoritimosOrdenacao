#include <stdio.h>
#include <stdlib.h>
#include "tempo.h"

double calculaTempo(clock_t tempoInicio, clock_t tempoFim){
    //FAZ DIFERENCA ENTRE TEMPO ANTIGO E TEMPO NOVO E TRAZ O TEMPO GASTO
    double tempoCalculado = ( (double) (tempoFim - tempoInicio) ) / CLOCKS_PER_SEC;
         //printf("Tempo gasto: %lf segundos.", tempo);
    return tempoCalculado;

}

clock_t retornaTempo(){
    //RETORNA TEMPO ATUAL
    return clock();
}
