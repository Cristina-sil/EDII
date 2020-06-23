#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"
#include "prof.h"

struct dep{
    char nomeDep[50];
    char sigla[10];
};

struct nodep{
    Dep* depto;
    ListaProf* primProf;
    NoDep* proxDep;
};

struct inst{
    Inst* prox;
    char nome[81];
    char sigla[10];
    NoDep* prim;
};


Inst* arv_cria(){
    Inst* arvore=(Inst*)malloc(sizeof(Inst));
    if(arvore==NULL){
        printf("Sem memória suficiente!n\n");
        exit(1);
    }
    strcpy(arvore->nome,"Universidade Federal Rural do Semi-Árido");
    strcpy(arvore->sigla,"UFERSA");
    arvore->prim=NULL;
    arvore->prox=NULL;
    return arvore;
}

static Dep* depto_cria(char* nome,char* sigla){
    Dep* dep=(Dep*)malloc(sizeof(Dep));
    if(dep==NULL){
        printf("Sem memória Suficiente!\n");
        exit(1);
    }
    strcpy(dep->nomeDep,nome);
    strcpy(dep->sigla,sigla);
    return dep;
}

NoDep* arv_crianoDep(char* nome,char* sigla){
    NoDep* novo=(NoDep*)malloc(sizeof(NoDep));
    if(novo==NULL){
        printf("memoria insuficiente!\n");
        exit(1);
    }

    Dep* dep=depto_cria(nome,sigla);

    novo->depto=dep;
    novo->proxDep=NULL;
    novo->primProf=lista_cria();
    return novo;
}

void arv_insereDep(Inst* inst, NoDep* sa){
    sa->proxDep=inst->prim;
    inst->prim=sa;
    printf("\nO Departamento %s(%s) foi cadastrado com sucesso!\n\n",sa->depto->nomeDep,sa->depto->sigla);
}


void arv_imprimeDep(Inst* r){
    NoDep* aux;
    printf("\nDEPARTAMENTOS CADASTRADOS\n");
    for(aux=r->prim;aux!=NULL;aux=aux->proxDep){
        printf(" - %s\n\n",aux->depto->nomeDep);
    }
}


void arv_insereProf(NoDep* r,int mat,char* nome,char* area,char* titulo){
    char* novo=arv_crianoProf(r->primProf,mat,nome,area,titulo);
    printf("\nO(A) Professor(a) %s foi cadastrado(a) com sucesso!\n",novo);
}


NoDep* arv_busca(Inst* r,char* nomeDep){
    NoDep* aux;
    for(aux=r->prim;aux!=NULL;aux=aux->proxDep){
        if(strcmp(aux->depto->nomeDep,nomeDep)==0){
            return aux;
        }
    }
    return NULL;

}


int verifica_duplicacaoProf(Inst* a,char* nome,int mat){
    NoDep* aux;
    int r=0;
    for(aux=a->prim;aux!=NULL;aux=aux->proxDep){
        r=prof_verificaDados(aux->primProf,nome,mat);
        if(r==1 || r==2 || r==3)
            return r;

    }
    return r;
}


int arv_vazia(Inst* arv){
    if(arv->prim==NULL)
        return 1;
    else
        return 0;
}

int verifica_duplicacaoDep(Inst* a,char* nome,char* sigla){
    NoDep* aux;
    for(aux=a->prim;aux!=NULL;aux=aux->proxDep){
        if(strcmp(aux->depto->nomeDep,nome)==0 && strcmp(aux->depto->sigla,sigla)==0){
            return 1;
        }else if(strcmp(aux->depto->nomeDep,nome)==0){
            return 2;
        }else if(strcmp(aux->depto->sigla,sigla)==0){
            return 3;
        }
    }
    return 0;
}

void arv_imprimeProfMestrado(Inst* a){
    NoDep* aux;
    if(!arv_vazia(a)){
        for(aux=a->prim;aux!=NULL;aux=aux->proxDep){
            if(depto_listaProfVazia(aux->primProf)!=1){
               imprimeProfM(aux->primProf,aux->depto->sigla);
            }
        }
    }else{
        printf("Não há nenhum Departamento cadastrado, e portanto também não há Professores a serem listados.\n");
    }
}


void arv_imprimeProfDoutorado(Inst* a){
    NoDep* aux;
    if(!arv_vazia(a)){
        for(aux=a->prim;aux!=NULL;aux=aux->proxDep){
            if(depto_listaProfVazia(aux->primProf)!=1){
                imprimeProfD(aux->primProf,aux->depto->sigla);
            }
        }
    }else{
        printf("Não há nenhum Departamento cadastrado, e portanto também não há Professores a serem listados.\n");
    }
}

void arv_armazenaNoArquivo(Inst* a){
    NoDep* aux;
    FILE* arq;
    if(!arv_vazia(a)){
        arq=fopen("InstituicaoUFERSA.txt","w");
        if(arq==NULL){
            printf("erro\n");
            return EXIT_FAILURE;
        }
        for(aux=a->prim;aux!=NULL;aux=aux->proxDep){
            if(!depto_listaProfVazia(aux->primProf)){
               prof_imprimeArq(aux->primProf,arq,aux->depto->sigla);
            }else{
                printf("Nenhum Professor do Departamento [%s] foi enviado ao arquivo, pois o mesmo se encontra vazio.\n",aux->depto->sigla); //dizer qual dep deu erro
            }
        }
        fclose(arq);

    }else{
        system("cls");
        printf(" - Não há dados/Departamentos cadastrados no sistema ainda. Não há nada para ser salvo.\n\n");
    }
}

void arv_libera(Inst* arv){
    if(!arv_vazia(arv)){
        NoDep* p=arv->prim;
        while(p!=NULL){
            free(p->depto);
            prof_libera(p->primProf);
            NoDep* t=p->proxDep;
            free(p);
            p=t;
        }
    }
    free(arv);

}







