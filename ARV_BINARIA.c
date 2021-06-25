#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct NO{ //Definição da struct com informação e 2 ponteiros.
	int info; //Informação.
	struct NO* esq; //Ponteiro para esquerda.
	struct NO* dir; //Ponteiro para a direita.
};

typedef struct NO node; //Renomeando a struct.

void imprime(node* Arv){ //Função imprime a ordem da arvore.
	if( Arv != NULL){ //Se a arvore for diferente de nulo.
		imprime(Arv->esq); //Imprime arvore da esquerda.
		printf("%d ",Arv->info); //Imprime a raiz
		imprime(Arv->dir); //Imprime a arvore da direita.
	}
}


node* insere (node* Arv, int info){ //Função para inserir elementos em uma arvore binaria.
	if( Arv == NULL){ //Verifica se a arvore é variavel.
		Arv = (node*)malloc(sizeof(node)); //Se for vazio ele aloca um novo NO.
		Arv->info = info; //o NO recebe a informação digitada para o NO.
		Arv->esq = NULL; //Lado esquerdo aponta pra null.
		Arv->dir = NULL; //Lado direito aponta pra null.
	}else if(info < Arv->info){ //Se a arvore não for vazia ele verifica se o valor inserido é menor que a informação atual do NO.
		Arv->esq = insere(Arv->esq,info); //Se a informação for menor, ele aloca e insere um NO a esquerda na arvore.
	}else if(info > Arv->info){ //Se a arvore não for vazia ele verifica se o valor inserido é maior que a informação atual do NO.
		Arv->dir = insere(Arv->dir,info); //Se a informação for maior, ele aloca e insere um NO a direita da arvore.
	}
	return Arv; //Retorna os NO's.
}

node* retira (node* ret, int info){ //Função que retira um NO de uma arvore.
	if(ret == NULL){ //Se a arvore ainda não esxistir.
		return NULL; //Ele retora null.
	}else if(ret->info > info){ //Senão ele verifica se o valor passado é maior que o vavlor que vai ser excluido.
		ret->esq = retira(ret->esq, info); //Se for ele percorre a arvore da esquerda.
		}else if(ret->info < info){ //Senão ele verifica se o valor passado é menor que o valor que vai ser excluido.
			ret->dir = retira(ret->dir, info); //Se for ele percorre a arvore da direita.
		}else{
			if(ret->esq == NULL && ret->dir == NULL){ //Se esquerda e direita for null.
				free(ret); //Libera o NO.
				ret = NULL; //Recebe null.
			}else if(ret->esq == NULL){ //Sub arvore da esquerda não é null.
				node* aux = ret; //Cria uma auxiliar que recebe o valor do NÓ que sera apagado.
				ret = ret->dir; //R recebe o valor do filho a direita.
				free(aux); //Libera o NO.
			}else if(ret->dir == NULL){ //Sub arvore da direita não é null.
				node* aux = ret; //Cria um auxiliar que recebe o valor do NO que sera apagado.
				ret = ret->esq; //R recebe o valor do filho a esquerda.
				free(aux); //Libera o NO.
			}
		}
	return ret; //Retorna os NO's.
}



int main(){
	setlocale(LC_ALL, "portuguese"); //Cola os pontos no portugues.
	int valor; //Variável que recebe o valor digitado pelo usuário.
	int op; //Variável que recebe a opção digitada pelo usuário.
	
	node* Arv = NULL; //Inicia a arvore como null.
	
	printf("O que você deseja fazer na arvore?\n"); //Menu de opções.
	printf("1 - Incluir elemento!\n");
	printf("2 - Printar Arvore!\n");
	printf("3 - Remover um elemento!\n");
	printf("0 - sair\n");
	do{ //Loop para fazer o menu pedir as opções do usuário.
	printf("\nDigite a sua opção: ");
	scanf("%d",&op); //Leitura da opção digitada.
	switch(op){ //Loop que le a opção do usuário e mostra as ações.
		case 0:
			printf("Saindo...");
			return 0; //Sair do programa.
		case 1:
			printf("Digite o numero que deseja incluir na arvore: ");
			scanf("%d",&valor); //Informação que sera adicionada a arvore.
			Arv = insere(Arv,valor); //Chamado da função que ira inserir o NO digitado na arvore.
			setbuf(stdin,NULL); //Limpando flush do teclado para evitar bugs.
			break; //Para o programa para voltar ao menu sem atropelar as opções.
		case 2:
			printf("Numeros que estão na arvore: ");
			imprime(Arv); //Chamado da função para imprimir os NO em ordem.
			printf("\n"); //Pula uma linha.
			break; //Para o programa para voltar ao menu sem atropelar as opções.
		case 3:
			printf("Digite qual elemento deseja remover: ");
			scanf("%d",&valor); //Variável que o usuário quer excluir da arvore.
			Arv = retira(Arv,valor); //Chamado da função que ira buscar o NO  e excluir.
			setbuf(stdin,NULL); //Limpando flush do teclado para evitar bugs.
			break; //Para o programa para voltar ao menu sem atropelar as opções.
		default: 
			printf("\nOpção invalida! Tente novamente."); //Se o usuário digitar errada a opção.
		}
	}while(op != 0); //Enquanto a opção for diferente de 0 ele fica mostrando menu.
	
	system("pause"); //Pause o programa até a pessoa apertar uma tecla.
	return 0; //Finalização do programa.
}
