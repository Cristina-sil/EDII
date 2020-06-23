#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/*Fun��o que limpa o buffer de entrada*/
void LimpaBuffer(void);

/* Essa Fun��o l� o n�mero da op��o do menu do usuario, e retorna essa op��o. L� at� que seja v�lido. */
int LeOpcao(int menorValor,int maiorValor);

/* Apresenta menu na tela. */
void ApresentaMenu(int nItens,int menorOpcao,...);

/* Essa Fun��o l� um n�mero do tipo inteiro, faz valida��o e retorna o valor lido. */
int VerificaValor();

/* Essa Fun��o converte uma cadeia de  caracteres completa, para mai�sculo. */
void converte_maiuscula(char* txt);

/* Essa Fun��o l� strings do usu�rio, faz valida��es e retorna a string. */
char* calculaTamString(void);















void LimpaBuffer(void);

//Essa Fun��o l� o n�mero da op��o do menu do usuario, e retorna essa op��o.
int LeOpcao(int menorValor,int maiorValor);

//Apresenta menu na tela
void ApresentaMenu(int nItens,int menorOpcao,...);

//Essa Fun��o l� strings do usu�rio, faz valida��es e retorna a string.
char * calculaTamString(void);

//Essa Fun��o l� um n�mero do tipo inteiro, faz valida��o e retorna o valor lido.
int LeValor (void);

//Essa Fun��o converte uma cadeia de  caracteres completa, para mai�sculo.
void converte_maiuscula (char *txt);



#endif // MENU_H_INCLUDED
