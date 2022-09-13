#define TAM 5
#include <stdio.h>
#include <time.h>

void bubbleSort(int vetor[]){
    for (int j = TAM; j > 0; j--){
        for(int i = 0; i < j; i++) {
            if(vetor[i] > vetor[i+1]){
                int aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }       
}
int main(){
    int vetor[TAM];

    /*for(int cont= TAM; cont>0; cont--){//ordenado
        vetor[cont] = cont;
    }*/

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }

    printf("Original ->\t");
    for(int cont= 0; cont<TAM; cont++){
        printf("%d\t",vetor[cont]);
    }

    clock_t inicio = clock();
    bubbleSort(vetor);
    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    printf("\n\nOrdenado ->\t");
    for(int cont= 0; cont<TAM; cont++){
        printf("%d\t", vetor[cont]);
    }

    printf("\nTempo Decorrido: %.5f", tempo);
}