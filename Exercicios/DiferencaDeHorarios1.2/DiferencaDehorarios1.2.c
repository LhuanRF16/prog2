#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hh;
    int mm;
    int ss;
} hora;

void diferenca(hora x[2]){
    int dif[3];
    dif[0]= x[0].hh - x[1].hh;
    if(x[0].mm < x[1].mm){
        x[0].mm += 60;
        dif[0] -= 1;
    }
    dif[1] = x[0].mm - x[1].mm;
    if(x[0].ss < x[1].ss){
        x[0].ss += 60;
        dif[1] -= 1;
    }
    dif[2] = x[0].ss - x[1].ss;

    if(dif[0] < 10 && dif[1] < 10 && dif[2] < 10){
        printf("0%d:0%d:0%d\n",dif[0],dif[1],dif[2]);
    }
    else if(dif[0] < 10 && dif[1] < 10){
        printf("0%d:0%d:%d\n",dif[0],dif[1],dif[2]);
    }
    else if(dif[0] < 10 && dif[2] < 10){
        printf("0%d:%d:0%d\n",dif[0],dif[1],dif[2]);
    }
    else if(dif[1] < 10 && dif[2] < 10){
        printf("%d:0%d:0%d\n",dif[0],dif[1],dif[2]);
    }
    else if(dif[0] < 10){
        printf("0%d:%d:%d\n",dif[0],dif[1],dif[2]);
    }
    else if(dif[1] < 10){
        printf("%d:0%d:%d\n",dif[0],dif[1],dif[2]);
    }
    else if(dif[2] < 10){
        printf("%d:%d:0%d\n",dif[0],dif[1],dif[2]);
    }
    else{
        printf("%d:%d:%d\n",dif[0],dif[1],dif[2]);
    }
}


int main(){

    hora horas[2],aux[1];

    scanf("%d:%d:%d",&horas[0].hh,&horas[0].mm,&horas[0].ss);
    scanf("%d:%d:%d",&horas[1].hh,&horas[1].mm,&horas[1].ss);

    if(horas[0].hh  < horas[1].hh){
        aux[0] = horas[0];
        horas[0] = horas[1];
        horas[1] = aux[0];
    }

    if(horas[0].hh == horas[1].hh && horas[0].mm < horas[1].mm){
        aux[0] = horas[0];
        horas[0] = horas[1];
        horas[1] = aux[0];
    }

    if(horas[0].hh == horas[1].hh && horas[0].mm == horas[1].mm && horas[0].ss < horas[1].ss){
        aux[0] = horas[0];
        horas[0] = horas[1];
        horas[1] = aux[0];
    }

    diferenca(horas);

    return 0;
}

