#include <stdio.h>

int main(){

    int soma = 0;

    for(int i = 2;i < 101;){
        soma += i;
        i += 2;
    }

    printf("%d",soma);
}