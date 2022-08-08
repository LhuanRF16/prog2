#include <stdio.h>
int main(void)
{
    int a, b, *pt1, *pt2;

    pt1 = &a;//pt1 recebeu o endereco de 'a'
    pt2 = &b;//pt2 recebeu o endereco de 'b'
    a = 1;//'a' recebeu 1
    (*pt1)++;//a varivavel que pt1 aponta('a') recebeu mais 1
    b = a + *pt1;//'b' recebeu 'a' mais o valor que pt1 aponta('a')
    *pt2 = *pt1 * *pt2;//a variavel que pt2 aponta('b') recebeu o valor que pt1 aponta('a') vezes o valor que pt2 aponta('b')
    printf("a=%d, b=%d, *pt1=%d, *pt2=%d\n", a, b, *pt1, *pt2);//mostra o valor de 'a' , 'b' , valor que pt1 aponta('a'),valor que pt2 aponta('b')

    return 0;
}
