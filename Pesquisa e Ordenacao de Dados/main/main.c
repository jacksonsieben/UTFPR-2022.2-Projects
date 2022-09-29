#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define Q500K 500000        //define quantidade 500 Mil
#define Q750K 750000        //define quantidade 750 Mil
#define Q1KK  1000000       //define quantidade 1 Milhao
#define OUTLP 27            //define saida do loop em 0
#define SCREEN_WIDTH 500    //define largura da tela
#define SCREEN_HEIGHT 400   //define altura da tela

#define CORD 28             //define pixel da coluna ordenada
#define CINV 38             //define pixel da coluna invertido
#define CALT 48             //define pixel da coluna aleatorio

#define lin 11              //define quantidade de linhas da matriz de impressão
#define col 48              //define quantidade de colunas da matriz de impressão



/**
    *!                                          Anotacoes
**/

char tabela [lin][col]=   {
                        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', '*', '*', 'T', 'A', 'B', 'E', 'L', 'A', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', 'O', 'R', 'D', 'E', 'N', 'A', 'D', 'O', '|', 'I', 'N', 'V', 'E', 'R', 'T', 'I', 'D', 'O', '|', 'A', 'L', 'E', 'A', 'T', 'O', 'R', 'I', 'O', '|'},
                        {'B', 'U', 'B', 'B', 'L', 'E', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'I', 'N', 'S', 'E', 'R', 'T', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'S', 'E', 'L', 'E', 'C', 'T', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'S', 'H', 'E', 'L', 'L', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'Q', 'U', 'I', 'C', 'K', 'S', 'O', 'R', 'T', ' ', 'H', 'O', 'A', 'R', 'E', ' ', '|', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'Q', 'U', 'I', 'C', 'K', 'S', 'O', 'R', 'T', ' ', 'L', 'O', 'M', 'U', 'T', 'O', '|', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'M', 'E', 'R', 'G', 'E', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'R', 'A', 'D', 'I', 'X', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'H', 'E', 'A', 'P', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'}
                        };// 48 colunas, 11 linhas

struct tempo{
    double ordenado;
    double invertido;
    double aleatorio;
};

struct tOrdenacao{
    int tam;
    struct tempo *bubbleSort;
    struct tempo *insertSort;
    struct tempo *selectSort;
    struct tempo *shellSort;
    struct tempo *quickSortHoare;
    struct tempo *quickSortLomuto;
    struct tempo *mergeSort;
    struct tempo *radixSort;
    struct tempo *heapSort;
};

struct tPesquisa{
    int tam;
    double *pesquisaSequencial;
    double *pesquisaBinaria;
    struct tempo *algoritmoOrdenacao;
};

typedef struct tempo  Tempo;
typedef Tempo*        pTempo;

typedef struct tOrdenacao  TOrdenacao;
typedef TOrdenacao*        pTOrdenacao;

typedef struct tPesquisa   TPesquisa;
typedef TPesquisa*         pTPesquisa;

typedef double (algOrdenacao(int v[], int tam));
typedef double (algPesquisa(int v[], int tam, int key));

pTOrdenacao criarStructOrdenacao(){
    pTOrdenacao pTO = malloc(sizeof(TOrdenacao));

    pTO->tam = 0;
    pTO->bubbleSort = NULL;
    pTO->insertSort = NULL;
    pTO->selectSort = NULL;
    pTO->shellSort  = NULL;
    pTO->quickSortHoare  = NULL;
    pTO->quickSortLomuto  = NULL;
    pTO->mergeSort  = NULL;
    pTO->radixSort  = NULL;
    pTO->heapSort = NULL;

    return pTO;
}

pTPesquisa criarStructPesquisa(){
    pTPesquisa  pTP = malloc(sizeof(TPesquisa));

    pTP->tam = 0;
    pTP->pesquisaSequencial = NULL;
    pTP->pesquisaBinaria = NULL;
    pTP->algoritmoOrdenacao = NULL; 

    return pTP;
}
//? ============================================================================SCREEN============================================================================
#pragma Screen 
void showCursor(int bShow){
    /******************************* showCursor ***********************************
        shows/hides the curser by TRUE/FALSE.

        PRE : bShow - TRUE/FALSE
        POST: Returns nothing.
    *******************************************************************************/
    int nSize = 25; 	//The nSize = the cursor height, optional parameter, by default 25. Size range: 1 - 100
	CONSOLE_CURSOR_INFO CurInfo;

	//Define the cursor size
	if (nSize <= 0) nSize = 1;
	if (nSize > 100) nSize = 100;
	CurInfo.dwSize = nSize;
	CurInfo.bVisible = bShow;           //Define the visibility of the cursor
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);  //Set parameters
} /* showCursor */

void setScreenSize(int x, int y){
    /**************** setScreenSize *******************************
        changes screen to full.

        PRE : x  - left/right width.
            y  - up/down length.
        POST: Returns nothing.
    ***************************************************************/
    HANDLE hConsoleOutput;
    COORD coord;
    CONSOLE_SCREEN_BUFFER_INFO  ConsoleInfo;
    HWND console = GetConsoleWindow();

    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);
    coord.X = x;
    coord.Y = y;
    SetConsoleScreenBufferSize(hConsoleOutput, coord);

    MoveWindow(console, 20, 20, SCREEN_WIDTH, SCREEN_HEIGHT, TRUE);
} /* setScreenSize */

void gotoxy(int x, int y) {
    COORD c;
    c.Y= y-1;
    c.X= x-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void tabDraw (pTOrdenacao pTO){
    system("cls");

    for (int c=0; c<col; c++){
        for (int l=0; l<lin; l++){
            gotoxy(10+c,1+l);
            switch (tabela [l][c]){
                case '*': printf(" ");   break;
                case '|': printf("%c", 179); break;
                default: printf("%c", tabela [l][c]);
            }
        }
    }

    if(pTO->tam != Q1KK){
        gotoxy(CINV,1);
        printf("%d MIL", (pTO->tam/1000));
    }else{
        gotoxy(CINV,1);
        printf("1 MILHAO");
    }

    if(pTO->bubbleSort != NULL){
        gotoxy(CORD,3);//linha 3 coluna ORDENADO
        printf("%.4lf", pTO->bubbleSort->ordenado);
        gotoxy(CINV,3);//linha 3 coluna INVERTIDO
        printf("%.4lf", pTO->bubbleSort->invertido);
        gotoxy(CALT,3);//linha 3 coluna ALEATORIO
        printf("%.4lf", pTO->bubbleSort->aleatorio);
    }

    if(pTO->insertSort != NULL){
        gotoxy(CORD,4);//linha 4 coluna ORDENADO
        printf("%.4lf", pTO->insertSort->ordenado);
        gotoxy(CINV,4);//linha 4 coluna INVERTIDO
        printf("%.4lf", pTO->insertSort->invertido);
        gotoxy(CALT,4);//linha 4 coluna ALEATORIO
        printf("%.4lf", pTO->insertSort->aleatorio);
    }

    if(pTO->selectSort != NULL){
        gotoxy(CORD,5);//linha 5 coluna ORDENADO
        printf("%.4lf", pTO->selectSort->ordenado);
        gotoxy(CINV,5);//linha 5 coluna INVERTIDO
        printf("%.4lf", pTO->selectSort->invertido);
        gotoxy(CALT,5);//linha 5 coluna ALEATORIO
        printf("%.4lf", pTO->selectSort->aleatorio);
    }

    if(pTO->shellSort != NULL){
        gotoxy(CORD+1,6);//linha 6 coluna ORDENADO
        printf("%.4lf", pTO->shellSort->ordenado);
        gotoxy(CINV+1,6);//linha 6 coluna INVERTIDO
        printf("%.4lf", pTO->shellSort->invertido);
        gotoxy(CALT+1,6);//linha 6 coluna ALEATORIO
        printf("%.4lf", pTO->shellSort->aleatorio);
    }

    if(pTO->quickSortHoare != NULL){
        gotoxy(CORD+1,7);//linha 7 coluna ORDENADO
        printf("%.4lf", pTO->quickSortHoare->ordenado);
        gotoxy(CINV+1,7);//linha 7 coluna INVERTIDO
        printf("%.4lf", pTO->quickSortHoare->invertido);
        gotoxy(CALT+1,7);//linha 7 coluna ALEATORIO
        printf("%.4lf", pTO->quickSortHoare->aleatorio);
    }

    if(pTO->quickSortLomuto != NULL){
        gotoxy(CORD,8);//linha 8 coluna ORDENADO
        printf("%.4lf", pTO->quickSortLomuto->ordenado);
        gotoxy(CINV,8);//linha 8 coluna INVERTIDO
        printf("%.4lf", pTO->quickSortLomuto->invertido);
        gotoxy(CALT+1,8);//linha 8 coluna ALEATORIO
        printf("%.4lf", pTO->quickSortLomuto->aleatorio);
    }

    if(pTO->mergeSort != NULL){
        gotoxy(CORD+1,9);//linha 9 coluna ORDENADO
        printf("%.4lf", pTO->mergeSort->ordenado);
        gotoxy(CINV+1,9);//linha 9 coluna INVERTIDO
        printf("%.4lf", pTO->mergeSort->invertido);
        gotoxy(CALT+1,9);//linha 9 coluna ALEATORIO
        printf("%.4lf", pTO->mergeSort->aleatorio);
    }

    if(pTO->radixSort != NULL){
        gotoxy(CORD+1,10);//linha 10 coluna ORDENADO
        printf("%.4lf", pTO->radixSort->ordenado);
        gotoxy(CINV+1,10);//linha 10 coluna INVERTIDO
        printf("%.4lf", pTO->radixSort->invertido);
        gotoxy(CALT+1,10);//linha 10 coluna ALEATORIO
        printf("%.4lf", pTO->radixSort->aleatorio);
    }

    if(pTO->heapSort != NULL){
        gotoxy(CORD+1,11);//linha 11 coluna ORDENADO
        printf("%.4lf", pTO->heapSort->ordenado);
        gotoxy(CINV+1,11);//linha 11 coluna INVERTIDO
        printf("%.4lf", pTO->heapSort->invertido);
        gotoxy(CALT+1,11);//linha 11 coluna ALEATORIO
        printf("%.4lf", pTO->heapSort->aleatorio);
    }

    gotoxy(5,14);
    printf("Aperte qualquer tecla para voltar ao menu!");
    fflush(stdin);
    getch();
}

void tabDrawPesquisa (pTPesquisa pTP){
    system("cls");

    for (int c=16; c<col; c++){
        for (int l=0; l<lin; l++){
            gotoxy(10+c,1+l);
            switch (tabela [l][c]){
                case '*': printf(" ");   break;
                case '|': printf("%c", 179); break;
                default: printf("%c", tabela [l][c]);
            }
        }
    }

    if(pTP->tam != Q1KK){
        gotoxy(CINV,1);
        printf("%d MIL", (pTP->tam/1000));
    }else{
        gotoxy(CINV,1);
        printf("1 MILHAO");
    }

    gotoxy(6,3);
    printf("PESQUISA SEQUENCIAL");
    gotoxy(6,4);
    printf("PESQUISA BINARIA");
    gotoxy(6,5);
    printf("ALGORITMO ORDENACAO");
    gotoxy(6,6);
    printf("SEQUENCIAL+ORDENACAO");
    gotoxy(6,7);
    printf("BINARIO+ORDENACAO");

    if(pTP->pesquisaSequencial != NULL){
        gotoxy(CORD,3);//linha 3 coluna ORDENADO
        printf("%.5lf", *(pTP->pesquisaSequencial));
        gotoxy(CINV,3);//linha 3 coluna INVERIDO
        printf("%.5lf", *(pTP->pesquisaSequencial));
        gotoxy(CALT,3);//linha 3 coluna ALEATORIO
        printf("%.5lf", *(pTP->pesquisaSequencial));

        gotoxy(CORD,6);//linha 6 coluna ORDENADO
        printf("%.5lf", ((pTP->algoritmoOrdenacao->ordenado) + *(pTP->pesquisaSequencial)));
        gotoxy(CINV,6);//linha 6 coluna INVERIDO
        printf("%.5lf", ((pTP->algoritmoOrdenacao->invertido) + *(pTP->pesquisaSequencial)));
        gotoxy(CALT,6);//linha 6 coluna ALEATORIO
        printf("%.5lf", ((pTP->algoritmoOrdenacao->aleatorio) + *(pTP->pesquisaSequencial)));
    }

    if(pTP->pesquisaBinaria != NULL){
        gotoxy(CORD,4);//linha 4 coluna ORDENADO
        printf("%.5lf", *(pTP->pesquisaBinaria));
        gotoxy(CINV,4);//linha 4 coluna INVERIDO
        printf("%.5lf", *(pTP->pesquisaBinaria));
        gotoxy(CALT,4);//linha 4 coluna ALEATORIO
        printf("%.5lf", *(pTP->pesquisaBinaria));
        
        gotoxy(CORD,7);//linha 7 coluna ORDENADO
        printf("%.5lf", ((pTP->algoritmoOrdenacao->ordenado) + *(pTP->pesquisaBinaria)));
        gotoxy(CINV,7);//linha 7 coluna INVERIDO
        printf("%.5lf", ((pTP->algoritmoOrdenacao->invertido) + *(pTP->pesquisaBinaria)));
        gotoxy(CALT,7);//linha 7 coluna ALEATORIO
        printf("%.5lf", ((pTP->algoritmoOrdenacao->aleatorio) + *(pTP->pesquisaBinaria)));
    }

    if(pTP->algoritmoOrdenacao != NULL){
        gotoxy(CORD+1,5);//linha 5 coluna ORDENADO
        printf("%.4lf", pTP->algoritmoOrdenacao->ordenado);
        gotoxy(CINV+1,5);//linha 5 coluna ORDENADO
        printf("%.4lf", pTP->algoritmoOrdenacao->invertido);
        gotoxy(CALT+1,5);//linha 5 coluna ORDENADO
        printf("%.4lf", pTP->algoritmoOrdenacao->aleatorio);
    }

    gotoxy(5,14);
    printf("Aperte qualquer tecla para voltar ao menu!");
    fflush(stdin);
    getch();
}
#pragma Screen
//? ============================================================================ALGORITMOS========================================================================
#pragma Algoritmos 
double bubbleSort(int vetor[], int tam){
    clock_t inicio = clock();
    for (int j = tam; j > 0; j--){
        for(int i = 0; i < j; i++) {
            if(vetor[i] > vetor[i+1]){
                int aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

double insertSort(int vetor[], int tam){
    clock_t inicio = clock();
    for(int i = 1, y = 0; i < tam ; i++){
        int aux = vetor[i];
        y = i-1;
        while((y>=0) && (aux < vetor[y])){
            vetor[y+1] = vetor[y];
            y = y-1;
            vetor[y+1] = aux;
        }
    }
    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

double selectionSort(int vetor[], int tam){
    int menor;
    clock_t inicio = clock();

    for (int i = 0; i < tam-1; i++){
        menor = i;
        for (int j = i+1; j < tam; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        if(menor != i){
            int temp = vetor[menor];
            vetor[menor] = vetor[i];
            vetor[i] = temp;
        }
    }

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

double shellSort(int vetor[], int tam){
    int h, aux;
    clock_t inicio = clock();

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
    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

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
        int aux2 = vetor[esq];
        vetor[esq] = vetor[dir];
        vetor[dir] = aux2;
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

	hoare(vetor, tam);

	double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

	return tempo;
}

int partitionLomuto(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return (i + 1);
}

void lomuto(int arr[], int low, int high){
    while (low < high) {
        int index = partitionLomuto(arr, low, high);
        if((index-low) <= (high-index)){
            lomuto(arr, low, index - 1);
            low = index+1;
        }else{
            lomuto(arr, index + 1, high);
            high = index-1;
        }
    }
}

double quickSortLomuto(int *vetor, int tam){
    clock_t inicio = clock();

    lomuto(vetor, 0, tam - 1);

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

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

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
  
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
      
        heapify(arr, n, largest);
    }
}

double heapSort(int arr[], int n) {
    clock_t inicio = clock();
    
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        heapify(arr, i, 0);
    }
    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;
    
    return tempo;
}

int buscaSequencial(int vetor[], int tam, int key){
    for (int t = 0; t < tam; t++){
        if (vetor[t] == key){
            return t;
        }
    }

    return -1;
}

double pesquisaSequencial(int vetor[], int tam, int key){
    clock_t inicio = clock();

    buscaSequencial(vetor, tam, key);

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;
    
    return tempo;
}

int buscaBinaria(int vetor[], int ini, int fim, int key){

    int mei = (ini + fim) / 2;
    if((ini == fim) && !(key == vetor[mei])){
        return -1;
    }else{
        if(key == vetor[mei]){
            return mei;
        }
        else{
            if(key > vetor[mei]){
                return buscaBinaria(vetor, mei+1, fim, key);
            }else{
                return buscaBinaria(vetor, ini, mei-1, key);
            }
        }
    }
}

double pesquisaBinaria(int vetor[], int tam, int key){
    clock_t inicio = clock();

    buscaBinaria(vetor, 0, tam, key);

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;
    
    return tempo;
}
#pragma Algoritmos
//? ============================================================================ARQUIVOS==========================================================================
#pragma Arquivos 
int randomInteger (int high){
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    int k = d * (high - 0 + 1);
    return 0 + k;
}

void ordenado(char nome[], int tam){
    FILE *ordenado;
    char nomeArquivo[255];

    sprintf(nomeArquivo, "%sOrdenado%05d.txt", nome, tam);
    ordenado = fopen(nomeArquivo, "w");
    for(int x=1; x<tam; x++){
        fprintf(ordenado, "%d\n", x);
    }
    fclose(ordenado);
}

void invertido(char nome[], int tam){
    FILE *invertido;
    char nomeArquivo[255];

    sprintf(nomeArquivo, "%sInvertido%05d.txt", nome, tam);
    invertido = fopen(nomeArquivo, "w");
    for(int x=tam; x>=1; x--){
        fprintf(invertido, "%d\n", x);
    }
    fclose(invertido);
}

void gerarAleatorio(int tam){
    FILE *aleatorio;
    char nomeArquivo[255];

    srand(time(NULL));
    sprintf(nomeArquivo, "Aleatorio%05d.txt", tam);
    aleatorio = fopen(nomeArquivo, "w");
    for(int i=0; i<tam; i++){
        fprintf(aleatorio, "%d\n", randomInteger(tam));
    }
    fclose(aleatorio);
}

void aleatorio(char nome[], int tam){
    FILE *original, *novo;
    char nomeOriginal[255], nomeNovo[255], c;

    sprintf(nomeOriginal, "Aleatorio%05d.txt", tam);
    sprintf(nomeNovo, "%sAleatorio%05d.txt", nome, tam);

    original = fopen(nomeOriginal, "r");
    novo = fopen(nomeNovo, "w");

    c = fgetc(original);
    while (c != EOF){
        fputc(c, novo);
        c = fgetc(original);
    }

    fclose(novo);
    fclose(original);
}

void gerarArquivosAleatorio(){
    for (int i = 0, tam = 500000; i < 3; i++, tam+=250000){
        gerarAleatorio(tam);
    }
}

void lerArquivo (FILE *file, int vetor[]){
    for (int i = 0; !feof (file); i++){
        fscanf (file, "%d", &vetor[i]);
    }
}
#pragma endregion
//? ============================================================================ORDENAÇÃO=========================================================================
#pragma Ordenação 
pTempo ordenar(int tam, algOrdenacao algoritmo){
    pTempo pt = malloc(sizeof(Tempo));

    int *vetor = malloc(tam * sizeof(int));
    double tOrdenado, tInvertido, tAleatorio;

    FILE *ordenado, *invertido, *aleatorio;
    char nomeOrdenado[255], nomeInvertido[255], nomeAleatorio[255];

    sprintf(nomeOrdenado, "Ordenado%05d.txt", tam);
    sprintf(nomeInvertido, "Invertido%05d.txt", tam);
    sprintf(nomeAleatorio, "Aleatorio%05d.txt", tam);

    ordenado = fopen(nomeOrdenado, "r");
    invertido = fopen(nomeInvertido, "r");
    aleatorio = fopen(nomeAleatorio, "r");
    printf("\n\tOrdenando Arquivo Ordenado...");

    lerArquivo(ordenado, vetor);
    tOrdenado = algoritmo(vetor, tam);

    printf("\n\tOrdenando Arquivo Invertido...");

    lerArquivo(invertido, vetor);
    tInvertido = algoritmo(vetor, tam);

    printf("\n\tOrdenando Arquivo Aleatorio...");

    lerArquivo(aleatorio, vetor);
    tAleatorio = algoritmo(vetor, tam);

    pt->ordenado = tOrdenado;
    pt->invertido = tInvertido;
    pt->aleatorio = tAleatorio;

    free(vetor);

    return pt;
}
#pragma Ordenação
//? ============================================================================PESQUISA==========================================================================
#pragma Pesquisa 
int achaMax(int vetor[], int tam){
    int maior = 0;

    for (int i = 0; i < tam; i++){
        if(vetor[i]>maior){
            maior = vetor[i];
        }
    }
    return maior;
    
}

double* pesquisar(int tam, algPesquisa algoritmo, algOrdenacao algOrd, pTPesquisa pTP){
    pTempo ptOrd = ordenar(tam, algOrd);
    //pt = 

    int *vetor = malloc(tam * sizeof(int));
    double *tPesquisa = malloc(sizeof(double));

    FILE *ordenado;
    char nomeOrdenado[255];

    sprintf(nomeOrdenado, "Ordenado%05d.txt", tam);

    ordenado = fopen(nomeOrdenado, "r");
    lerArquivo(ordenado, vetor);

    int max = achaMax(vetor, tam);

    printf("\n\tPesquisando no Arquivo...");
    
    *tPesquisa = algoritmo(vetor, tam, max);

    pTP->algoritmoOrdenacao = ptOrd;
    
    free(vetor);

    return tPesquisa;
}
#pragma Pesquisa
//? ============================================================================MENUS=============================================================================
#pragma Menus 
int menuTamanho(){
    system("cls");
    
    int option;
    printf("    ** Escolha o tamanho do arquivo **\n\n");
    printf("\t\t1- 500 Mil\n");
    printf("\t\t2- 750 Mil\n");
    printf("\t\t3- 1 Milhao\n");
    printf("\t\t4- Sair\n");

    fflush(stdin);
    option = getch();
    switch (option){
        case '1':
            ordenado("", Q500K);
            invertido("", Q500K);
            option = Q500K;
            break;
        case '2':
            ordenado("", Q750K);
            invertido("", Q750K);
            option = Q750K;
            break;
        case '3':
            ordenado("", Q1KK);
            invertido("", Q1KK);
            option = Q1KK;
            break;
        case '4':
            system("cls");
            printf("Adeus!");
            option = 0;

    default:
        system("cls");
        printf("Erro: Opcao nao encontrada");
        break;
    }

    return option;
}

int menuEscolha(){
    system("cls");

    printf("    ** Escolha se oque quer realizar **\n\n");
    printf("\t\t1- Ordenacao\n");
    printf("\t\t2- Pesquisa\n");
    printf("\t\t3- Sair\n");
    
    fflush(stdin);
    int option = getch();
    
    switch (option){
        case '1':
            option = 1;
            break;
        case '2':
            option = 2;
            break;
        case '3':
            system("cls");
            printf("Adeus!");
            option = 0;

    default:
        system("cls");
        printf("Erro: Opcao nao encontrada");
        break;
    }

    return option;
}

int menuOrdenacao(pTOrdenacao pTO){
    int option;

    system("cls");
    printf("\t** Escolha o algoritmo de ordenacao **\n\n");
    printf("\t\t   1- BubbleSort\n");
    printf("\t\t   2- InsertSort\n");
    printf("\t\t   3- SelectSort\n");
    printf("\t\t   4- ShellSort\n");
    printf("\t\t   5- QuickSort Hoare\n");
    printf("\t\t   6- QuickSort Lomuto\n");
    printf("\t\t   7- MergeSort\n");
    printf("\t\t   8- RadixSort\n");
    printf("\t\t   9- HeapSort\n");
    printf("\t\t   0- Todos\n");
    printf("\t\t   ESC- Sair\n");

    fflush(stdin);
    option = getch();
    switch (option){
        case '1':
            system("cls");
            printf("\t     ** BubbleSort **");
            pTO->bubbleSort = ordenar(pTO->tam, bubbleSort);
            tabDraw(pTO);
            break;
        case '2':
            system("cls");
            printf("\t     ** InsertSort **");
            pTO->insertSort = ordenar(pTO->tam, insertSort);
            tabDraw(pTO);
            break;
        case '3':
            system("cls");
            printf("\t     ** SelectSort **");
            pTO->selectSort = ordenar(pTO->tam, selectionSort);
            tabDraw(pTO);
            break;
        case '4':
            system("cls");
            printf("\t     ** ShellSort **");
            pTO->shellSort = ordenar(pTO->tam, shellSort);
            tabDraw(pTO);
            break;
        case '5':
            system("cls");
            printf("\t     ** QuickSort Hoare **");
            pTO->quickSortHoare = ordenar(pTO->tam, quickSortHoare);
            tabDraw(pTO);
            break;
        case '6':
            system("cls");
            printf("\t     ** QuickSort Lomuto **");
            pTO->quickSortLomuto = ordenar(pTO->tam, quickSortLomuto);
            tabDraw(pTO);
            break;
        case '7':
            system("cls");
            printf("\t     ** MergeSort **");
            pTO->mergeSort = ordenar(pTO->tam, mergeSort);
            tabDraw(pTO);
            break;
        case '8':
            system("cls");
            printf("\t     ** RadixSort **");
            pTO->radixSort = ordenar(pTO->tam, radixSort);
            tabDraw(pTO);
            break;
        case '9':
            system("cls");
            printf("\t     ** HeapSort **");
            pTO->heapSort = ordenar(pTO->tam, heapSort);
            tabDraw(pTO);
            break;
        case '0':
            system("cls");
            printf("\t     ** BubbleSort **");
            pTO->bubbleSort = ordenar(pTO->tam, bubbleSort);
            printf("\n\t     ** InsertSort **");
            pTO->insertSort = ordenar(pTO->tam, insertSort);
            printf("\n\t     ** SelectSort **");
            pTO->selectSort = ordenar(pTO->tam, selectionSort);
            printf("\n\t     ** ShellSort **");
            pTO->shellSort = ordenar(pTO->tam, shellSort);
            printf("\n\t     ** QuickSort Hoare **");
            pTO->quickSortHoare = ordenar(pTO->tam, quickSortHoare);
            printf("\n\t     ** QuickSort Lomuto **");
            pTO->quickSortLomuto = ordenar(pTO->tam, quickSortLomuto);
            printf("\n\t     ** MergeSort **");
            pTO->mergeSort = ordenar(pTO->tam, mergeSort);
            printf("\n\t     ** RadixSort **");
            pTO->radixSort = ordenar(pTO->tam, radixSort);
            printf("\n\t     ** HeapSort **");
            pTO->heapSort = ordenar(pTO->tam, heapSort);
            tabDraw(pTO);
            system("cls");
            tabDraw(pTO);
            break;
        case 27: //?ESC
            system("cls");
            printf("Adeus!");
            return OUTLP;
            break;
        default:
            system("cls");
            printf("Erro opcao nao identificada");
            printf("\n\nAperte qualquer tecla para voltar ao menu!");
            getch();
            break;
    }
    return option;
}

int menuPesquisa(pTPesquisa pTP){
    int option;

    system("cls");
    printf("\t** Escolha o algoritmo de pesquisa **\n\n");
    printf("\t\t   1- Pesquisa Sequencial\n");
    printf("\t\t   2- Pesquisa Binaria\n");
    printf("\t\t   3- Todos\n");
    printf("\t\t   ESC- Sair\n");

    fflush(stdin);
    option = getch();
    switch (option){
    case '1':
        system("cls");
        printf("\t     ** Pesquisa Sequencial **");
        pTP->pesquisaSequencial = pesquisar(pTP->tam, pesquisaSequencial, quickSortHoare, pTP);
        tabDrawPesquisa(pTP);
        break;
    case '2':
        system("cls");
        printf("\t     ** Pesquisa Binaria **");
        pTP->pesquisaBinaria = pesquisar(pTP->tam, pesquisaBinaria, quickSortHoare, pTP);
        tabDrawPesquisa(pTP);
        break;
    case '3':
        system("cls");
        printf("\t     ** Pesquisa Sequencial **");
        pTP->pesquisaSequencial = pesquisar(pTP->tam, pesquisaSequencial, quickSortHoare, pTP);
        printf("\n\t     ** Pesquisa Binaria **");
        pTP->pesquisaBinaria = pesquisar(pTP->tam, pesquisaBinaria, quickSortHoare, pTP);
        tabDrawPesquisa(pTP);
        break;
    case 27:
        system("cls");
        printf("Adeus");
        return OUTLP;
        break;    
    default:
        system("cls");
        printf("Erro opcao nao identificada");
        printf("\n\nAperte qualquer tecla para voltar ao menu!");
        getch();
        break;
    }
    return option;
}

void menuInicial(pTOrdenacao pTO, pTPesquisa pTP){
    pTO->tam = menuTamanho();
    pTP->tam = pTO->tam;
    if(pTO->tam !=0){
        int escolha = menuEscolha();
        if(escolha==1){
            while(menuOrdenacao(pTO) != OUTLP);
        }else if(escolha==2){
            while(menuPesquisa(pTP) != OUTLP);
        }else{
            system("cls");
        }
    }
}
#pragma Menus
//? ============================================================================MAIN==============================================================================

int main(){
    pTOrdenacao pTO = criarStructOrdenacao();
    pTPesquisa  pTP = criarStructPesquisa();
    setScreenSize(800,600);
    showCursor(0);

    printf("Gerando Arquivos...");
    gerarArquivosAleatorio();
    system("cls");
    system("color 0F");
    menuInicial(pTO, pTP);

    free(pTO);
    free(pTP);
}