#include <stdio.h> // Da acesso ao uso de funcoes de escrita e leitura
#include <stdlib.h> // Disponibiliza funcoes de alocacao  dinamica de memoria, dentre outas
#include <string.h> // Fornece funcoes, macros e definicoes da biblioteca padrao da linguagem da progamacao em C para manipulacao de cadeias de caracteres e regioes de memoria.
#include <conio.h> // Remover se rodar em Linux

// Cria a estrutura da lista
struct Urna{
	char mensagem[64];
	struct Urna *prox;
};
typedef struct Urna node;

// Declaracao das funcoes que serao utilizadas com voids e int
void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
void inserirMensagem(node *LISTA);
void exibirListaCripto(node *LISTA);
void exibirListaDecripto(node *LISTA);
void criptografar(char* mensagem);
void descriptografar(char *mensagem);

// Verifica se ha memoria disponivel
int main(void)
{
	node *LISTA = (node *) malloc(sizeof(node));
 	if(!LISTA){
  		printf("Sem memoria disponivel!\n");
  		exit(1);
 	}
 	inicia(LISTA);
 	int opt;

 	do{
  		opt=menu();
  		opcao(LISTA,opt);
 	}while(opt);

 	free(LISTA);
 	return 0;
}

void inicia(node *LISTA)
{
 	LISTA->prox = NULL;
}
// Definido as opcoes do menu
int menu(void)
{
 	int opt;

	 printf("\nEscolha a opcao\n");
	 printf("0. Sair\n");
	 printf("1. Adicionar mensagem\n");
	 printf("2. Exibir lista cripto\n");
	 printf("3. Exibir decripto\n");
	 printf("Opcao: "); scanf("%d", &opt);

 	return opt;
}

// Definicao das cases para cada opcao
void opcao(node *LISTA, int op)
{
 	switch(op){
  		case 0:
   			break;

		case 1:
   			inserirMensagem(LISTA);
   			break;

  		case 2:
   			exibirListaCripto(LISTA);
   			break;

		case 3:
		   exibirListaDecripto(LISTA);
		   break;


  		default:
   			printf("Comando invalido\n\n");
 	}
}

int vazia(node *LISTA)
{
 	if(LISTA->prox == NULL)
  		return 1;
 	else
  		return 0;
}

// Processo para insercao da mensagem na lista
void inserirMensagem(node *LISTA)
{
 	node *novo=(node *) malloc(sizeof(node));
 	if(!novo){
  		printf("Sem memoria disponivel!\n");
  		exit(1);
 	}

	printf("Nova mensagem: "); scanf("%s", novo->mensagem);
	criptografar(novo->mensagem);
 	novo->prox = NULL;

 	if(vazia(LISTA))
  		LISTA->prox=novo;
 	else{
  		node *tmp = LISTA->prox;

	  	while(tmp->prox != NULL)
	   		tmp = tmp->prox;

	  	tmp->prox = novo;
 	}
}

// Processo para exibir a lista criptografada
void exibirListaCripto(node *LISTA)
{
 	if(vazia(LISTA)){
  		printf("Lista vazia!\n\n");
  		return ;
 	}

 	node *tmp;
 	tmp = LISTA->prox;

 	while( tmp != NULL){
  		printf("%s\n\n", tmp->mensagem);
  		tmp = tmp->prox;
 	}
 	printf("\n\n");
}

// Processo para exibir a lista decriptografada
void exibirListaDecripto(node *LISTA)
{
 	if(vazia(LISTA)){
  		printf("Lista vazia!\n\n");
  		return ;
 	}

 	node *tmp;
 	tmp = LISTA->prox;

 	while( tmp != NULL){
  		char aux[30];
  		strcpy(aux, tmp->mensagem);
  		descriptografar(aux);
		printf("%s\n\n", aux);
  		tmp = tmp->prox;
 	}
 	printf("\n\n");
}

// Processo logico para a criptografia
void criptografar(char* mensagem) {

    int m;
    for(m = 0; m < strlen(mensagem); m++)
    {
        if(mensagem[m] >= 65 && mensagem[m] <= 90) //Letras maiusculas
        {
            mensagem[m] = mensagem[m] + 5;

            if (mensagem[m] > 90)
                mensagem[m] = mensagem[m] - 26;
        }

        else if(mensagem[m] >= 97 && mensagem[m] <= 122) //Letras minusculas
        {
            mensagem[m] = mensagem[m] + 5;

            if (mensagem[m] > 122)
                mensagem[m] = mensagem[m] - 26;

        }


        else if(mensagem[m] >= 48 && mensagem[m] <= 57) //Numeros
        {
            mensagem[m] = mensagem[m] - 3;

            if (mensagem[m] < 48)
                mensagem[m] = mensagem[m] + 10;
        }
    }

    printf("\nMensagem Criptografada ");
    printf("\n");

}

// Processo logico para a decriptografia
void descriptografar(char *mensagem) {

    int m;
    for(m = 0; m < strlen(mensagem); m++)
    {
        if(mensagem[m] >= 65 && mensagem[m] <= 90) //Letras maiusculas
        {
            mensagem[m] = mensagem[m] - 5;

            if (mensagem[m] < 65)
                mensagem[m] = mensagem[m] + 26;
        }

        else if(mensagem[m] >= 97 && mensagem[m] <= 122) //Letras minusculas
        {
            mensagem[m] = mensagem[m] - 5;

            if (mensagem[m] < 97)
                mensagem[m] = mensagem[m] + 26;

        }


        else if(mensagem[m] >= 48 && mensagem[m] <= 57)
		{
			mensagem[m] = mensagem[m] + 3;

			if (mensagem[m] > 57)
				mensagem[m] = mensagem[m] - 10;
		}
    }

	printf("\nMensagem descriptografada: "); //Está imprimindo a mensagem descricriptografada//
	printf("\n");

}
