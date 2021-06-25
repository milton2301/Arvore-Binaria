#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct NO{ //Defini��o da struct com informa��o e 2 ponteiros.
	int info; //Informa��o.
	struct NO* esq; //Ponteiro para esquerda.
	struct NO* dir; //Ponteiro para a direita.
};

typedef struct NO node; //Renomeando a struct.

void imprime(node* Arv){ //Fun��o imprime a ordem da arvore.
	if( Arv != NULL){ //Se a arvore for diferente de nulo.
		imprime(Arv->esq); //Imprime arvore da esquerda.
		printf("%d ",Arv->info); //Imprime a raiz
		imprime(Arv->dir); //Imprime a arvore da direita.
	}
}


node* insere (node* Arv, int info){ //Fun��o para inserir elementos em uma arvore binaria.
	if( Arv == NULL){ //Verifica se a arvore � variavel.
		Arv = (node*)malloc(sizeof(node)); //Se for vazio ele aloca um novo NO.
		Arv->info = info; //o NO recebe a informa��o digitada para o NO.
		Arv->esq = NULL; //Lado esquerdo aponta pra null.
		Arv->dir = NULL; //Lado direito aponta pra null.
	}else if(info < Arv->info){ //Se a arvore n�o for vazia ele verifica se o valor inserido � menor que a informa��o atual do NO.
		Arv->esq = insere(Arv->esq,info); //Se a informa��o for menor, ele aloca e insere um NO a esquerda na arvore.
	}else if(info > Arv->info){ //Se a arvore n�o for vazia ele verifica se o valor inserido � maior que a informa��o atual do NO.
		Arv->dir = insere(Arv->dir,info); //Se a informa��o for maior, ele aloca e insere um NO a direita da arvore.
	}
	return Arv; //Retorna os NO's.
}

node* retira (node* ret, int info){ //Fun��o que retira um NO de uma arvore.
	if(ret == NULL){ //Se a arvore ainda n�o esxistir.
		return NULL; //Ele retora null.
	}else if(ret->info > info){ //Sen�o ele verifica se o valor passado � maior que o vavlor que vai ser excluido.
		ret->esq = retira(ret->esq, info); //Se for ele percorre a arvore da esquerda.
		}else if(ret->info < info){ //Sen�o ele verifica se o valor passado � menor que o valor que vai ser excluido.
			ret->dir = retira(ret->dir, info); //Se for ele percorre a arvore da direita.
		}else{
			if(ret->esq == NULL && ret->dir == NULL){ //Se esquerda e direita for null.
				free(ret); //Libera o NO.
				ret = NULL; //Recebe null.
			}else if(ret->esq == NULL){ //Sub arvore da esquerda n�o � null.
				node* aux = ret; //Cria uma auxiliar que recebe o valor do N� que sera apagado.
				ret = ret->dir; //R recebe o valor do filho a direita.
				free(aux); //Libera o NO.
			}else if(ret->dir == NULL){ //Sub arvore da direita n�o � null.
				node* aux = ret; //Cria um auxiliar que recebe o valor do NO que sera apagado.
				ret = ret->esq; //R recebe o valor do filho a esquerda.
				free(aux); //Libera o NO.
			}
		}
	return ret; //Retorna os NO's.
}



int main(){
	setlocale(LC_ALL, "portuguese"); //Cola os pontos no portugues.
	int valor; //Vari�vel que recebe o valor digitado pelo usu�rio.
	int op; //Vari�vel que recebe a op��o digitada pelo usu�rio.
	
	node* Arv = NULL; //Inicia a arvore como null.
	
	printf("O que voc� deseja fazer na arvore?\n"); //Menu de op��es.
	printf("1 - Incluir elemento!\n");
	printf("2 - Printar Arvore!\n");
	printf("3 - Remover um elemento!\n");
	printf("0 - sair\n");
	do{ //Loop para fazer o menu pedir as op��es do usu�rio.
	printf("\nDigite a sua op��o: ");
	scanf("%d",&op); //Leitura da op��o digitada.
	switch(op){ //Loop que le a op��o do usu�rio e mostra as a��es.
		case 0:
			printf("Saindo...");
			return 0; //Sair do programa.
		case 1:
			printf("Digite o numero que deseja incluir na arvore: ");
			scanf("%d",&valor); //Informa��o que sera adicionada a arvore.
			Arv = insere(Arv,valor); //Chamado da fun��o que ira inserir o NO digitado na arvore.
			setbuf(stdin,NULL); //Limpando flush do teclado para evitar bugs.
			break; //Para o programa para voltar ao menu sem atropelar as op��es.
		case 2:
			printf("Numeros que est�o na arvore: ");
			imprime(Arv); //Chamado da fun��o para imprimir os NO em ordem.
			printf("\n"); //Pula uma linha.
			break; //Para o programa para voltar ao menu sem atropelar as op��es.
		case 3:
			printf("Digite qual elemento deseja remover: ");
			scanf("%d",&valor); //Vari�vel que o usu�rio quer excluir da arvore.
			Arv = retira(Arv,valor); //Chamado da fun��o que ira buscar o NO  e excluir.
			setbuf(stdin,NULL); //Limpando flush do teclado para evitar bugs.
			break; //Para o programa para voltar ao menu sem atropelar as op��es.
		default: 
			printf("\nOp��o invalida! Tente novamente."); //Se o usu�rio digitar errada a op��o.
		}
	}while(op != 0); //Enquanto a op��o for diferente de 0 ele fica mostrando menu.
	
	system("pause"); //Pause o programa at� a pessoa apertar uma tecla.
	return 0; //Finaliza��o do programa.
}
