#include <stdio.h>
#define MAX 20

void troca(int *a,int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}


void Bubblesort_R(int v[],int n){

    int i;

    if(n != 0){
        for(i = 0;i < n ;i++){
            if(v[i] > v[i + 1]){
                troca(&v[i],&v[i + 1]);
            }
        }
        Bubblesort_R(v,n - 1);
    }
}

int main(){

    int vetor[MAX];
    int i;

    for(i = 0; i < 10;i++){
        scanf("%d", &vetor[i]);
    }

    Bubblesort_R(vetor,10);

    for(i = 0; i < 10;i++){
        printf("%d ",vetor[i]);
    }

    return 0;

}