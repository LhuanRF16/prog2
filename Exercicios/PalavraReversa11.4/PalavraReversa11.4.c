#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){

    int letra;
    char mensagem[MAX];
    char *p = mensagem;

    while ((letra = getchar()) != '\n'){
        *p = letra;
        p++;
    }

    p--;

    for(;p >= mensagem;p--){
        printf("%c",*p);
    }

    return 0;

}