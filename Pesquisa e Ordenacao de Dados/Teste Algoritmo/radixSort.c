// Radix Sort in C Programming

#include <stdio.h>
#include <stdlib.h>

#define TAM 500

// Function to get the largest element from an array
int get_max (int a[], int n){
   int max = a[0];
   for (int i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
}
void radix_sort (int a[], int n){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = get_max (a, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = a[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
      /*printf ("After pass %d : ", pass + 1);
      for (i = 0; i < n; i++)
         printf ("%d ", a[i]);
      printf ("\n");*/
   }
}

// Print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int *vetor = malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont>0; cont--, i++){//invertido
        vetor[i] = cont;
    }
    //printArray(vetor, TAM);
    printf("Ordenando...\n");
    radix_sort(vetor, TAM);
    printArray(vetor, TAM);
}