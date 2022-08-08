#include <stdio.h>
#define MAX 10

int remover(int n, int v[], int k){

    int i;

    for(i = k; i < n;i++){
        v[i] = v[i + 1];
    }

    return n - 1;

}

int remover_R(int n,int v[],int k){

    int i;

    if(k < n){
        v[k] = v[k + 1];
        remover_R(n,v,k + 1);
    }

    return n - 1;
}

int main(){

    int vetor[MAX];
    int i,elemr,novot;

    for(i = 0;i < MAX;i++){
        scanf("%d",&vetor[i]);
    }

    scanf("%d",&elemr);

    novot = remover(MAX,vetor,elemr);

    printf("novo tamanho pela funcao nao recursiva %d\n",novot);
    
    for(i = 0;i< MAX - 1;i++){
        printf("%d ",vetor[i]);

    }

    printf("\n");

    scanf("%d",&elemr);

    novot = remover_R(MAX - 1,vetor,elemr);

    printf("novo tamanho pela funcao recursiva %d\n",novot);

    for(i = 0;i < MAX - 2;i++){
        printf("%d ",vetor[i]);

    }





}