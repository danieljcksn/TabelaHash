#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Protótipos das funções
int indiceHashing(int elemento);
void tabelaHash(void);

//Função que calcula o índice no qual será inserido um dado elemento.
int indiceHashing(int elemento){
	int indice;
	indice = elemento % 10;
	return indice;
}

//Função principal que criará a tabela hash.
void tabelaHash(void){
	int m, i, j, elemento, indice, colisoes, iteracoes;

	printf("Insira o tamanho da tabela: ");
	scanf("%d", &m);

	//Criando um vetor no qual serão inseridos os elementos.
	int tabela[m];

	/*Definindo todos os elementos da tabela como -1, para 
	posteriormente saber quando uma determinada posição está vazia.*/
	for(i = 0; i < m; i++){
		tabela[i] = -1;
	}
	printf("Agora, insira os %d elementos da tabela.", m);
	printf("Para finalizar a inserção de elementos, insira -1\n");
	colisoes = 0;
	for(i = 0; i < m; i++){
		printf("Insira o %dº elemento da tabela: ", i+1);
		scanf("%d", &elemento);

		if(elemento == -1)
			break;

		indice = indiceHashing(elemento);

		if(tabela[indice] == -1){
			tabela[indice] = elemento;
		}else{
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

	for(i = 0; i < m; i++){
		if(tabela[i] == -1){
			printf("[Nulo]\n");
			continue;
		}
		printf("[%d]\n", tabela[i]);
	}
	printf("Número de colisões: %d\n", colisoes);
}

int main(void){
	setlocale(LC_ALL, "Portuguese");
	tabelaHash();

	return 0;
}