
#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int chave;
  struct cel *prox;
} celula;


/* Recebe um ponteiro para uma lista linear encadeada com
   cabeça e imprime o conteúdo de cada uma de suas células */
void imprime_lista_C(celula *lst)
{
  celula *p;
  for (p = lst->prox; p != NULL; p = p->prox)
    printf("%d ", p->chave);
  printf("\n");
}

celula *busca(int x, celula *lst)
{
  celula *p,*ant;
  ant = lst;
  p = lst->prox;
  while (p != NULL && p->chave < x){
    ant = p;
    p = p->prox;
  }

  return ant;
}

void insere(int y, celula *p)
{
  celula *nova;
  nova = (celula *) malloc(sizeof (celula));
  nova->chave = y;
  nova->prox = p->prox;
  p->prox = nova;
}


/* Recebe um ponteiro para uma lista linear encadeada com
   cabeça e um inteiro y e insere y na lista de modo que a
   lista permaneça em ordem crescente */
void insere_ord_C(int y, celula *lst)
{
  celula *p;
  p = busca(y,lst);
  insere(y,p);
}

/* Recebe uma sequencia de n numeros inteiros inserindo-os em uma
   lista de forma ordenada. Então imprime a lista resultante */
int main(void)
{
  int y;
  celula *lst;

  lst = (celula *) malloc(sizeof (celula));
  lst->prox = NULL;

  while (scanf("%d", &y) != EOF)
    insere_ord_C(y, lst);
  
  imprime_lista_C(lst);
 
  return 0;
}