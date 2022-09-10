
#include <stdio.h>
#include <time.h>

void bubbleSort(int vet[], int tam){
    clock_t inicio = clock();

    for (int i=0; i < tam-1; i++){
        for (int j=i+1; j < tam; j++){
            if(vet[i] > vet[j]){
                int aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
        }
    }

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;
    for (int i = 0; i < tam; i++){
        printf("%d - ", vet[i]);
    }

    printf("\n\nTempo de execucao %.2f.\n\n", tempo);
}

void insertSort(int vet[], int tam){
    int j;
    clock_t inicio = clock();

    for (int i = 1; i < tam; i++){
        int aux = vet[i];
        j = i-1;
        while (j >= 0 && aux < vet[j]){
            vet[j+1] = vet[j];
            j = j-1;
        }
        vet[j+1] = aux;
    }

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;
    for (int i = 0; i < tam; i++)
        printf("%d - ", vet[i]);

    printf("\n\nTempo de execucao %.2f.\n\n", tempo);
}

void main(){
    int z;
    int tam = 50000;
    int vet[tam];


    while (z != 3){

    for (int i=tam; i>0; i--)
        vet[i] = tam-i;

    printf("1. BubbleSort;\n");
    printf("2. InsertSort;\n");
    printf("3. Encerrar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &z);

        switch(z){
            case 1:
                bubbleSort(vet, tam);
                break;
            case 2:
                insertSort(vet, tam);
                break;
            case 3:
                printf("\n\nAdeus!!!\n\n");
                break;
            default:
                printf("\n\nOpcao invalida...\n\n");
        }
    }

}
