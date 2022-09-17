#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000000

int partitionHoare(int *vetor, int tam){
    int x = vetor[tam/2];
    int esq, dir;
    for (esq = 0, dir = tam - 1; ; esq++, dir--) {
        while (vetor[esq] < x){
            esq++;
        }
        while (vetor[dir] > x){
            dir--;
        }
        if (esq >= dir) {
            return esq;
        }
        int aux = vetor[esq];
        vetor[esq] = vetor[dir];
        vetor[dir] = aux;
    }
}

void hoare(int *vetor, int tam) {
    if(tam<2){
        return;
    }
    int esq = partitionHoare(vetor, tam);
    if(tam>esq){
        hoare(vetor, esq);
        hoare(vetor + esq, tam - esq);
    }
}

double quickSortHoare (int *vetor, int tam) {
	clock_t inicio = clock();

	hoare(vetor, TAM);

	double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

	return tempo;
}

int main(){
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }

	clock_t inicio = clock();

	double tempo = quickSortHoare(vetor, TAM);

    printf("\nVetor Ordenado em %.8f\n", tempo);
}