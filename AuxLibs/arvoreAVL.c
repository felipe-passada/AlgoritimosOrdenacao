#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

struct NO{
    PESSOA ps;
    int alt; //inclui altura da sub-arvore
    struct NO *esq;
    struct NO *dir;
};

arvoreAVL *cria_arvoreAVL(){
    arvoreAVL *raiz = (arvoreAVL*) malloc(sizeof(arvoreAVL));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

//Funções Axiliares

int alt_no(struct NO *no){
    if(no == NULL){
        return -1;
    }else{
        return no->alt;
    }
}

int fatorBalanceamento_NO(struct NO *no){
    return labs(alt_no(no->esq) - alt_no(no->dir));
}

int maior(int x, int y){
    if(x > y){
        return(x);
    }else{
        return(y);
    }
}

void rotacaoLL(arvoreAVL *raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->esq), (*raiz)->alt + 1);
    *raiz = no;
}

void rotacaoRR(arvoreAVL *raiz){
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->dir), (*raiz)->alt + 1);
    *raiz = no;
}

void rotacaoLR(arvoreAVL *raiz){
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(arvoreAVL *raiz){
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

/*Fim Funcoes Auxiliares*/

 void liberar_arvoreAVL(arvoreAVL *raiz){
        if(raiz == NULL){
            return;
        }
        libera_NO(*raiz);
        free(raiz);
}

void libera_NO(struct NO *no){
    if(no == NULL){
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

int vazia_arvoreAVL(arvoreAVL *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int altura_arvoreAVL(arvoreAVL *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_arvoreAVL(&((*raiz)->esq));
    int alt_dir = altura_arvoreAVL(&((*raiz)->dir));
    if(alt_esq > alt_dir){
        return(alt_esq + 1);
    }else{
        return(alt_dir + 1);
    }
}

int totalNO_arvoreAVL(arvoreAVL *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = totalNO_arvoreAVL(&((*raiz)->esq));
    int alt_dir = totalNO_arvoreAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

void preOrdem_arvoreAVL(arvoreAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->ps);
        preOrdem_arvoreAVL(&((*raiz)->esq));
        preOrdem_arvoreAVL(&((*raiz)->dir));
    }
}

void emOrdem_arvoreAVL(arvoreAVL *raiz){
    if(raiz == NULL){
       return;
    }
    if(*raiz != NULL){
        emOrdem_arvoreAVL(&((*raiz)->esq));
        printf("%d\n", (*raiz)->ps);
        emOrdem_arvoreAVL(&((*raiz)->dir));
    }
}

void posOrdem_arvoreAVL(arvoreAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem_arvoreAVL(&((*raiz)->esq));
        posOrdem_arvoreAVL(&((*raiz)->dir));
        printf("%d\n", (*raiz)->ps);
    }
}

int insere_arvoreAVL(arvoreAVL *raiz, PESSOA ps){
    int res; //pega resposta das chamadas da funcao
    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL){
            return 0;
        }
        novo->ps = ps;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    struct NO *atual = *raiz;
    if(ps.id < atual->ps.id){
        if((res = insere_arvoreAVL(&(atual->esq), ps)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(ps.id < (*raiz)->esq->ps.id){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }else{
        if(ps.id > atual->ps.id){
            if((res = insere_arvoreAVL(&(atual->dir), ps)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if((*raiz)->dir->ps.id < ps.id){
                        rotacaoRR(raiz);
                    }else{
                        rotacaoRL(raiz);
                    }
                }
            }
        }else{
            return 0;
        }
    }
    atual->alt = maior(alt_no(atual->esq), alt_no(atual->dir)) + 1;
    return res;
}

struct NO *procuramenor(struct NO *atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_arvoreAVL(arvoreAVL *raiz, PESSOA ps){
    if(*raiz == NULL){
        return 0;
    }
    int res;
    if(ps.id < (*raiz)->ps.id){
        if((res = remove_arvoreAVL(&(*raiz)->esq, ps)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(alt_no((*raiz)->dir->esq <= alt_no((*raiz)->dir->dir))){
                    rotacaoRR(raiz);
                }else{
                    rotacaoRL(raiz);
                }
            }
        }
    }
    if((*raiz)->ps.id < ps.id){
        if((res = remove_arvoreAVL(&(*raiz)->dir, ps)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }
    if((*raiz)->ps.id == ps.id){
        if(((*raiz)->esq == NULL) || (*raiz)->dir == NULL){
            struct NO *no_velho = (*raiz);
            if((*raiz)->esq != NULL){
                *raiz = (*raiz)->esq;
            }else{
                *raiz = (*raiz)->dir;
            }
            free(no_velho);
        }else{
            struct NO *temp = procuramenor((*raiz)->dir);
            (*raiz)->ps.id = temp->ps.id;
            remove_arvoreAVL( (*raiz)->dir,(*raiz)->ps);
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
        if(*raiz != NULL){
            (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
        }
        return 1;
    }
    if(*raiz != NULL){
        (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    }
    return res;
}

int consulta_arvoreAVL(arvoreAVL *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->ps.id){
            return 1;
        }
        if(valor > atual->ps.id){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}
