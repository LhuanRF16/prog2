#include <stdio.h>
#define MAX 20

void troca(int *a,int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}


int separaD(int p, int r, int v[]){

    int x, i, j;

    x = v[p];
    i = p - 1;
    j = r + 1;
    while (i < j) {

        do {
            j--;
        } while (v[j] < x);

        do {
            i++;
        } while (v[i] > x);

        if (i < j)
            troca(&v[i], &v[j]);
    }
    return j;
}

void quicksortD(int p, int r, int v[]){

    int q;

    if (p < r) {
        q = separaD(p, r, v);
        quicksortD(p, q, v);
        quicksortD(q+1, r, v);
    }
}

int main(){

    int vetor[MAX];

    for(int i = 0; i < 10;i++){
        scanf("%d", &vetor[i]);
    }

    quicksortD(0,9,vetor);

    for(int i = 0;i < 10;i++){
        printf("%d ",vetor[i]);
    }

    return 0;

}