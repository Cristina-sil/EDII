#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/*Função que limpa o buffer de entrada*/
void LimpaBuffer(void);

/* Essa Função lê o número da opção do menu do usuario, e retorna essa opção. Lê até que seja válido. */
int LeOpcao(int menorValor,int maiorValor);

/* Apresenta menu na tela. */
void ApresentaMenu(int nItens,int menorOpcao,...);

/* Essa Função lê um número do tipo inteiro, faz validação e retorna o valor lido. */
int VerificaValor();

/* Essa Função converte uma cadeia de  caracteres completa, para maiúsculo. */
void converte_maiuscula(char* txt);

/* Essa Função lê strings do usuário, faz validações e retorna a string. */
char* calculaTamString(void);















void LimpaBuffer(void);

//Essa Função lê o número da opção do menu do usuario, e retorna essa opção.
int LeOpcao(int menorValor,int maiorValor);

//Apresenta menu na tela
void ApresentaMenu(int nItens,int menorOpcao,...);

//Essa Função lê strings do usuário, faz validações e retorna a string.
char * calculaTamString(void);

//Essa Função lê um número do tipo inteiro, faz validação e retorna o valor lido.
int LeValor (void);

//Essa Função converte uma cadeia de  caracteres completa, para maiúsculo.
void converte_maiuscula (char *txt);



#endif // MENU_H_INCLUDED
