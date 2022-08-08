#include <stdio.h>

int main(){

    int x;
    int vetor[10];

    scanf("%d",&x);

    for(int i = 0 ; i < 10 ; i++){
        vetor[i] = x;
        x *= 2;
    }

    for(int i = 0 ; i < 10 ; i++){
        printf("N[%d] = %d\n",i,vetor[i]);
    }

    return 0;

}