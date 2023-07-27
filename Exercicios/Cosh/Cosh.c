#include <stdio.h>
#include <math.h>
#define e 2.718281828

long double cosh(double a){

    long double aux = pow(e, a);

    return (aux + 1/(aux))/2;
}

long double senh(double a){

    long double aux = pow(e, a);

    return (aux - 1/(aux))/2;
}

int main(){

    long double angulo;
    printf("informe um angulo\n");
    scanf("%lf",&angulo);

    printf("Cosh = %lf\n",cosh(angulo));
    printf("Senh = %lf",senh(angulo));

}