#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000000


void merge(int *v, int *c, int i, int m, int f) {
    int z, iv = i, ic = m + 1;

    for (z = i; z <= f; z++){
        c[z] = v[z];
    }

    z = i;

    while (iv <= m && ic <= f) {
       

        if (c[iv] <= c[ic]){
            v[z++] = c[iv++];
        }
            
        else {
            v[z++] = c[ic++];
        }  
    }

    while (iv <= m){
        v[z++] = c[iv++];
    }

    while (ic <= f){
        v[z++] = c[ic++];
    }
}

void mergeAlg(int *v, int *c, int i, int f) {
    if (i >= f) return;

    int m = (i + f) / 2;

    mergeAlg(v, c, i, m);
    mergeAlg(v, c, m + 1, f);

   
    if (v[m] <= v[m + 1]){
        return;
    }

    merge(v, c, i, m, f);
}

double mergeSort(int vetor[], int tam) {
    int *c = malloc(sizeof(int) * tam);
        
    clock_t inicio = clock();

    mergeAlg(vetor, c,  0, tam - 1);

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;
    free(c);

    return tempo;
}

int main(){
    
    int *vetor = (int *) malloc(TAM * sizeof(int)); 

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }
    printf("Ordenando...\n");

    double tempo = mergeSort(vetor,TAM);

    printf("\nVetor Ordenado em %.8f\n", tempo);
}