#include <stdio.h>

int main(){

    int vetor[20],aux;

    for(int i = 0;i < 20;i++){
        scanf("%d",&vetor[i]);
    }

    for(int i = 0;i < 10;i++){
        aux = vetor[i];
        vetor[i] = vetor[19 - i];
        vetor[19 - i] = aux;
    }

    for(int i = 0; i < 20; i++){
        printf("N[%d] = %d\n",i,vetor[i]);
    }

    return 0;

}