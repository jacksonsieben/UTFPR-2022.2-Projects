#define TAM 5
#include <stdio.h>
#include <time.h>

void insert(int vetor[]){//um modelo que peguei na internet e funciona, talvez seja mais otimizado para arquivos maiores //? testar
    printf("\n");
    for(int i=1; i < TAM; i++){
        int temp = vetor[i];
        int j = i-1;
        while((temp < vetor[j]) && (j >= 0)){
            printf("i %d, j %d\n", vetor[i], vetor[j]);
            vetor[j+1] = vetor[j];
            j = j-1;
        }
        vetor[j+1] = temp;
   }
}

void insertSort(int vetor[]){
    for(int i = 1, y = 0; i < TAM ; i++){
        int aux = vetor[i];
        y = i-1;
        while((y>=0) && (aux < vetor[y])){
            vetor[y+1] = vetor[y];
            y = y-1;
            vetor[y+1] = aux;
        }
    }
}


int main(){
    int vetor[TAM];

    /*for(int i=0; i<TAM; i++){
        vetor[i] = i;
    }
    /*for(int cont= 0; cont<TAM; cont++){//ordenado
        vetor[cont] = cont;
    }*/

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }

    for(int i=0; i<TAM; i++){
        printf("\nVetor[%d]: %d", i, vetor[i]);
    }
    
    clock_t inicio = clock();
    insertSort(vetor);
    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    printf("\n\nElementos Ordenados: ");
    for(int i=0;i<TAM;i++)
        printf("\nVetor[%d]: %d", i,vetor[i]);

    printf("\nTempo Decorrido: %.2f", tempo);

   return 0;
}