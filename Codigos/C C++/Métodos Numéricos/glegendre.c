#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x){
	return (x*x)/((x*x*x)-2);
}

double parametrizar(double a, double b, double s){
	return (((a+b)/2) + ((a-b)/2)*s);
}
	
double plegendre(double a, double b, double t, double wi[], double xi[], int pontos){
	double I, I1 = 0;
	double N0, N1 = 1;
	double a0, a1, b0, b1, aux0, aux1, xp0, xp1, deltax0, deltax1;
	
	int p,i;
	
	do{
		N0 = N1;
		N1 = 2*N1;
		
		deltax0 = (b-a)/N0;
		deltax1 = (b-a)/N1;
		
		for(i = 0;i < N0;i++){
			a0 = a + i*deltax0;
			b0 = a0 + deltax0;
			for(p = 0;p < pontos; p++){
				xp0 = parametrizar(a0,b0,xi[p]);
				I = I + (wi[p]*f(xp0));
			}
		}
		
		I = (deltax0/2) * I;
		
		for(i = 0;i < N1;i++){
			a1 = a + i*deltax1;
			b1 = a1 + deltax1;
			for(p = 0;p < pontos; p++){
				xp1 = parametrizar(a1,b1,xi[p]);
				I1 = I1 + (wi[p]*f(xp1));
			}
		}
		
		I1 = (deltax1/2) * I1;		
	
	}while(fabs((I1-I)/I) > t);
	
	return I1; 
}

double glegendre2pontos(double a, double b, double t){
	double wi[] = {1.0, 1.0};
	double xi[] = {-0.57735, 0.57735};
	
	return plegendre(a, b, t, wi, xi, 2);
}

double glegendre3pontos(double a, double b, double t){
	double wi[] = {0.888889, 0.555556, 0.555556 };
	double xi[] = {0.0, -0.7745966692414834, 0.7745966692414834};
	
	return plegendre(a, b, t, wi, xi, 3);
}

double glegendre4pontos(double a, double b, double t){
	double wi[] = {0.6521451548625461, 0.6521451548625461, 0.3478548451374538, 0.3478548451374538};
	double xi[] = {-0.3399810435848563, 0.3399810435848563, -0.8611363115940526, 0.8611363115940526};
	
	return plegendre(a, b, t, wi, xi, 4);
}

double glegendre5pontos(double a, double b, double t){
	double wi[] = {0.5688888888888889, 0.4786286704993665, 0.4786286704993665, 0.2369268850561891, 0.2369268850561891};
	double xi[] = {0.0, -0.5384693101056831, 0.5384693101056831, -0.9061798459386640, 0.9061798459386640};
	
	return plegendre(a, b, t, wi, xi, 5);
}

double glegendre6pontos(double a, double b, double t){
	double wi[] = {0.3607615730481386, 0.3607615730481386, 0.4679139345726910, 0.4679139345726910, 0.1713244923791704, 0.1713244923791704};
	double xi[] = {0.6612093864662645, -0.6612093864662645, -0.2386191860831969, 0.2386191860831969, -0.9324695142031521, 0.9324695142031521};
	
	return plegendre(a, b, t, wi, xi, 6);
}

int main(){
	int op, n;
	double a, b, t, v;

	do{
		printf("Entre o valor do inicio do intervalo: ");
		scanf("%lf", &a);
		printf("\nEntre o valor do final do intervalo: ");
		scanf("%lf", &b);
		printf("\nEntre o valor da tolerancia: ");
		scanf("%lf", &t);
		printf("Entre o valor do numero de pontos de legendre a ser usado no somatorio(1 a 5): ");
		scanf("\n%d", &op);
	
		switch(op){
			case 1:
				v = glegendre2pontos(a,b,t);
				break;
			case 2:
				v = glegendre3pontos(a,b,t);
				break;
			case 3:
				v = glegendre4pontos(a,b,t);
				break;
			case 4:
				v = glegendre5pontos(a,b,t);
				break;
			case 5:
				v = glegendre6pontos(a,b,t);
				break;
		}
		
		printf("\n%lf", v);
		
		printf("\nDeseja calcular de novo? (1 - sim  2 - nao)");
		scanf("\n%d", &n);
		
	}while(n==1);
	
	
}
