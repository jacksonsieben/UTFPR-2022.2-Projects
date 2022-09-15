#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 500000

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

void mergeAlg(int a[], int esq, int dir) {

    if (esq < dir) {
        int meio = (esq + dir) / 2;
        mergeAlg(a, esq, meio);
        mergeAlg(a, meio +1, dir);
        merge(a, esq, meio, dir);
    }
}

double mergeSort(int vetor[], int tam){
    clock_t inicio = clock();

    mergeAlg(vetor, 0, tam - 1);

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

int main(){
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }

    double tempo = mergeSort(vetor,TAM);

    printf("\nVetor Ordenado em %.8f\n", tempo);
}