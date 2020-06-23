#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arv.h"
#include "menu.h"

#include "operacoes_cliente.h"


#define TITULO_OPCAO1 "Cadastrar departamento"
#define TITULO_OPCAO2 "Cadastrar professor(a)"
#define TITULO_OPCAO3 "Listar professores com mestrado"
#define TITULO_OPCAO4 "Listar professores com doutorado"
#define TITULO_OPCAO5 "Salvar dados em arquivo"
#define TITULO_OPCAO6 "Sair do programa"


#define N_OPCOES 6
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'



int main()
{

    setlocale(LC_ALL,"portuguese");
    system("title UNIVERSIDADE FEDERAL RURAL DO SEMI ARIDO - UFERSA");
    Inst* arv=arv_cria();
    unsigned char op;
    unsigned int saida=0;

    do{
        ApresentaMenu(N_OPCOES,OPCAO1,TITULO_OPCAO1,TITULO_OPCAO2,TITULO_OPCAO3,TITULO_OPCAO4,TITULO_OPCAO5,TITULO_OPCAO6);
        fflush(stdin);
        op=LeOpcao(OPCAO1,OPCAO1+N_OPCOES-1);

        switch(op){
        case OPCAO1:
            depto_cadastro(arv);
            break;

        case OPCAO2:
            prof_cadastro(arv);
            break;

        case OPCAO3:
            prof_mestrado_listagem(arv);
            break;

        case OPCAO4:
            prof_doutorado_listagem(arv);
            break;

        case OPCAO5:
            salvar_dados_em_arquivo(arv);
            break;

        case OPCAO6:
            saida=1;
            printf("Obrigada por usar esse programa.\n");

            break;

        default:
            printf("Este Programa possui um bug.\n");
            return 1;
        }

    }while(!saida);
    return 0;
}
