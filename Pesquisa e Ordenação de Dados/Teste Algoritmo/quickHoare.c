#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time

#define TAM 500000
/*
// função que realiza a troca entre dois elementos
void troca(int vet[], int i, int j){
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int vet[], int inicio, int fim)
{
	int pivo, pivo_indice, i;
	
	pivo = vet[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
		if(vet[i] <= pivo)
		{
			// realiza a troca
			troca(vet, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(vet, pivo_indice, fim);
	
	// retorna o índice do pivô
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int vet[], int inicio, int fim)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	// faz a troca para colocar o pivô no fim
	troca(vet, pivo_indice, fim);
	// chama a particiona
	return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim)
{
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona_random(vet, inicio, fim);
		
		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1);
		quick_sort(vet, pivo_indice + 1, fim);
	}
}

int main(){
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }

	quick_sort(vetor, 0, TAM);

    printf("\nVetor Ordenado \n");

	for (int i = 0; i < TAM; i++){
        printf("%d\t", vetor[i]);
    }
}*/

void troca(int vet[], int i, int j){
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

int particionaHoare(int vet[], int esq, int dir){
	int x = vet[esq], up = dir, down = esq;
	while(down < up){
		while(vet[down] <= x && down < dir){
			//down++;
			down = down + 1;
		}
		while(vet[up] > x){
			//up--;
			up = up - 1;
		}
		if(down < up){
			troca(vet, down, up);
		}
	}

	vet[esq] = vet[up];
	vet[up] = x;

	return up;
}

void hoare(int vetor[], int esq, int dir){
	int i;
	if(dir > esq){
		i = particionaHoare(vetor, esq, dir);
		hoare(vetor, esq, i);
		hoare(vetor, i+1, dir);
	}	
}

double quickSortHoare(int vetor[], int tam){
	clock_t inicio = clock();
	
	hoare(vetor, 0, tam -1);

	double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

int main(){
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }

	double tempo = quickSortHoare(vetor, TAM);

    printf("\nVetor Ordenado em %.8f\n", tempo);

}