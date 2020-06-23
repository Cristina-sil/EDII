#ifndef ARV_H_INCLUDED
#define ARV_H_INCLUDED

#include "prof.h"

typedef struct dep Dep;
typedef struct nodep NoDep;
typedef struct arv Arv;
typedef struct inst Inst;

/*Cria a arvore vazia e retorna o endere�o da arvore(instituicao)*/
Inst* arv_cria();

/*Cria um no do tipo departamento,
preechendo os campos deste de acordo com as parametros recebidos, e retorna o endere�o do no alocado*/
NoDep* arv_crianoDep(char* nome,char* sigla);

/* Insere um no do tipo departamento como sendo filha(subArv)do no raiz, que a instituicao. */
void arv_insereDep(Inst* a, NoDep* sa);

/* Imprime uma lista com todos departamentos da institui��o */
void arv_imprimeDep(Inst* r);

/* Busca um departamento na institui��o, pelo seu nome,
e retorna o endere�o do n� no qual o departamento se encontra. Caso n�o exista, retorna NULL */
NoDep* arv_busca(Inst* r,char* nomeDep);

/*Verifica se j� existe um professor cadastrado na institui��o com o nome e matricula recebidos.
Retorna um inteiro para sinalizar.0 para false,e 1,2 ou 3 para o caso de haver duplica��o.
O tratamento � feito em outra fun��o*/
int verifica_duplicacaoProf(Inst* a,char* nome,int mat);

/* Verifica se a arvore cont�m algum departamento. Retorna 1 para true e 0 para false. */
int arv_vazia(Inst* arv);

/* Insere um professor na arvore, de fato, ligando-o a um departamento.
Recebe o departamento no qual vai ser cadastrado e seus dados. */
void arv_insereProf(NoDep* r,int mat,char* nome,char* area,char* titulo);

/*Verifica se j� existe um departamento cadastrado com o nome e sigla recebidos como par�metro.
Retorna um inteiro para sinalizar.0 para false,1 para Nome duplicado e sigla,2 para somente Nome e 3 para Sigla. */
int verifica_duplicacaoDep(Inst* a,char* nome,char* sigla);

/* Imprime os departamentos n�o vazios com todos os professores com titulo de Doutorado */
void arv_imprimeProfDoutorado(Inst* a);

/* Imprime os departamentos n�o vazios com todos professores com titulo de Mestrado */
void arv_imprimeProfMestrado(Inst* a);

/* Essa Fun��o insere em um arquivo .txt as informa��es cadastradas na institui��o,
como Departamento e os professores destes, com seus respectivos dados*/
void arv_armazenaNoArquivo(Inst* a);

/* Libera todo o espa�o de mem�ria que havia sido alocado para institui��o e seus departamentos.
Faz chamada � libera da lista de professores*/
void arv_libera(Inst* arv);



void impri(Inst* a);
#endif // ARV_H_INCLUDED

