#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 500

void merge(int a[], int esq, int meio, int dir) {
    int i, j, k;
    int aux[dir];
    for (i = meio +1; i > esq; i--){
        aux[i-1] = a[i-1];
    }

    for (j = meio; j < dir; j++){
        aux[dir + meio -j] = a[j+1];
    }

    for (k = esq; k <= dir; k++){
        if (aux[j] < aux[i]){
            a[k] = aux[j--];
        }else{
            a[k] = aux[i++];
        }
    }
}

double mergeAlg(int a[], int esq, int dir) {
    clock_t inicio = clock();

    if (esq < dir) {
        int meio = (esq + dir) / 2;
        mergeAlg(a, esq, meio);
        mergeAlg(a, meio +1, dir);
        merge(a, esq, meio, dir);
    }

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

double mergeSort(int vetor[], int tam){
    return mergeAlg(vetor, 0, tam - 1);
}

int main(){
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }

    printf("Vetor Original\n");

    for (int i = 0; i < TAM; i++){
        printf("%d\t", vetor[i]);
    }

    mergeSort(vetor,TAM);

    printf("\nVetor Ordenado\n");

    for (int i = 0; i < TAM; i++){
        printf("%d\t", vetor[i]);
    }
}