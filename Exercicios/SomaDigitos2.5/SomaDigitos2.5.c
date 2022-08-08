#include <stdio.h>

int somadigitos(int n){

    if(n < 10){
        return n;
    }
    else{
        return (n % 10) + somadigitos(n / 10);
    }

}



int main(){

    int soma,x;

    scanf("%d",&x);

    soma  = somadigitos(x);

    printf("%d",soma);
    
    return 0;
}