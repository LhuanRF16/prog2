#include <stdio.h>

int main(){

    int casos,termo;
    long long int anterior1,anterior2,fib,aux;

    scanf("%d",&casos);

    for(int i  = 0;i < casos;i++){
        scanf("%d",&termo);
        anterior1 = 1;
        anterior2 = 0;
        if(termo == 0){
            printf("Fib(0) = 0\n");
        }
        else if(termo == 1){
            printf("Fib(1) = 1\n");
        }
        else{
            for(int i = 0;i < termo - 2;i++){
                aux = anterior1;
                anterior1 += anterior2;
                anterior2 = aux; 
            }
            fib = anterior1 + anterior2;
            printf("Fib(%d) = %lld\n",termo,fib);
        }
    }

    return 0;
}