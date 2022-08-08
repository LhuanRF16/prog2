#include <stdio.h>
#define MAX 30

void intercala(int p,int q ,int r , int v[]){
    int i , j ,d, k ,w[MAX];
    i = p;
    j = q;
    k = 0;
    d = 0;
    while(i < q && j < r){
        if(v[i] <= v[j]){
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

    for(i = p;i < r;i++){
        v[i] = w[d];
        d++;
    }

}

void mergesort(int p,int r,int v[]){
    int q;
    
    if(p < r - 1){
        q = (p + r)/2;
        mergesort(p,q,v);
        mergesort(q,r,v);
        intercala(p,q,r,v);
    }
}

void troca(int *a,int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int separa (int p, int r, int v[MAX]){

    int x,i,j;
    x = v[p];
    i = p ;
    j = r ;

    while(i < j){
        while(v[j] > x){
            j--;
        }
        while(v[i] < x){
            i++;
        }
        if(i < j){
            troca(&v[i],&v[j]);
        }
    }
    return j;
}

void quicksort(int p, int r, int v[MAX]){
    
    int q;
    if (p < r) {
        q = separa(p, r, v);
        quicksort(p, q, v);
        quicksort(q+1, r, v);
    }
}




int main(){

    int vetor[20];

    for(int i = 0; i < 20;i++){
        scanf("%d",&vetor[i]);
    }

    quicksort(0,19,vetor);

    for(int i = 0;i < 20;i++){
        printf("%d ",vetor[i]);
    }

    return 0;

}