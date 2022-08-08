/**************************************************
*
* Lhuan Rodrigues Fontes
* Trabalho 1
* Professor:Diego Rubert 
*
*/

#include <stdio.h>
#define MAX 1000

typedef struct {
    int numero;
    int ultrapass;
} capivara;

//********************************************************************************

void intercala(int p,int q,int r,capivara v[]){

    capivara w[MAX];
    int i,j,k;
    i = p;
    j = q;
    k = 0;

    while(i < q && j < r){
        if(v[i].ultrapass > v[j].ultrapass){
            w[k] = v[i];
            i++;
        }
        else if(v[i].ultrapass == v[j].ultrapass){
            if(v[i].numero < v[j].numero){
                w[k] = v[i];
                i++;
            }
            else{
                w[k] = v[j];
                j++;
            }
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
        v[i] = w[i - p];
    }

}

//********************************************************************************

void mergesort(int p,int r,capivara v[]){
    int q;
    if(p < r - 1){
        q = (p + r)/2;
        mergesort(p,q,v);
        mergesort(q,r,v);
        intercala(p,q,r,v);

    }
}

//********************************************************************************

void trocac(capivara *a,capivara *b){

    capivara aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

//********************************************************************************

int main(){

    int competidores,ultra,i;

    scanf("%d",&competidores);

    capivara capivaras[competidores];

    for(i = 0;i < competidores;i++){
        capivaras[i].numero = i + 1;
        capivaras[i].ultrapass = 0;
    }

    while(scanf("%d",&ultra) != EOF){
        for(i = 0;i < competidores;i++){
            if(capivaras[i].numero == ultra){
                capivaras[i].ultrapass += 1;
                trocac(&capivaras[i],&capivaras[i - 1]);
            }
        }
    }

    for(i = 0;i < competidores;i++){
        if(i != competidores - 1){
            printf("%d ",capivaras[i].numero);
        }
        else{
            printf("%d\n",capivaras[i].numero);
        }
    }

    mergesort(0,competidores,capivaras);

    for(i = 0;i < competidores;i++){
        if(i != competidores - 1){
            printf("%d ",capivaras[i].numero);
        }
        else{
            printf("%d\n",capivaras[i].numero);
        }
    }
    
    return 0;
}