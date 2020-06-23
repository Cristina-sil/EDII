#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

#include "menu.h"
#include "arv.h"

void LimpaBuffer(void){
    int valorLido;
    do{
        valorLido=getchar();
    }while((valorLido!='\n') && (valorLido !=EOF));
}

int LeOpcao(int menorValor,int maiorValor){
    int op;
    while(1){
        printf("\nDigite sua opção:");
        op=getchar();
        if(op>=menorValor && op<=maiorValor){
            LimpaBuffer();
            break;
        }else{
            printf("\nOpção inválida. Tente Novamente.\n");
            printf("\nA opção deve estar entre %c e %c.\n",menorValor,maiorValor);
        }
    }

    return op;
}

void ApresentaMenu(int nItens,int menorOpcao,...){
    int i;
    va_list argumentos;
    va_start(argumentos,menorOpcao);
    for(i=0;i<nItens;i++){
        printf("%c - %s\n",menorOpcao++,va_arg(argumentos,char *));
    }
    va_end(argumentos);
}

int VerificaValor(){
    int valor;
    do{
        printf("\nInforme a Matrícula do(a) Professor(a) no formato [XXXXX](5 digítos):");
        scanf("%d", &valor);
        if(valor >= 10000 && valor <= 99999){
            valor=valor;
        }else{
            printf("\nEntrada incorreta.");
            LimpaBuffer();
        }
    }while(valor < 10000 || valor > 99999);
return valor;
}


void converte_maiuscula(char* txt){
    strupr(txt);
}

static int validacao_string(char *string){
    int x, cont = 0;
    for ( x = 0; x < strlen(string);x++){
        if((!isalpha(string[x])) && (string[x]!=' ')){
            cont = 1;
            break;
        }
    }
    return cont;
}

char* calculaTamString(void){
    int tam,alfabeto;
    char* string = (char*)malloc(121*sizeof(char));
    if (string == NULL){
        printf("Memória insuficiente\n");
        exit(1);
    }
    scanf("%[^\n]s",string);
    tam =strlen(string);
    while (tam==0){
        LimpaBuffer();
        printf("\nCampo vázio é inválido!\n");
        printf("Preencha novamente: ");
        scanf("%[^\n]s",string);
        tam = strlen(string);

    }
    alfabeto = validacao_string(string);
    while (alfabeto!=0){
        LimpaBuffer();
        printf("Informação fornecida não é válida não é válida!\n");
        printf("Preencha novamente:\n");
        scanf("%[^\n]s",string);
        alfabeto = validacao_string(string);
    }

    LimpaBuffer();
    return string;
}





