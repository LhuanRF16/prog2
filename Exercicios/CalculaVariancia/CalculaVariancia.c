#include <stdio.h>
#define MAX 1000

int main(){

    float amostra[MAX];
    float media;
    int tamanho;
    int soma = 0;
    float variancia = 0;

    scanf("%d",&tamanho);

    for(int i = 0;i < tamanho;i++){
        scanf("%f",&amostra[i]);
    }

    for(int i = 0;i < tamanho;i++){
        soma += amostra[i];
    }

    printf("soma = %d\n",soma);


    media = soma/(float)tamanho;

    printf("media = %.4f\n",media);

    for(int i = 0;i < tamanho;i++){
        variancia += (amostra[i] - media) * (amostra[i] - media);
    }

    printf("variancia = %.4f",variancia/(tamanho - 1));

}