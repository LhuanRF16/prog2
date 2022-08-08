#include <stdio.h>

int main(){

    double iniciador;
    double vetor[100];

    scanf("%lf",&iniciador);
    vetor[0] = iniciador;

    for(int i = 1;i < 100;i++){
        iniciador /= 2; 
        vetor[i] = iniciador;
    }

    for(int i = 0; i< 100;i++){
        printf("N[%d] = %.4lf\n",i,vetor[i]);
    }

    return 0;
}