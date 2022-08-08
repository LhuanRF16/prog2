#include <stdio.h>
#define MAX 20

void pula(int v[],int k,int n){

    int w[MAX];
    int i,j = k,p = 0;


    for(i = k;i < n;i++){
        w[p] = v[i];
        p++;
    }

    for(i = 0;i < p;i++){
        v[j + 1] = w[i];
        j++;
    }

}

int insere(int n, int v[], int k, int y){

    pula(v,k,n);
    v[k] = y;
    return n + 1;
}

int insere_R(int n, int v[], int k, int y,int c[]){

    if(n == k){
        v[k] = y;
        c[0] += 1;
        return c[0] + k;
    }
    v[n] = v[n - 1];
    c[0] += 1;
    insere_R(n - 1,v,k,y,c);
}


int main(){

    int vetor[MAX],contador[1];
    int i,posicaoi,valori,novot;

    for(i = 0 ; i < 10 ;i++){
        scanf("%d",&vetor[i]);
    }

    scanf("%d %d",&posicaoi,&valori);

    novot = insere(10,vetor,posicaoi,valori);

    for(i = 0; i < 11;i++){
        printf("%d ",vetor[i]);
    }

    printf("\n");

    printf("novo tamanho do vetor apos a funcao nao recursiva %d\n",novot);

    scanf("%d %d",&posicaoi,&valori);

    contador[0] = 0;

    novot = insere_R(11,vetor,posicaoi,valori,contador);

    for(i = 0; i < 12;i++){
        printf("%d ",vetor[i]);
    }

    printf("\n");

    printf("novo tamanho do vetor apos a funcao recursiva %d\n",novot);

    return 0;

}