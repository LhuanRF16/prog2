#include <stdio.h>

int main(int argc,char *argv[]){

    int i,soma = 0;
    for(i = 1;i < argc;i++){
        soma += atoi(argv[i]);
    }

    printf("%d",soma);

    return 0;
}

