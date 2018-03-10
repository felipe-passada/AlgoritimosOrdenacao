#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "libFuncoes.h"

int main(){

    setlocale(LC_ALL, "portuguese");

    int opt;

    do{
        imprime_menu();
        opt = solicita_opcao();
        redireciona_para_opcao(opt);
    }while(opt);



    return 0;
}
