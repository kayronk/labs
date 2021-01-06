#include <stdio.h>
#include <stdlib.h>

int main(){
    float a = 0., b = 0., E = 0., M = 0., Fa = 0., Fb = 0., Fm = 0.;
    int k = 0;

    printf( "Digite valor de A:" );
    scanf( "%f", &a );
    printf( "Digite valor de B:" );
    scanf( "%f", &b );
    printf( "Digite valor de E:" );
    scanf( "%f", &E );

    printf("\n");

    do{
        M = ( a + b ) / 2.;
        Fa = ( a*a*a ) - (9. * a) + 3.; //insira a sua fun��o aqui para calcular F(a)
         Fm = ( M*M*M ) - (9. * M) + 3.; //insira a sua fun��o aqui para calcular F(M)
        Fb = ( b*b*b ) - (9. * b) + 3.; //insira a sua fun��o aqui para calcular F(b)
        if ( Fa * Fm < 0 )
           b = M;
        else
           a = M;
       k += 1;
       printf( "iteracao = %d\n", k );
       printf( "A = %f\nB = %f\n", a, b );
    } while( b - a >= E || Fa >= E || Fb >= E);
    //se for verdade ele continua o la�o

    printf("\nb - a = %f\n", b - a);
    printf( "A solucao final eh: %f\n", ( a + b ) / 2. );
    return 0;
}