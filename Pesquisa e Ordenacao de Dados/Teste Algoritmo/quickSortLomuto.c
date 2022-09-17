#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 500000

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
        if((index-low) <= (high-index)){       
            lomuto(arr, low, index - 1);    
            low = index+1;                     
        }else{                                 
            lomuto(arr, index + 1, high);   
            high = index-1;                   
        }                                      
    }
}

double quickSortLomuto(int *vetor, int tam){
    clock_t inicio = clock();

    lomuto(vetor, 0, tam - 1);

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

int main(){
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){
        vetor[i] = cont;
    }

	double tempo = quickSortLomuto(vetor, TAM-1);

    printf("\nVetor Ordenado em %.8f\n", tempo);
}