#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50000

void troca(int vet[], int i, int j){
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

int particiona(int vet[], int inicio, int fim){
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

void lomuto(int vet[], int inicio, int fim)
{
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona(vet, inicio, fim);
		
		// chamadas recursivas quick_sort
		lomuto(vet, inicio, pivo_indice - 1);
		lomuto(vet, pivo_indice + 1, fim);
	}
}

double quickSortLomuto(int vetor[], int tam){
	clock_t inicio = clock();
	
	lomuto(vetor, 0, tam-1);
	//quicksort(vetor, 1, tam);

	double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

int main(){
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }

	double tempo = quickSortLomuto(vetor, TAM);

    printf("\nVetor Ordenado em %.8f\n", tempo);
}