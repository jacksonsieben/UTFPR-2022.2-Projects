// Quick sort in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 500000
int partitionHoare(int vetor[], int esq, int dir){
    int x = vetor[dir/2]; // tam/2
    for ( ; ; esq++, dir--) {
        while (vetor[esq] < x){
            esq++;
        }
        while (vetor[dir] > x){
            dir--;
        }
        if (esq >= dir) {
            break;
        }
        int aux2 = vetor[esq];
        vetor[esq] = vetor[dir];
        vetor[dir] = aux2;
    }
    return esq;
}
// function to swap elements
void quicksort(int *vetor, int tam) {
    //clock_t inicio = clock();
    if (tam < 2) {
        return;
    }
    int esq = partitionHoare(vetor, 0, tam-1);
    quicksort(vetor, esq);
    quicksort(vetor + esq, tam - esq);
    /*clock_t fim = clock();
    double gasto = difftime(fim,inicio)/CLOCKS_PER_SEC;
    printf("\ntempo gasto: %f segundos\n", gasto);*/
}

void quicksortH(int *vetor, int tam) {
  if (tam < 2) {
      return;
  }
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
          break;
      }
      int aux2 = vetor[esq];
      vetor[esq] = vetor[dir];
      vetor[dir] = aux2;
  }
  quicksortH(vetor, esq);
  quicksortH(vetor + esq, tam - esq);
}

// main function
int main() {
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }

    clock_t inicio = clock();
    quicksortH(vetor, TAM);
    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    printf("\nOrdenado em: %.5fs\n", tempo);
    //printf("finalizado");
}

