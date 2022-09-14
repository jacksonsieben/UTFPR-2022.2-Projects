#define Q500K 500000
#define Q750K 750000
#define Q1KK  1000000
#define OUT 6
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 400

#define CORD 28
#define CINV 37
#define CALT 48

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

/**  
    *!                                          Anotacoes
    *? talvez gerar um relatorio ao selecionar no menu para que possa ter os dados gerados de forma mais eficiente
    *? CRIAR UMA MATRIZ QUE VAI COLOCAR O TEMPO DE CADA ALGORITIMO E IMPRIMIR COM GOTOXY TODA VEZ QUE FOR USADO UM ALGORITIMO
    *? pensar em gerar o relatorio de forma txt pra ter isso armazenado, e poder trocar o tamanho do arquivo
    *? ver o shellSort.c par verificar se vou por o tamanho da tela mais setado
    *! \t é equivalente a 8 espaços no console
    *TODO TABELA 500 MIL
    *TODO TABELA 750 MIL
    *TODO TABELA 1 MILHAO
    ** QuickSort Hoare
    ** QuickSort Lomoto
    ** Mergesort https://gist.github.com/olegon/27c2a880c9b932862e60ab5eb89be5b6
    ** Radixsort
**/

char tabela [10][47]=   { //                                                       |13                                |meio*/
                        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', 'T', 'A', 'B', 'E', 'L', 'A', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', 'O', 'R', 'D', 'E', 'N', 'A', 'D', 'O', '|', 'I', 'N', 'V', 'E', 'R', 'T', 'I', 'D', 'O', '|', 'A', 'L', 'E', 'A', 'T', 'O', 'R', 'I', 'O', '|'},
                        {'B', 'U', 'B', 'B', 'L', 'E', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', '|', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'I', 'N', 'S', 'E', 'R', 'T', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', '|', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'S', 'E', 'L', 'E', 'C', 'T', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', '|', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},        
                        {'S', 'H', 'E', 'L', 'L', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'Q', 'U', 'I', 'C', 'K', 'S', 'O', 'R', 'T', ' ', 'H', 'O', 'A', 'R', 'E', ' ', '|', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'Q', 'U', 'I', 'C', 'K', 'S', 'O', 'R', 'T', ' ', 'L', 'O', 'M', 'U', 'T', 'O', '|', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'M', 'E', 'R', 'G', 'E', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'},
                        {'R', 'A', 'D', 'I', 'X', 'S', 'O', 'R', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|', '*', '*', '*', '*', '*', '*', '*', '*', '*', '|'}
                        };// 47 colunas, 10 linhas

struct tempo{
    double ordenado;
    double invertido;
    double aleatorio;
};

struct tAlgoritmo{
    int tam;
    struct tempo *bubbleSort;
    struct tempo *insertSort;
    struct tempo *selectSort;
    struct tempo *shellSort;
    struct tempo *quickSortHoare;
    struct tempo *quickSortLomuto;
    struct tempo *mergeSort;
    struct tempo *radixSort;
};

typedef struct tempo  Tempo;
typedef Tempo*        pTempo;

typedef struct tAlgoritmo  TAlgoritmo;
typedef TAlgoritmo*        pTAlgoritmo;

typedef double (algOrdenacao(int v[], int tam));

pTAlgoritmo criarStruct(){
    pTAlgoritmo pTA = malloc(sizeof(TAlgoritmo));

    pTA->tam = 0;
    pTA->bubbleSort = NULL;
    pTA->insertSort = NULL;
    pTA->selectSort = NULL;
    pTA->shellSort  = NULL;

    return pTA;
}

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

void frame (int ci, int cf, int li, int lf){
    int l,c;
    for (c=ci+1; c<=cf-1;c++){
        gotoxy(c, li); printf("%c", 220);
        gotoxy(c, lf); printf("%c", 223);
    }
    for (l=li; l<=lf;l++){
        gotoxy(ci, l); printf("%c", 219);
        gotoxy(cf, l); printf("%c", 219);
    }
    gotoxy(ci, li); printf("%c", 220);
    gotoxy(cf, li); printf("%c", 220);
    gotoxy(ci, lf); printf("%c", 223);
    gotoxy(cf, lf); printf("%c", 223);
}

void tabDraw (pTAlgoritmo pTA){
    system("cls");
    int l, c;
    for (l=0; l<47; l++){
        for (c=0; c<10; c++){
            gotoxy(10+l,1+c);
            switch (tabela [c][l]){
                case '*': printf(" ");   break;
                /*case 'b': printf("%c", 3);   break;
                case 'e': printf("%c", 42);  break;
                case 'f': printf("%c", 250); break;*/
                default: printf("%c", tabela [c][l]);
            }
        }
    }
    if(pTA->tam != Q1KK){
        gotoxy(CINV,1);
        printf("%d MIL", (pTA->tam/1000));
    }else{
        gotoxy(CINV,1);
        printf("1 MILHAO");
    }

    if(pTA->bubbleSort != NULL){
        gotoxy(CORD,3);//linha 3 coluna ORDENADO
        printf("%.2lfs", pTA->bubbleSort->ordenado);
        gotoxy(CINV,3);//linha 3 coluna INVERTIDO
        printf("%.2lfs", pTA->bubbleSort->invertido);
        gotoxy(CALT,3);//linha 3 coluna ALEATORIO
        printf("%.2lfs", pTA->bubbleSort->aleatorio);
    }

    if(pTA->insertSort != NULL){
        gotoxy(CORD,4);//linha 4 coluna ORDENADO
        printf("%.2lfs", pTA->insertSort->ordenado);
        gotoxy(CINV,4);//linha 4 coluna INVERTIDO
        printf("%.2lfs", pTA->insertSort->invertido);
        gotoxy(CALT,4);//linha 4 coluna ALEATORIO
        printf("%.2lfs", pTA->insertSort->aleatorio);
    }

    if(pTA->selectSort != NULL){    
        gotoxy(CORD,5);//linha 5 coluna ORDENADO
        printf("%.2lfs", pTA->selectSort->ordenado);
        gotoxy(CINV,5);//linha 5 coluna INVERTIDO
        printf("%.2lfs", pTA->selectSort->invertido);
        gotoxy(CALT,5);//linha 5 coluna ALEATORIO
        printf("%.2lfs", pTA->selectSort->aleatorio);
    }

    if(pTA->shellSort != NULL){    
        gotoxy(CORD+1,6);//linha 6 coluna ORDENADO
        printf("%.2lfs", pTA->shellSort->ordenado);
        gotoxy(CINV+1,6);//linha 6 coluna INVERTIDO
        printf("%.2lfs", pTA->shellSort->invertido);
        gotoxy(CALT,6);//linha 6 coluna ALEATORIO //! tirei o CALT+1
        printf("%.2lfs", pTA->shellSort->aleatorio);
    }

    gotoxy(5,14);
    printf("Aperte qualquer tecla para voltar ao menu!");
    fflush(stdin);
    getch();
}

/** 
   *TODO ==================================================================ALGORITMOS==================================================================
**/

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

void troca(int vet[], int i, int j){
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

int particionaHoare(int vet[], int esq, int dir){
	int x = vet[esq], up = dir, down = esq;
	while(down < up){
		while(vet[down] <= x && down < dir){
			down++;
		}
		while(vet[up] > x){
			up--;
		}
		if(down < up){
			troca(vet, down, up);
		}
	}

	vet[esq] = vet[up];
	vet[up] = x;

	return up;
}

double hoare(int vetor[], int esq, int dir){
	int i;
	clock_t inicio = clock();

	if(dir > esq){
		i = particionaHoare(vetor, esq, dir);
		hoare(vetor, esq, i-1);
		hoare(vetor, i+1, dir);
	}

	double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

double quickSortHoare(int vetor[], int tam){
	return hoare(vetor, 0, tam-1);
}

void merge(int a[], int esq, int meio, int dir) {
    int i, j, k;
    int aux[dir];
    for (i = meio +1; i > esq; i--){
        aux[i-1] = a[i-1];
    }

    for (j = meio; j < dir; j++){
        aux[dir + meio -j] = a[j+1];
    }

    for (k = esq; k <= dir; k++){
        if (aux[j] < aux[i]){
            a[k] = aux[j--];
        }else{
            a[k] = aux[i++];
        }
    }
}

double mergeAlg(int a[], int esq, int dir) {
    clock_t inicio = clock();

    if (esq < dir) {
        int meio = (esq + dir) / 2;
        mergeAlg(a, esq, meio);
        mergeAlg(a, meio +1, dir);
        merge(a, esq, meio, dir);
    }

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

double mergeSort(int vetor[], int tam){
    return mergeAlg(vetor, 0, tam - 1);
}
/** 
   *? =================================================================================ARQUIVOS=======================================================================
**/
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

/** 
   *? ============================================================================ORDENAÇÃO============================================================================
**/

pTempo ordenar(int tam, algOrdenacao algoritmo){//TODO: trazer funcao por parametro
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

    return pt;
}
/** 
   *? ============================================================================MENUS============================================================================
**/

int menuTamanho(){
    system("cls");
    
    int option;
    printf("    ** Escolha o tamanho do arquivo **\n\n");
    printf("\t\t1- 500 Mil\n");
    printf("\t\t2- 750 Mil\n");
    printf("\t\t3- 1 Milhão\n");
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
        printf("Erro: Opção não encontrada");
        break;
    }

    return option;
}

int menuAlgoritmo(pTAlgoritmo pTA){
    int option;
    
    system("cls");
    printf("\t** Escolha o algoritmo de ordenação **\n\n");
    printf("\t\t   1- BubbleSort\n");
    printf("\t\t   2- InsertSort\n");
    printf("\t\t   3- SelectSort\n");
    printf("\t\t   4- ShellSort\n");
    printf("\t\t   5- QuickSort Hoare\n");
    printf("\t\t   6- QuickSort Lomuto\n");
    printf("\t\t   7- MergeSort\n");
    printf("\t\t   8- RadixSort\n");
    printf("\t\t   9- Todos\n");
    printf("\t\t   0- Sair\n");

    fflush(stdin);
    option = getch();
    switch (option){
        case '1': 
            system("cls");
            printf("\t     ** BubbleSort **");
            pTA->bubbleSort = ordenar(pTA->tam, bubbleSort);
            tabDraw(pTA);
            break;
        case '2':
            system("cls");
            printf("\t     ** InsertSort **");
            pTA->insertSort = ordenar(pTA->tam, insertSort);
            tabDraw(pTA);
            break;
        case '3':
            system("cls");
            printf("\t     ** SelectSort **");
            pTA->selectSort = ordenar(pTA->tam, selectionSort);
            tabDraw(pTA);
            break;
        case '4':
            system("cls");
            printf("\t     ** ShellSort **");
            pTA->shellSort = ordenar(pTA->tam, shellSort);
            tabDraw(pTA);
            break;
        case '5':
            system("cls");
            printf("\t     ** QuickSort Hoare **");
            pTA->quickSortHoare = ordenar(pTA->tam, quickSortHoare);
            tabDraw(pTA);
            break;
        case '6':
            system("cls");
            printf("\t     ** QuickSort Lomuto **");
            //pTA->quickSortLomuto = ordenar(pTA->tam, quickSortLomuto);
            tabDraw(pTA);
            break;
        case '7':
            system("cls");
            printf("\t     ** MergeSort **");
            pTA->mergeSort = ordenar(pTA->tam, mergeSort);
            tabDraw(pTA);
            break;
        case '8':
            system("cls");
            printf("Indisponivel");
            /*printf("\t     ** RadixSort **");
            pTA->radixSort = ordenar(pTA->tam, radixSort);
            tabDraw(pTA);*/
            break;
        case '9':
            system("cls");
            printf("\t     ** BubbleSort **");
            pTA->bubbleSort = ordenar(pTA->tam, bubbleSort);
            printf("\n\t     ** InsertSort **");
            pTA->insertSort = ordenar(pTA->tam, insertSort);
            printf("\n\t     ** SelectSort **");
            pTA->selectSort = ordenar(pTA->tam, selectionSort);
            printf("\n\t     ** ShellSort **");
            pTA->shellSort = ordenar(pTA->tam, shellSort);
            system("cls");
            tabDraw(pTA);
            break;
        case '0':
            system("cls");
            printf("Adeus!");
            return 0;
            break;
        default:
            system("cls");
            printf("Erro opção não identificada");
            printf("\n\nAperte qualquer tecla para voltar ao menu!");
            getch();
            break;
    }
    return option; 
}

void menuInicial(pTAlgoritmo pTA){
    pTA->tam = menuTamanho();
    if(pTA->tam == 0){
        system("cls");
    }else{
        while(menuAlgoritmo(pTA) != 0);
    }
}

int main(){
    pTAlgoritmo pTA = criarStruct();
    setlocale(LC_ALL,"Portuguese_Brazil.1252");
    
    setScreenSize(800,600);
    showCursor(0);

    printf("Gerando Arquivos...");
    gerarArquivosAleatorio();
    system("cls");
    system("color 0F");
    menuInicial(pTA);
    
    free(pTA);
}
