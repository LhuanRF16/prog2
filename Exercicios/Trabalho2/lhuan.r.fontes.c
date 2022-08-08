/**************************************************
*
* Lhuan Rodrigues Fontes
* Trabalho 2
* Professor(a): Diego Rubert
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VEICULOS 5
#define NUM_PILHAS 3
//---------------------------------------------------------------------------------------------------------
typedef struct cel {
    char placa[9];
    struct cel *prox; // Proximo veiculo
} veiculo;
//---------------------------------------------------------------------------------------------------------
typedef struct {
    int veiculos; // Quantidade de veiculos estacionados 
    veiculo *topo; // Topo da pilha 
} pilha;
//---------------------------------------------------------------------------------------------------------
typedef struct {
    veiculo *fim; // Fim da fila
    veiculo *i; // Inicio da fila
} fila;
//---------------------------------------------------------------------------------------------------------
typedef struct {
    char data[11];
    pilha P[NUM_PILHAS]; // Armazena as pilhas
} estacionamento;
//---------------------------------------------------------------------------------------------------------
void troca(int *a,int *b){ // Troca o valor de dois numeros interos

    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
//---------------------------------------------------------------------------------------------------------
void bubblesort(int n, int v[]){// Ordena um vetor em ordem crescente

    int i, j;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j+1])
                troca(&v[j], &v[j+1]);
}
//---------------------------------------------------------------------------------------------------------
void enfileira(veiculo**f,char* y){// Adiciona um veiculo no fim da fila

    veiculo *novo;

    novo = (veiculo *) malloc(sizeof (veiculo));
    strcpy(novo->placa,y);
    novo->prox = NULL;
    (*f)->prox = novo;
    *f = novo;
}
//---------------------------------------------------------------------------------------------------------
void desenfileira(veiculo *i, veiculo **f){// Remove um veiculo do inicio da fila

    veiculo *p;

    p = i->prox;
    if (p != NULL) {
        i->prox = p->prox;
        free(p);
        if (i->prox == NULL)
            *f = i;
    }

}
//---------------------------------------------------------------------------------------------------------
void desempilha(veiculo *t){// Remove o veiculo do topo da pilha

    veiculo *p;

    if (t->prox != NULL) {
        p = t->prox;
        t->prox = p->prox;
        free(p);
    }
}
//---------------------------------------------------------------------------------------------------------
void empilha(char* p,veiculo*t){// Adiciona um veiculo no topo da pilha

    veiculo *novo;

    novo = (veiculo *) malloc(sizeof (veiculo));
    strcpy(novo->placa,p);
    novo->prox = t->prox;
    t->prox = novo;
}
//---------------------------------------------------------------------------------------------------------
veiculo *menosveiculos(estacionamento *pe){// Encontra a pilha com menos veiculos

    int v[3];

    v[0] = pe->P[0].veiculos;
    v[1] = pe->P[1].veiculos;
    v[2] = pe->P[2].veiculos;

    bubblesort(3,v);

    if(pe->P[0].veiculos == v[0] && pe->P[0].veiculos < MAX_VEICULOS){
        pe->P[0].veiculos += 1;
        return pe->P[0].topo;
    }
    else if(pe->P[1].veiculos == v[0] && pe->P[1].veiculos < MAX_VEICULOS){
        pe->P[1].veiculos += 1;
        return pe->P[1].topo;
    }
    else if(pe->P[2].veiculos == v[0] && pe->P[2].veiculos < MAX_VEICULOS){
        pe->P[2].veiculos += 1;
        return pe->P[2].topo;
    }
    else{
        return NULL;
    }

}
//---------------------------------------------------------------------------------------------------------
void inserepilhaM(veiculo *t){// Adiciona um veiculo no topo da pilha e mostra a operacao

    char p[9];

    scanf(" %s",p);
    if(t == NULL){
        printf("C %s\n",p);
    }
    else{
        veiculo *novo;

        novo = (veiculo *) malloc(sizeof (veiculo));
        strcpy(novo->placa,p);
        novo->prox = t->prox;
        t->prox = novo;
        printf("E %s\n",novo->placa);
    }

}
//---------------------------------------------------------------------------------------------------------
void insereestacionamentoM(estacionamento *pe){// Adiciona um veiculo no local ideal do estacionamento
    inserepilhaM(menosveiculos(pe));
}
//---------------------------------------------------------------------------------------------------------
void Mpilha(veiculo *t,int n){// Mostra os veiculos de uma pilha

    t = t->prox;
    if(t == NULL){
        printf("P%d:\n",n);
    }
    else{
        printf("P%d:",n);
    }

    while(t != NULL){
        if(t->prox != NULL){
            printf("%s,",t->placa);
        }
        else{
            printf("%s\n",t->placa);
        }
        t = t->prox;
    }

}
//---------------------------------------------------------------------------------------------------------
void removepilhaM(pilha* p,char* pl){// Remove um veiculo da pilha e mostra a operacao

    fila f;
    char comppl[9];
    f.i = (veiculo *) malloc(sizeof (veiculo));
    f.i->prox = NULL;
    f.fim = f.i;

    if(p == NULL){
        printf("N %s\n",pl);
    }
    else{
        while(strcmp(p->topo->prox->placa,pl) != 0){
            enfileira(&(f.fim),p->topo->prox->placa);
            desempilha(p->topo);  
        }
        desempilha(p->topo);
        while(f.i->prox != NULL){
            empilha(f.i->prox->placa,p->topo);
            desenfileira(f.i,&(f.fim));
        }
        free(f.i);
        p->veiculos -= 1;
        printf("S %s\n",pl);
    }
}
//---------------------------------------------------------------------------------------------------------
void limpapilha(pilha *p){// Limpa uma pilha de veiculos

    int v;

    for(v = 0;v < p->veiculos;v++){
        desempilha(p->topo);
    }
    p->veiculos = 0;
}
//---------------------------------------------------------------------------------------------------------
void limpaestacionamento(estacionamento *pe){// Limpa todos os veiculos do estacionamento

    limpapilha(&(pe->P[0]));
    limpapilha(&(pe->P[1]));
    limpapilha(&(pe->P[2]));
}
//---------------------------------------------------------------------------------------------------------
pilha *encontraplaca(estacionamento *pe,char *p){// Encontra em qual pilha esta um determinado veiculo

    veiculo* v;
    v = pe->P[0].topo;
    v = v->prox;
    while(v != NULL){
        if(strcmp(v->placa,p) == 0){
            return &(pe->P[0]);
        }
        v = v->prox;
    }

    v = pe->P[1].topo;
    v = v->prox;
    while(v != NULL){
        if(strcmp(v->placa,p) == 0){
            return &(pe->P[1]);
        }
        v = v->prox;
    }

    v = pe->P[2].topo;
    v = v->prox;
    while(v != NULL){
        if(strcmp(v->placa,p) == 0){
            return &(pe->P[2]);
        }
        v = v->prox;
    }
    return NULL;
}
//---------------------------------------------------------------------------------------------------------
int main(){

    estacionamento estac;
    int casos,pi;
    char op,pl[9];
    estac.P[0].veiculos = 0;
    estac.P[1].veiculos = 0;
    estac.P[2].veiculos = 0;
    estac.P[0].topo = (veiculo *) malloc(sizeof (veiculo));
    estac.P[0].topo->prox = NULL;
    estac.P[1].topo = (veiculo *) malloc(sizeof (veiculo));
    estac.P[1].topo->prox = NULL;
    estac.P[2].topo = (veiculo *) malloc(sizeof (veiculo));
    estac.P[2].topo->prox = NULL;

    scanf("%d",&casos);

    for(;casos > 0;casos--){
        scanf(" %s",estac.data);
        printf("%s\n",estac.data);
        scanf(" %c",&op);
        while(op != 'F'){
            if(op == 'E'){
                insereestacionamentoM(&estac);
            }
            else if(op == 'S'){
                scanf(" %s",pl);
                removepilhaM(encontraplaca(&estac,pl),pl);
            }
            else if(op = 'I'){
                scanf(" P%d",&pi);
                Mpilha(estac.P[pi].topo,pi);
            }
            scanf(" %c",&op);
        }
        limpaestacionamento(&estac);
        printf("F\n");
        printf("\n");
    }
    free(estac.P[0].topo);
    free(estac.P[1].topo);
    free(estac.P[2].topo);
    return 0;
}