#include <stdio.h>

#define MAX 1000

int main(){

    int vetor[MAX];
    int t,p = 0;

    scanf("%d",&t);

    for(int i = 0;i < 1000;i++){
        if(p == t){
            p = 0;
        }
        vetor[i] = p;
        p++;
    }

    for(int i = 0;i<1000;i++){
        printf("N[%d] = %d\n",i,vetor[i]);
    }

 return 0;
}