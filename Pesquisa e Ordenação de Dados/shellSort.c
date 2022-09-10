#define TAM 1000000
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void shell_sort(int *a, int size)
{
 int i , j , value;
 int gap = 1;
  
 do {
  gap = 3*gap+1;
 } while(gap < size);
  
 do {
  gap /= 3;
  for(i = gap; i < size; i++) {
   value = a[i];
   j = i - gap;
    
   while (j >= 0 && value < a[j]) {
    a[j + gap] = a[j];
    j -= gap;
   }
   a[j + gap] = value;
  }
 }while(gap > 1);
}

void shellSort(int vetor[], int tam){
    int h, aux;
    for (h = 1; h < tam; h = 3*h +1);
    while(h>0){
        h = (h-1)/3;
        for (int i = h; i < tam; i++){
            aux = vetor[i];
            int j = i;
            while(vetor[j - h] > aux){
                vetor[j] = vetor[j - h];
                j-=h;
                if(j<h){
                    break;
                }
            }
            vetor[j]=aux;
        }
    }
}

int main(){
    /*HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);
    //COORD Coordinates = {200, 100};
    //SetConsoleScreenBufferSize(Output, Coordinates);
    //                                  L
    SMALL_RECT Coordinates2 = {10, 20, 100, 50};
    SetConsoleWindowInfo(Output, TRUE, &Coordinates2);*/
    COORD SIZE_COORD = { 80, 50 };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),SIZE_COORD);

    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }

    printf("Vetor Original\n");

    for (int i = 0; i < TAM; i++){
        printf("%d\t", vetor[i]);
    }

    shellSort(vetor, TAM);

    printf("\nVetor Ordenado\n");

    for (int i = 0; i < TAM; i++){
        printf("%d\t", vetor[i]);
    }
}