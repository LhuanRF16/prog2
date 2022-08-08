#include <stdio.h>
#define MAX 100000

void intercala(int p,int q ,int r , int v[]){
    int i , j , k ,w[MAX];
    i = p;
    j = q;
    k = 0;
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
    for (i = p; i < r; i++)
        v[i] = w[i-p];


    /*i = p;

    for(k = 0;k < r;k++){
        v[i] = w[k];
        i++;
        k++;
    }*/

    
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


int main(){
    
    int n,valor,par,impar;
    int pares[MAX],impares[MAX];

    scanf("%d",&n);
    par = 0;
    impar = 0;

    for(int i = 0; i < n;i++){

        scanf("%d",&valor);

        if(valor % 2 == 0){
            pares[par] = valor;
            par++;
        }
        else{
            impares[impar] = valor;
            impar++;
        }
    }

    mergesort(0,par + 1,pares);
    mergesort(0,impar + 1,impares);

    for(int i = 1;i < par + 1;i++){
        printf("%d\n",pares[i]);
    }
    for(int i = impar;i >= 1;i--){
        printf("%d\n",impares[i]);
    }

    return 0;

}