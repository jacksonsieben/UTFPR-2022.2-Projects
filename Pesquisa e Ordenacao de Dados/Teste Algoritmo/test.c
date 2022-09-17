// Quick sort in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 500000

void troca(int vet[], int i, int j){
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

/*int partition(int values[], int left, int right) {
        
    int pivot = values[right/2];
    int i = left;

    for (int j = left + 1; j <= right; j++) {
        if (values[j] <= pivot) {
            i+=1;
            troca(values, i, j);
        }
    }

    // troca pivot (values[left]) com i.
    troca(values, left, i);
    
    return i; 
}

void quickSort(int values[], int left, int right) {
	if (left < right) {
		int index_pivot = partition(values, left, right);
		quickSort(values, left, index_pivot - 1);
		quickSort(values, index_pivot + 1, right);	
	}
}*/
int partitionLomuto(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return (i + 1);
}

void lomuto(int arr[], int low, int high){
    while (low < high) {
        int index = partitionLomuto(arr, low, high);
        if((index-low) <= (high-index)){       // avoid stack overflow
            lomuto(arr, low, index - 1);    //
            low = index+1;                     //
        }else{                                 //
            lomuto(arr, index + 1, high);   //
            high = index-1;                    //
        }                                      //
    }
}

double quickSortLomuto(int *vetor, int tam){
    clock_t inicio = clock();

    lomuto(vetor, 0, tam - 1);

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

// main function
int main() {
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont > 0; cont--, i++){//invertido
        vetor[i] = cont;
    }
    printf("Ordenando...");
    double tempo = quickSortLomuto(vetor, TAM);

    printf("\nOrdenado em: %.5fs\n", tempo);

    printf("\nVetor Ordenado\n");

    for (int i = 0; i < TAM; i++){
        printf("%d\t", vetor[i]);
    }
    //printf("finalizado");
}

