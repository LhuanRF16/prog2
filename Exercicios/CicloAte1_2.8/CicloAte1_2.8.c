#include <stdio.h>

int ciclo(int n){

    int i;

    for(i = 0;n != 1;i++){
        if(n % 2 == 0){
            printf("%d ",n);
            n /= 2;
        }
        else{
            printf("%d ",n);
            n = (3 * n) + 1;
        }
    }
    printf("1\n");
    i++;
    return i;
}

int cicloR(int n,int v[]){

    if(n == 1){
        printf("1\n");
        v[0] += 1;
        return 1;
    }
    else if(n % 2 == 0){
        printf("%d ",n);
        v[0] += 1;
        return cicloR(n/2,v);
    }
    else{
        printf("%d ",n);
        v[0] += 1;
        return cicloR((3 * n) + 1,v);
    }   
}


int main(){

    int comprimento,x;
    int chamadas[1];

    scanf("%d",&x);
    chamadas[0] = 0;

    comprimento = ciclo(x);
    printf("comprimento do ciclo nao recursivo = %d\n",comprimento);
    comprimento = cicloR(x,chamadas);
    printf("comprimento do ciclo recursivo = %d\n",chamadas[0]);

    return 0;
}