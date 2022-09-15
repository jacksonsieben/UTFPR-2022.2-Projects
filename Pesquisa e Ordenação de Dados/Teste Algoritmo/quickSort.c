#include <stdio.h>
#define TAM 500000

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

int particione (int vet[], int esq, int dir){
    int x = vet[esq], up = dir, down = esq;
    
}

int main(){
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }

    /*printf("Vetor Original\n");

    for (int i = 0; i < TAM; i++){
        printf("%d\t", vetor[i]);
    }*/

    quick_sort(vetor, 0, TAM -1);

    printf("\nVetor Ordenado\n");

    for (int i = 0; i < TAM; i++){
        printf("%d\t", vetor[i]);
    }
}