#ifndef PROF_H_INCLUDED
#define PROF_H_INCLUDED

#include "arv.h"

typedef struct prof Prof;
typedef struct noprof NoProf;
typedef struct listaprof ListaProf;

ListaProf* lista_cria();

/*De acordo com os par�mentros recebidos, essa Fun��o cria um n� de professores, e um professor � inserido nesse n�. */
char* arv_crianoProf(ListaProf* prim,int mat,char* nome,char* area,char* titulo);

/* Essa Fun��o verifica se os dados recebidos como par�metro j� se encontram cadastrados na instiui��o. */
int prof_verificaDados(ListaProf* prim,char* nome,int mat);

/* Essa Fun��o verifica se as titula��es informadas pelo usu�rio s�o v�lidas, sendo que so � permitido "Mestrado" e "Doutorado". */
int prof_verificaTitulacao(char* titulo);

/*Essa Fun��o exibe os professorese existentes  cadastrados com titula��o de doutorado, de cada departamento, e imprime a sigla do departamento. */
void imprimeProfD(ListaProf* l,char* siglaDep);

/* Essa Fun��o exibe os professorese existentes  cadastrados com titula��o de mestrado, de cada departamento, e imprime a sigla do departamento. */
void imprimeProfM(ListaProf* l,char* siglaDep);

/*Essa Fun��o verifica se h� exist�ncia de professores cadastrados no departamento. */
int depto_listaProfVazia(ListaProf* l);

/* Salva no arquivo .txt os professores cadastrado no departamento */
void prof_imprimeArq(ListaProf* l,FILE* arq,char* sigla);

/* Essa Fun��o libera os professores do departamento.*/
void prof_libera(ListaProf* l);

#endif // PROF_H_INCLUDED
