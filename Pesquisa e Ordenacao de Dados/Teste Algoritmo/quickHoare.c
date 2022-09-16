#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 150000

/*// função que realiza a troca entre dois elementos


// particiona e retorna o índice do pivô
int particiona(int vet[], int inicio, int fim)7
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

int main()
{
	// vetor que será ordenado
	int vet[] = {25,40,55,20,44,35,38,99,10,65,50};
	int tam_vet = sizeof(vet) / sizeof(int);
	int i;
	
	// inicializa random seed
	srand(time(NULL));
	 
	// chamada do quicksort
	quick_sort(vet, 0, tam_vet - 1);

	// mostra o vetor ordenado
	for(i = 0; i < tam_vet; i++)
		printf("%d ", vet[i]);
	
	return 0; 
}*/

void troca(int vet[], int i, int j){
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

int particionaHoare(int *vet, int esq, int dir){
	int x = vet[esq];
	int up = dir;
	int down = esq;

	while(down < up){
		while(vet[down] <= x && down < dir){
			down = down + 1;
		}
		while(vet[up] > x){
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

void hoare(int vetor[], int tam){// pivo = x | i3 = esq | j3 = dir
	int i, dir, esq;
	if(dir > esq){

		int x = vetor[tam/2];
		int up = dir - 1;
		int down = esq;

		while(down < up){
			while(vetor[down] <= x && down < dir){
				down++;
			}
			while(vetor[up] > x){
				up--;
			}
			if(down < up){
				troca(vetor, down, up);
			}
		}

		vetor[esq] = vetor[up];
		vetor[up] = x;


		//i = particionaHoare(vetor, esq, dir);
		hoare(vetor, esq);
		hoare(vetor + esq, tam - esq);
	}
}

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while (i >= j){
        do {
            i++;
        } while (a[i] < pivot);
 
        do {
            j--;
        } while (a[j] > pivot);
 
        /*if (i >= j) {
            return j;
        }*/
 
        troca(a, i, j);
    }

	return j;
}
 
// Quicksort routine
void quicksort(int a[], int low, int high){
    int pivot = 0;
	// base condition
    if (low >= high) {
        return;
    }
 
    // rearrange elements across pivot
    pivot = partition(a, low, high);
 
    // recur on subarray containing elements that are less than the pivot
    quicksort(a, low, pivot);
 
    // recur on subarray containing elements that are more than the pivot
    quicksort(a, pivot, high);
}

double quickSortHoare(int vetor[], int tam){
	clock_t inicio = clock();
	int esq;
	int dir;
	esq = 0;
	dir = tam;
	
	hoare(vetor, tam);
	//quicksort(vetor, 1, tam);

	double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

int main(){
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        //vetor[i] = cont;
		vetor[i] = i;
    }

	double tempo = quickSortHoare(vetor, TAM);

    printf("\nVetor Ordenado em %.8f\n", tempo);
}