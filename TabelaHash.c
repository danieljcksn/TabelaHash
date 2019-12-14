#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//----------------* P R O T Ó T I P O S *----------------//
int hashing(int elemento, int m);
void tabelaHash(void);
void buscaHash(int elemento, int* tabela, int m);
void removeHash(int elemento, int* tabela, int m);
void imprimeHash(int* tabela, int m);


//----------------* F U N Ç Õ E S  D A  T A B E L A  H A S H *----------------//
void imprimeHash(int* tabela, int m){
	int i;
	printf(" - - - T A B E L A - - - \n");
	for(i = 0; i < m; i++){
		if(tabela[i] == -1){
			printf("[Nulo]\n");
			continue;
		}
		printf("[%d]\n", tabela[i]);
	}
	printf(" - - - - - - - - - - - - \n\n\n\n");
}

//Função que remove um determinado elemento da tabela.
void removeHash(int elemento, int* tabela, int m){
	int i;
	for(i=0; i<m; i++){
		if(tabela[i] == elemento){
			tabela[i] = -1;
			printf("Elemento removido com sucesso!\n\n\n\n\n");
			return;
		}
	}
	printf("Elemento não encontra-se na tabela!\n\n\n\n\n");
}

//Função que busca na tabela um elemento e indica o seu índice.
void buscaHash(int elemento, int* tabela, int m){
	int i;
	for(i=0; i<m; i++){
		if(tabela[i] == elemento){
			printf("Elemento encontrado! O seu índice é: %d\n\n\n\n\n", i);
			return;
		}
	}
	printf("Elemento não encontra-se na tabela!\n");
}

//Função que calcula o índice no qual será inserido um dado elemento.
int hashing(int elemento, int m){
	int indice;
	indice = elemento % m;
	return indice;
}

//Função principal que criará a tabela hash.
void tabelaHash(void){
	int m, i, j, elemento, indice, colisoes, iteracoes, escolha = 1, elem;

	printf("Insira o tamanho da tabela: ");
	scanf("%d", &m);

	//Criando um vetor no qual serão inseridos os elementos.
	int tabela[m];

	/*Definindo todos os elementos da tabela como -1, para 
	posteriormente saber quando uma determinada posição está vazia.*/
	for(i = 0; i < m; i++){
		tabela[i] = -1;
	}
	printf("Agora, insira os %d elementos da tabela.\n", m);
	printf("Para finalizar a inserção de elementos, insira -1\n");
	printf("- - - - - - - - - - - - - - - - - - \n");
	colisoes = 0;
	for(i = 0; i < m; i++){
		printf("Insira o %dº elemento da tabela: ", i+1);
		scanf("%d", &elemento);

		if(elemento == -1)
			break;

		indice = hashing(elemento, m);

		if(tabela[indice] == -1)
			tabela[indice] = elemento;
		else{
			colisoes++;
			iteracoes = 1;
			for(j = indice+1; j < m; j++){
				if(tabela[j] == -1){
					tabela[j] = elemento;
					break;
				}
				iteracoes++;
				/*Caso o número de iterações seja igual ao tamanho da tabela,
				temos que todas as posições possíveis da tabela foram verificadas.*/
				if(iteracoes == m){
					printf("Erro: Tabela completamente preenchida.\nNão foi possível inserir o elemento %d na tabela.\n", elemento);
					break;
				}
				/*Caso chegue ao fim da tabela hash e não tenha
				verificado para todas possíveis posições da tabela. Volta ao primeiro índice.*/
				if(j == m-1)
					j = 0;
			}
		}	
	}
	printf("- - - - - - - - - - - - - - - - - - \n");
	printf("Número de colisões: %d\n\n", colisoes);


	//Menu de opções para o programa.
	while(escolha != 4){
		printf("Selecione uma das seguintes operações:\n");
		printf("1 - Buscar elemento.\n");
		printf("2 - Remover elemento.\n");
		printf("3 - Imprimir tabela.\n");
		printf("4 - Nova tabela.\n");
		printf("5 - Sair.\n\n- - - - - - - - - - - - - - - - - - \n");	
		printf("Sua escolha: ");
		scanf("%d", &escolha);
		switch (escolha){
			case 1:
				//Comando para limpar a tela.
				printf("\e[H\e[2J");
			    printf("Digite o elemento a ser buscado na tabela: ");
			    scanf("%d", &elem);
			    buscaHash(elem, tabela, m);
				break;

		   	case 2:
		   		printf("\e[H\e[2J");
			    printf("Digite o elemento a ser removido na tabela: ");
			    scanf("%d", &elem);
			    removeHash(elem, tabela, m);
				break;

		   	case 3:
		   		printf("\e[H\e[2J");
			    imprimeHash(tabela, m);
				break;

		   	case 4:
		   		printf("\e[H\e[2J");
		   		tabelaHash();
			    return;
				break;		

			case 5:
				printf("\e[H\e[2J");
		   		printf("Tchau! :)\n\n\n\n");
			    return;
				break;

			default:
			    printf("Opção inválida!\n");
		}
	}
	return;
}	

//----------------* F U N Ç Ã O  P R I N C I P A L *----------------//
int main(void){

	setlocale(LC_ALL, "Portuguese");
	printf("\e[H\e[2J");
	
	tabelaHash();

	return 0;
}