#include <stdio.h>
#define MAX 1000

int bubblesort(int n,int v[]){
    int  aux;
    for(int i = n - 1; i > 0;i--){
        for(int j = 0; j < i;j++){
            if(v[j] > v[j +1]){
                aux = v[j + 1];
                v[j + 1] = v[j];
                v[j] = aux;
            }   
        }
    }
}



int main(){
    int cadastros[MAX];
    int casos;

    while(scanf("%d",&casos) == 1){
        for(int i = 0;i < casos;i++){
            scanf("%d",&cadastros[i]);
        }

        bubblesort(casos,cadastros);

        for(int i = 0;i < casos;i++){
            if(cadastros[i] < 10){
                printf("000%d\n",cadastros[i]);
            }
            else if(cadastros[i] < 100){
                printf("00%d\n",cadastros[i]);
            }
            else if(cadastros[i] < 1000){
                printf("0%d\n",cadastros[i]);
            }
            else{
                printf("%d\n",cadastros[i]);
            }
        }
    }
    return 0;
}