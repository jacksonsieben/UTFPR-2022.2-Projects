#define TAM 12
#include <stdio.h>

void selection(int arr[], int n){
    int min_idx;

    for (int i = 0; i < n-1; i++){
        min_idx = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx!=i){
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

void selectionSort(int vetor[], int tam){
    int menor;
    for (int i = 0; i < tam-1; i++){
        menor = i;
        for (int j = i+1; j < tam; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        if(menor != i){
            int temp = vetor[menor];
            vetor[menor] = vetor[i];
            vetor[i] = temp;
        }
    }
    
}

int main(){
    int vetor[] = {3,5,2,1,4,29,37,0,712,82,3,8};
    
    printf("Vetor Original\n");

    for (int i = 0; i < TAM; i++){
        printf("%d\t", vetor[i]);
    }

    selectionSort(vetor, TAM);

    printf("\nVetor Ordenado\n");

    for (int i = 0; i < TAM; i++){
        printf("%d\t", vetor[i]);
    }
}