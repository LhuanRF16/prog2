#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void quicksort(int p, int r, int v[]);
int separa(int p, int r, int v[]);
void mergesort(int p, int r, int v[]);
void intercala(int p,int q ,int r , int v[]);
void troca(int *a, int *b);
void copia_tmp(int n, int v[], int tmp[]);
void bubblesort(int n, int v[]);
void selectionsort(int n, int v[]);
void insertionsort(int n, int v[]);


int main(void)
{
  int i, v[MAX], tmp[MAX];
  int n = MAX;
  clock_t inicio, fim;

  /* initialize random seed: */
  srand (time(NULL));

  for (i = 0; i < n; i++)
    v[i] = rand();  // vetor aleatório
    //v[i] = i;     // vetor ordenado
    //v[i] = n - i; // vetor decrescente
    

  printf("%d elementos\n", n);

  
  copia_tmp(n, v,tmp);
  inicio = clock();
  bubblesort(n, tmp);
  fim = clock();
  printf("BUBBLE: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

  copia_tmp(n, v,tmp);
  inicio = clock();
  selectionsort(n, tmp);
  fim = clock();
  printf("SELECTION: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);
  
  copia_tmp(n, v,tmp);
  inicio = clock();
  insertionsort(n, tmp);
  fim = clock();
  printf("INSERTION: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

  copia_tmp(n, v,tmp);
  inicio = clock();
  mergesort(0,MAX,tmp);
  fim = clock();
  printf("MERGESORT: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

  copia_tmp(n, v,tmp);
  inicio = clock();
  quicksort(0,MAX - 1,tmp);
  fim = clock();
  printf("QUICKSORT: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

  return 0;
}

void troca(int *a, int *b)
{
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

void copia_tmp(int n, int v[], int tmp[])
{
  for (int i = 0; i < n; i++)
    tmp[i] = v[i];
}

void bubblesort(int n, int v[])
{
  int i, j;
  for (i = n - 1; i > 0; i--)
    for (j = 0; j < i; j++)
      if (v[j] > v[j+1])
	troca(&v[j], &v[j+1]);
}

void selectionsort(int n, int v[])
{
  int i, j, min;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i+1; j < n; j++)
      if (v[j] < v[min])
	min = j;
    troca(&v[i], &v[min]);
  }
}

void insertionsort(int n, int v[])
{
  int i, j, x;
  for (i = 1; i < n; i++) {
    x = v[i];
    for (j = i - 1; j >= 0 && v[j] > x; j--)
      v[j+1] = v[j];
    v[j+1] = x;
  }
}

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

int separa(int p, int r, int v[]){

    int x, i, j;

    x = v[p];
    i = p - 1;
    j = r + 1;
    while (i < j) {

        do {
            j--;
        } while (v[j] > x);

        do {
            i++;
        } while (v[i] < x);

        if (i < j)
            troca(&v[i], &v[j]);
    }
    return j;
}

void quicksort(int p, int r, int v[]){

    int q;

    if (p < r) {
        q = separa(p, r, v);
        quicksort(p, q, v);
        quicksort(q+1, r, v);
    }
}