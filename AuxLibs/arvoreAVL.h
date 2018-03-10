#import "../Estrutura.h"

typedef struct NO *arvoreAVL;

arvoreAVL *cria_arvoreAVL();

void liberar_arvoreAVL(arvoreAVL *raiz);

int vazia_arvoreAVL(arvoreAVL *raiz);

int altura_arvoreAVL(arvoreAVL *raiz);

int totalNO_arvoreAVL(arvoreAVL *raiz);

void preOrdem_arvoreAVL(arvoreAVL *raiz);

void emOrdem_arvoreAVL(arvoreAVL *raiz);

void posOrdem_arvoreAVL(arvoreAVL *raiz);

int insere_arvoreAVL(arvoreAVL *raiz, PESSOA ps);

int remove_arvoreAVL(arvoreAVL *raiz, PESSOA ps);

int consulta_arvoreAVL(arvoreAVL *raiz, int valor);
