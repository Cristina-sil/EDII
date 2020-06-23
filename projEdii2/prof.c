#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "prof.h"


struct prof{
    int mat;
    char nome[121];
    char area[121];
    char titulo[31];
};

struct noprof{
    Prof* prof;
    NoProf* prox;
};

struct listaprof{
    NoProf* prim;
};



ListaProf* lista_cria(){
    ListaProf* l=(ListaProf*)malloc(sizeof(ListaProf));
    if(l==NULL){
        printf("sem memória suficiente!\n");
        exit(1);
    }
    l->prim=NULL;
    return l;
}

static Prof* prof_cria(int mat,char* nome,char* area,char* titulo){
    Prof* prof=(Prof*)malloc(sizeof(Prof));
    if(prof==NULL){
        printf("Sem memória suficiente!\n");
        exit(1);
    }
    prof->mat=mat;
    strcpy(prof->area,area);
    strcpy(prof->nome,nome);
    strcpy(prof->titulo,titulo);

    return prof;
}

char* arv_crianoProf(ListaProf* l,int mat,char* nome,char* area,char* titulo){
    NoProf* no=(NoProf*)malloc(sizeof(NoProf));
    if(no==NULL){
        printf("Sem memória suficiente!\n");
        exit(1);
    }

    NoProf* aux;
    Prof* prof=prof_cria(mat,nome,area,titulo);
    no->prof=prof;
    if (l->prim==NULL || strcmp(l->prim->prof->nome,nome)>=0)
    {
        no->prox = l->prim;
        l->prim = no;
    }
    else
    {
        aux = l->prim;
        while (aux->prox!=NULL &&
             strcmp(aux->prox->prof->nome, no->prof->nome)<0)
        {
            aux = aux->prox;
        }
        no->prox = aux->prox;
        aux->prox = no;
    }

    return nome;

}



int prof_verificaDados(ListaProf* l,char* nome,int mat){//verifica validade dos dados
    NoProf* aux;
    for(aux=l->prim;aux!=NULL;aux=aux->prox){
        if(strcmp(aux->prof->nome,nome)==0 && aux->prof->mat==mat){
            return 1;
        }else if(aux->prof->mat==mat){
            return 2;
        }else if(strcmp(aux->prof->nome,nome)==0){
            return 3;
        }
    }
    return 0;
}

int prof_verificaTitulacao(char* titulo){
   if( (strcmp(titulo,"mestrado")==0) || (strcmp(titulo,"Mestrado")==0) || (strcmp(titulo,"doutorado")==0) || (strcmp(titulo,"Doutorado")==0)) {
       return 0;
   }
   return 1;
}

void imprimeProfD(ListaProf* l,char* siglaDep){
    NoProf* aux;
    int sigla=1;
    for(aux=l->prim;aux!=NULL;aux=aux->prox){
        if((strcmp(aux->prof->titulo,"doutorado")==0) || (strcmp(aux->prof->titulo,"Doutorado")==0)){
            if(sigla==1){
                printf("%s\n",siglaDep);
                sigla=2;
            }
            printf("%s\n",aux->prof->nome);
        }
    }
    printf("\n");
}
void imprimeProfM(ListaProf* l,char* siglaDep){
    NoProf* aux;
    int sigla=1;
    for(aux=l->prim;aux!=NULL;aux=aux->prox){
        if((strcmp(aux->prof->titulo,"mestrado")==0) || (strcmp(aux->prof->titulo,"Mestrado")==0)){
            if(sigla==1){
                printf("%s\n",siglaDep);
                sigla=2;
            }
            printf("%s\n",aux->prof->nome);
        }
    }
    printf("\n");
}

int depto_listaProfVazia(ListaProf* l){
    if(l->prim==NULL){
        return 1;
    }else{
        return 0;
    }
}

static char* nome_formatado_para_arquivo (char *STRING){

    int i;
    char* string = (char*)malloc(sizeof(char));
    strcpy(string,STRING);
    strlwr(string);

    for (i = 0; i < strlen(string) + 1; i++) {
        if (i == 0 || string[i - 1] == ' ')
            string[i] = toupper(string[i]);
        else
            string[i] = string[i];
    }

    return string;
}

void prof_imprimeArq(ListaProf* l,FILE* arq,char* sigla){
    char nome[121];
    char area[121];
    char titulo[31];
    NoProf* aux;
    int v=10;
    for(aux=l->prim;aux!=NULL;aux=aux->prox){
        if(v==10){
            fprintf(arq,"%s\n",sigla);
            v=11;
        }
        strcpy(nome,nome_formatado_para_arquivo(aux->prof->nome));
        strcpy(area,nome_formatado_para_arquivo(aux->prof->area));
        strcpy(titulo,nome_formatado_para_arquivo(aux->prof->titulo));
        fprintf(arq,"%s\t%s\t%s\n",nome,area,titulo);
    }
    printf("Os dados do Departamento [%s] foram salvos com sucesso de forma permanente no arquivo.\n",sigla);
}

void prof_libera(ListaProf* l){
    if(!depto_listaProfVazia(l)){
        NoProf* t=l->prim;
        while(t!=NULL){
            free(t->prof);
            NoProf* aux=t->prox;
            free(t);
            t=aux;
        }
        free(l);
    }
}
