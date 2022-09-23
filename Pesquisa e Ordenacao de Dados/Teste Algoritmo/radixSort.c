/* radix.c
   Jake Rodriguez Pomperada,MAED-IT, MIT
   www.jakerpomperada.com   www.jakerpomperada.blogspot.com
   jakerpomperada@gmail.com
   Bacolod City, Negros Occidental */

#define  _CRT_SECURE_NO_WARNINGS // only needed for Visual Studio
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 500000



void countingsort(int Array[], int n, int place) {
   int i;
   int* output = malloc(sizeof(int) * n);

   int freq[10] = { 0 };

   for (i = 0; i < n; i++){
      freq[(Array[i] / place) % 10]++;
   } 

   for (i = 1; i < 10; i++){
      freq[i] += freq[i - 1];
   }

   for (i = n - 1; i >= 0; i--) {
      output[freq[(Array[i] / place) % 10] - 1] = Array[i];
      freq[(Array[i] / place) % 10]--;
   }

   for (i = 0; i < n; i++){
      Array[i] = output[i];
   }

   free(output);
}

double radixSort(int Array[], int tam){
   clock_t inicio = clock();

	int i = 0, place = 0;
	int max = Array[0];

	for (i = 1; i < tam; i++) {
		if (max < Array[i])
			max = Array[i];
	}

	for (place = 1; max / place > 0; place *= 10){
      countingsort(Array, tam, place);
   }

   double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;
    
   return tempo;
}

int main() {

   int *vetor = (int *) malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont > 0; cont--, i++){
        vetor[i] = cont;
    }

	double tempo = radixSort(vetor, TAM);
   printf("ordenado em %.4f", tempo);
	free(vetor);
	return 0;
}