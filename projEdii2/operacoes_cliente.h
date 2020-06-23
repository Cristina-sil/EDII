#ifndef OPERACOES_CLIENTE_H_INCLUDED
#define OPERACOES_CLIENTE_H_INCLUDED

/* Essa fun��o cadastra o professor, com todas as valida��es necess�rias(estas tendo sido feitas dentro dessa fun��o) */
void prof_cadastro(Inst* arv);

/* Essa fun��o cadastra o departamento, com todas as valida��es necess�rias(estas tendo sido feitas dentro dessa fun��o) */
void depto_cadastro(Inst* arv);
/* Faz a listagem dos professores detentores do titulo de Mestre */
void prof_mestrado_listagem(Inst* arv);

/* Faz a listagem dos professores detentores do titulo de Mestre */
void prof_doutorado_listagem(Inst* arv);

/* libera todas as estruturas */
void libera_estruturas(Inst* arv);

/* Salva todos os dados no arquivo. � chamada na main*/
void salvar_dados_em_arquivo(Inst* arv);
#endif // OPERACOES_CLIENTE_H_INCLUDED
