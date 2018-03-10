#include "Arquivos.h"
#include "Estrutura.h"
#include "AuxLibs/quick.h"
#include "AuxLibs/ArvoreLLRB.h"
#include "AuxLibs/arvoreAVL.h"
#include "AuxLibs/tempo.h"

/* Procedimento de impressão do menu e suas opções */
void imprime_menu();

/* Função de solicitação de opção para menu principal */
int solicita_opcao();

/* Procedimento de pausa do sistema (Aguarda até que usuário pressione o botão <Enter>) */
void aguarda_enter();

/*Procedimento para imprir o submenu*/
void imprime_sub_menu();

void redireciona_para_opcao(int opt);

int abre_arquivo();

double insereDesordenado();
double insereOrdenado();




