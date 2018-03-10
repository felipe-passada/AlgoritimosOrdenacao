#include "Arquivos.h"
#include "Estrutura.h"
#include "AuxLibs/quick.h"
#include "AuxLibs/ArvoreLLRB.h"
#include "AuxLibs/arvoreAVL.h"
#include "AuxLibs/tempo.h"

/* Procedimento de impress�o do menu e suas op��es */
void imprime_menu();

/* Fun��o de solicita��o de op��o para menu principal */
int solicita_opcao();

/* Procedimento de pausa do sistema (Aguarda at� que usu�rio pressione o bot�o <Enter>) */
void aguarda_enter();

/*Procedimento para imprir o submenu*/
void imprime_sub_menu();

void redireciona_para_opcao(int opt);

int abre_arquivo();

double insereDesordenado();
double insereOrdenado();




