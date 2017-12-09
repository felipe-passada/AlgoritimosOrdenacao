#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Arquivos.h"
#include "Estrutura.h"

//Aloca um vetor auxiliar para guardar as structs

void ler_arquivo(PESSOA ps[]){
    FILE *file;
    file = fopen("massaDados.csv", "r");

    if(file == NULL){
        printf("ERRO NA LEITURA ARQUIVO VAZIO");
    }
    char car, str[255];
    //car = 1 caracter
    //str representa uma cadeia de caracteres(no meu programa str representa uma linha)
    //uma linha representa uma pessoa da struct

    int linha = 0, i = 0;
    char *auxId, *auxNm, *auxIdd, auxEmp, *auxDep, *auxSal ;
    do{
        car = fgetc(file);
        if(car == '\n'){ //verifica se o caracter parou no final da linha


            sprintf(str, "%s%c" , str, '\0');

            auxId = strtok(str, ";");
            auxNm = strtok('\0', ";");
            auxIdd = strtok('\0', ";");
            auxEmp = strtok('\0', ";");
            auxDep = strtok('\0', ";");
            auxSal = strtok('\0', ";");

            for(i = 0; i < 255; i++){
                str[i] = '\0';
            }
            i++;
        }else{ //se não a variavel auxiliar junta o caracter com a variavel da linha
            sprintf(str, "%s%c" , str, car);
        }

    }while(car != EOF);
    //printf("%s", str);

    fclose(file);



}

