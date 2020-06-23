#ifndef PROF_H_INCLUDED
#define PROF_H_INCLUDED

#include "arv.h"

typedef struct prof Prof;
typedef struct noprof NoProf;
typedef struct listaprof ListaProf;

ListaProf* lista_cria();

/*De acordo com os parâmentros recebidos, essa Função cria um nó de professores, e um professor é inserido nesse nó. */
char* arv_crianoProf(ListaProf* prim,int mat,char* nome,char* area,char* titulo);

/* Essa Função verifica se os dados recebidos como parâmetro já se encontram cadastrados na instiuição. */
int prof_verificaDados(ListaProf* prim,char* nome,int mat);

/* Essa Função verifica se as titulações informadas pelo usuário são válidas, sendo que so é permitido "Mestrado" e "Doutorado". */
int prof_verificaTitulacao(char* titulo);

/*Essa Função exibe os professorese existentes  cadastrados com titulação de doutorado, de cada departamento, e imprime a sigla do departamento. */
void imprimeProfD(ListaProf* l,char* siglaDep);

/* Essa Função exibe os professorese existentes  cadastrados com titulação de mestrado, de cada departamento, e imprime a sigla do departamento. */
void imprimeProfM(ListaProf* l,char* siglaDep);

/*Essa Função verifica se há existência de professores cadastrados no departamento. */
int depto_listaProfVazia(ListaProf* l);

/* Salva no arquivo .txt os professores cadastrado no departamento */
void prof_imprimeArq(ListaProf* l,FILE* arq,char* sigla);

/* Essa Função libera os professores do departamento.*/
void prof_libera(ListaProf* l);

#endif // PROF_H_INCLUDED
