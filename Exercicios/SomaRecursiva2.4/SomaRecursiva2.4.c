#include <stdio.h>
#include <stdlib.h>
#define MAX 100


float somavetor(int n,float v[]){

    if(n == 1){
         return v[0];
    }
    else{
        return v[n-1] + somavetor(n - 1,v);
    }

}

int main(){

    int n;
    float vetor[MAX];
    float soma;

    scanf("%d",&n);

    for(int i = 0; i < n ; i++){
        scanf("%f",&vetor[i]);
    }

    soma = somavetor(n,vetor);
    printf("%f",soma);

    return 0;
}