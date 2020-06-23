#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "menu.h"
#include "arv.h"
#include "prof.h"

void depto_cadastro(Inst* arv){
    char depNome[51], depSigla[11];
    int verificacaoDep=0;

    system("cls");
    printf("====================================");
	printf("\n|TELA DE CADASTRO DE UM DEPARTAMENTO|\n");
	printf("====================================\n");

    printf("\nInforme o nome do Departamento: ");
    strcpy(depNome,calculaTamString());


    printf("\nInforme a sigla do Departamento: ");
    strcpy(depSigla,calculaTamString());
    converte_maiuscula(depSigla);

    if(!arv_vazia(arv)){
        verificacaoDep=verifica_duplicacaoDep(arv,depNome,depSigla);
        while(verificacaoDep!=0){
            if(verificacaoDep==1){
                    system("cls");
                    printf("Já existe Departamento com esse Nome e Sigla cadastrados. Redefina-os para prosseguir.");
                    printf("\nInforme o nome do Departamento: ");
                    strcpy(depNome,calculaTamString());

                    printf("\nInforme a sigla do Departamento: ");
                    strcpy(depSigla,calculaTamString());
                    converte_maiuscula(depSigla);

                    verificacaoDep=verifica_duplicacaoDep(arv,depNome,depSigla);
                }else if(verificacaoDep==2){
                    system("cls");
                    printf("Já existe Departamento com esse Nome cadastrado. Redefina a Nome para prosseguir.");
                    printf("\nInforme o nome do Departamento: ");
                    strcpy(depNome,calculaTamString());
                    verificacaoDep=verifica_duplicacaoDep(arv,depNome,depSigla);
                }else if(verificacaoDep==3){
                    system("cls");
                    printf("Já existe Departamento com essa Sigla cadastrado. Redefina a Sigla para prosseguir.");
                    LimpaBuffer();
                    printf("\nInforme a sigla do Departamento: ");
                    strcpy(depSigla,calculaTamString());
                    converte_maiuscula(depSigla);
                    verificacaoDep=verifica_duplicacaoDep(arv,depNome,depSigla);
                }
        }
    }
    NoDep* dep=arv_crianoDep(depNome,depSigla);
    system("cls");
    arv_insereDep(arv,dep);
}


void prof_cadastro(Inst* arv){

    char profNome[121],profArea[51],profTitulo[15],profDep[51];
    int profMat,verificacaoProf,titulacao;

    system("cls");
    printf("====================================");
	printf("\n|TELA DE CADASTRO DE UM PROFESSOR|\n");
	printf("====================================\n");

	if(!arv_vazia(arv)){
        printf("Escolha um dos Departamentos listados abaixo:\n");
        arv_imprimeDep(arv);
        scanf("%50[^\n]s",profDep);
        NoDep* nodep=arv_busca(arv,profDep);

        while(nodep==NULL){
            system("cls");
            printf("Departamento não encontrado.\nEscolha um dos Departamentos listados abaixo, novamente:\n");
            arv_imprimeDep(arv);
            LimpaBuffer();
            scanf("%50[^\n]s",profDep);
            nodep=arv_busca(arv,profDep);
        }
        LimpaBuffer();

        printf("\nInforme o nome do(a) professor(a):");
        strcpy(profNome,calculaTamString());
        converte_maiuscula(profNome);

        profMat=VerificaValor();

        printf("\nInforme a área de atuação do(a) professor(a): ");
        LimpaBuffer();
        strcpy(profArea,calculaTamString());


        printf("\nInforme a titulação do(a) professor(a): ");
        scanf("%14[^\n]s",profTitulo);
        titulacao=prof_verificaTitulacao(profTitulo);

        while(titulacao!=0){
            printf("\nNome de Titulação inválido.\nCadastre um Professor cuja titulação seja\nI-Doutorado/doutorado\nII-Mestrado/mestrado\n");
            printf("\nInforme novamente a titulação do professor: ");
            LimpaBuffer();
            scanf("%14[^\n]s",profTitulo);
            titulacao=prof_verificaTitulacao(profTitulo);
        }

        verificacaoProf=verifica_duplicacaoProf(arv,profNome,profMat);

        while(verificacaoProf!=0){
            if(verificacaoProf==1){
                system("cls");
                printf("Já existe professor com esse Nome e Matrícula cadastrados. Redefina-os para prosseguir.");
                printf("\nInforme o nome do professor: ");
                LimpaBuffer();
                scanf("%120[^\n]s",profNome);
                converte_maiuscula(profNome);

                profMat=VerificaValor();

                verificacaoProf=verifica_duplicacaoProf(arv,profNome,profMat);

            }else if(verificacaoProf==2){
                system("cls");
                printf("Já existe professor com essa Matrícula cadastrado. Redefina a Matricula para prosseguir");
                profMat=VerificaValor();

                verificacaoProf=verifica_duplicacaoProf(arv,profNome,profMat);
            }else if(verificacaoProf==3){
                system("cls");
                printf("Já existe professor com esse Nome cadastrado. Redefina o Nome para prosseguir.");
                printf("\nInforme o nome do professor: ");
                LimpaBuffer();
                scanf("%120[^\n]s",profNome);
                converte_maiuscula(profNome);

                verificacaoProf=verifica_duplicacaoProf(arv,profNome,profMat);
            }
        }
       arv_insereProf(nodep,profMat,profNome,profArea,profTitulo);
       system("Pause");
       system("cls");
    }else{
        printf("Ainda não há departamentos cadastrados.\nCadastre-os primeiro, antes de tentar inserir um Professor.\n\n");
    }
}

void prof_mestrado_listagem(Inst* arv){
    system("cls");
    printf("=========================\n");
    printf("|PROFESSORES COM MESTRADO|");
    printf("\n=========================\n");
    arv_imprimeProfMestrado(arv);
    system("pause");
    system("cls");
}


void prof_doutorado_listagem(Inst* arv){
    system("cls");
    printf("==========================\n");
    printf("|PROFESSORES COM DOUTORADO|");
    printf("\n==========================\n");
    arv_imprimeProfDoutorado(arv);
    system("pause");
    system("cls");
}

void libera_estruturas(Inst* arv){
    arv_libera(arv);
}

void salvar_dados_em_arquivo(Inst* arv){
    arv_armazenaNoArquivo(arv);
}
