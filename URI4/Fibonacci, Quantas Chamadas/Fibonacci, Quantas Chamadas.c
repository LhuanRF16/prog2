#include <stdio.h>

fib(int x,int *y){
    if(x == 1){
        (*y)++;
        return 1;
    }
    else if(x == 0){
        (*y)++;
        return 0;
    }
    else{
        (*y)++;
        return fib(x - 1,y) + fib(x - 2,y);
    }
}

int main(){

    int casos,valor,res,chamadas = 0;
    int *p;

    p = &chamadas;

    scanf("%d", &casos);

    for(;casos > 0;casos--){
        scanf("%d",&valor);
        res = fib(valor,p);

        printf("fib(%d) = %d calls = %d\n",valor,chamadas - 1,res);
        *p = 0;
    }

    return 0;
}