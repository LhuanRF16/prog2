#include <stdio.h>
#define MAX 20

void intercala(int p,int q ,int r , int v[]){
    int i , j , k ,w[MAX];
    i = p;
    j = q;
    k = 0;
    while(i < q && j < r){
        if(v[i] >= v[j]){
            w[k] = v[i];
            i++;
        }
        else{
            w[k] = v[j];
            j++;
        }
        k++;
    }
    while(i < q){
        w[k] = v[i];
        i++;
        k++;
    }
    while(j < r){
        w[k] = v[j];
        j++;
        k++;
    }
    for (i = p; i < r; i++)
        v[i] = w[i-p];
   
}

void mergesort(int p, int r, int v[]){
    int q;
    if (p < r - 1) {
        q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}



int main(){

    int vetor[MAX];

    for(int i = 0;i < 10;i++){
        scanf("%d",&vetor[i]);
    }

    mergesort(0,10,vetor);
    printf("vetor em ordem decrescente por mergesort\n");

    for(int i = 0; i < 10;i++){
        printf("%d ",vetor[i]);
    }

    return 0;

}