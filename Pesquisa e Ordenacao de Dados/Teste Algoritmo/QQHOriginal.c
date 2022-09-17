int partQQOH(int *vetor, int esq, int dir){
    int x = vetor[esq], up = dir, down = esq;
    while (down < up){
        while(vetor[down] <= x && down < dir){
            down++;
        }
        while(vetor[up] > x){
            up--;
        }
        if (down < up){
            int aux = vetor[down];
		    vetor[down] = vetor[up];
		    vetor[up] = aux;
        }
    }

    vetor[esq] = vetor[up];
    vetor[up] = x;
    return up;
}

int qqOH(int *vetor, int esq, int dir){
    int i;
    if(dir > esq){
        i = partQQOH(vetor, esq, dir);
        qqOH(vetor, esq, i-1);
        qqOH(vetor, i + 1, dir);
    }
}