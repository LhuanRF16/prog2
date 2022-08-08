#include <stdio.h>

void MI(int n,int m[]){

    int *p,i = 0;

    for(p = m;p < m + (n * n);p++){
        if(i % (n + 1) == 0){
            *p = 1;
        }
        else{
            *p = 0;
        }
        i++;
    }

}


int main(){

    int t;
    scanf("%d",&t);
    int matriz[t][t];

    MI(t,matriz);

    for(int i = 0;i < t;i++){
        for(int j = 0;j < t;j++){
            if(j == t - 1){
                printf("%d\n",matriz[i][j]);
            }
            else{
                printf("%d ",matriz[i][j]);
            }
        }
    }
}

