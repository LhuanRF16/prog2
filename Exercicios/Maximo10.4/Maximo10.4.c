#include <stdio.h>
#define MAX 100    

int *maximo(int n, int v[]){

    int *max = v,*i;

    for(i = v;i < v + n;i++){
        if(*max < *i)
            max = i;
    }

    return max;
}

int main(){

    int v[MAX],n,i,*p;

    scanf("%d",&n);

    for(i = 0;i < n;i++){
        scanf("%d",&v[i]);
    }

    p = maximo(n,v);

    printf("%d\n",*p);

}