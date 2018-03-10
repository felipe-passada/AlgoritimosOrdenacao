#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "libFuncoes.h"
#include <time.h>


void aguarda_enter(){
    printf("\n\nDigite <enter> para continuar...");
    getchar();
    getchar();
}

void imprime_menu(){
    system("cls");


    printf("/--------------- TESTE DE ORDENA��O---------------\\\n");
    printf("|                                                  |\n");
    printf("|--------------------- OP��ES ---------------------|\n");
    printf("|                                                  |\n");
    printf("| 1 - Iniciar Teste Inser��o Ordenado              |\n");
    printf("| 2 - Iniciar Teste Inser��o Desordenado           |\n");
    printf("| 0 - Sair                                         |\n");
    printf("|                                                  |\n");
    printf("\\--------------------------------------------------/\n");
}

int solicita_opcao(){
    int opt, cont = 0;

    do{ //Roda do while at� digitar uma op��o v�lida.
        if(cont > 0){
            printf("\nOp��o inv�lida! Digite a op��o desejada: ");
            scanf("%d", &opt);
        }else{
            printf("\nDigite a op��o desejada: ");
            scanf("%d", &opt);
        }

        cont++;
    }while(opt < 0 || opt > 4);

    return opt;
}

//Redireciona para op��o escolhida
void redireciona_para_opcao(int opt){
    int dados, i;

    switch(opt){ //Verifica qual op��o foi selecionada e redireciona para m�dulos respons�veis pela execu��o.
        case 1:
            system("cls");
            printf(" -- Teste dados ordenados --\n");
            insereOrdenado();
            aguarda_enter();
        break;
        case 2:
            system("cls");
            printf(" -- Teste dados desordenado --\n");
            insereDesordenado();
            aguarda_enter();
        break;

    }
}
double insereOrdenado(){
    //Extra��o de dados do arquivo para struct
    PESSOA *ps = listaPessoas(14999);

    //extrai os dados do arquivo csv e passa para estrutura
    ler_arquivo(ps);
    //ordena a estrutura
    Ordena_quickSort(ps, 14999, 1);

    //gera_Arquivo_Ordenado(ps);
    gera_arquivo(ps);

    clock_t tempoInicio, tempoFim;
    tempoInicio = retornaTempo();

    //INSER��O NA ARVORE RUBRO NEGRA
    arvoreLLRB *raizLLRB;
    raizLLRB = cria_arvoreLLRB();

    //INSER�� NA ARVORE AVL
    arvoreAVL *raizAVL;
    raizAVL = cria_arvoreAVL();

    int i;
        while(i < 14999){
            insere_arvoreAVL(raizAVL, ps[i]);
            insere_arvoreLLRB(raizLLRB, ps[i]);
            i++;
        }
    liberar_arvoreLLRB(raizLLRB);
    liberar_arvoreAVL(raizAVL);

    tempoFim = retornaTempo();

    double CalculoTempo = calculaTempo(tempoInicio, tempoFim);

    printf("Tempo gasto: %lf segundos.", CalculoTempo);
    printf("\n");

}

double insereDesordenado(){
    //Extra��o de dados do arquivo para struct
    PESSOA *ps = listaPessoas(14999);

    ler_arquivo(ps);

    clock_t tempoInicio, tempoFim;
    tempoInicio = retornaTempo();

    //INSER��O NA ARVORE RUBRO NEGRA
    arvoreLLRB *raizLLRB;
    raizLLRB = cria_arvoreLLRB();

    //INSER�� NA ARVORE AVL
    arvoreAVL *raizAVL;
    raizAVL = cria_arvoreAVL();

    int i;
        while(i < 14999){
            insere_arvoreAVL(raizAVL, ps[i]);
            insere_arvoreLLRB(raizLLRB, ps[i]);
            i++;
        }
    liberar_arvoreLLRB(raizLLRB);
    liberar_arvoreAVL(raizAVL);

    tempoFim = retornaTempo();

    double totalTempo = calculaTempo(tempoInicio, tempoFim);

    printf("Tempo gasto: %lf segundos.", totalTempo);
    printf("\n");
}
