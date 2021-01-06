#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<iostream>
using namespace std;

double autovalor = 0;
double *autovetor;

double produtoEscalar(double *v1, double *v2, int n){
	double v = 0;
	int i;
	for(i=0;i<n;i++){
		v += v1[i]*v2[i];
	}

	return v;
}

double raizEuclidiana(double *v, int n){
	double raiz = 0;
	int i;
	for(i=0;i<n;i++){
		raiz = raiz + pow(v[i],2);
	}

	return sqrt(raiz);
}

double* multiMatrizVetor(double **m1, double *v, int n1, int n2, int n3){
	int i, w;
	double *v2;

	v2 = (double*)calloc((n1),sizeof(double*));

	if(n2==n3){
		for(w=0;w<n1;w++){
			for(i=0;i<n3;i++){
				v2[w] += (m1[w][i])*(v[i]);
			}
		}
	}

	return v2;
}

double** multiMatriz(double **m1, double **m2, int n1, int n2, int n3, int n4){
	int i, j, w;
	double **m3;

	m3 = (double**)malloc((n1)*sizeof(double*));
	for(i=0;i<n1;i++){
		m3[i] = (double*)calloc((n4),sizeof(double));
	}

	if(n2==n3){
		for(w=0;w<n1;w++){
			for(i=0;i<n2;i++){
				for(j=0;j<n4;j++){
					m3[w][j] += (m1[w][i])*(m2[i][j]);
				}
			}
		}
	}
	return m3;
}

void potencia(double **a, double *v, double e, int n){
	int i;
	double *v1, *v2;
	double autovalor2;

	v1 = (double*)calloc((n),sizeof(double));
	v2 = (double*)calloc((n),sizeof(double));
	autovetor = (double*)calloc((n),sizeof(double));

	for(i=0;i<n;i++){
		v2[i] = v[i];
	}

	do{
		autovalor2 = autovalor;
		for(i=0;i<n;i++){
			v1[i] = v2[i];
		}
		for(i=0;i<n;i++){
			autovetor[i] = v1[i]/raizEuclidiana(v1,n);
		}
		for(i=0;i<n;i++){
			v2[i] = multiMatrizVetor(a,autovetor,n,n,n)[i];
		}
		autovalor = produtoEscalar(autovetor, v2, n);
	}while(fabs((autovalor - autovalor2)/autovalor) > e);

	cout<<"Autovalor: "<<autovalor<<endl;
	cout<<"Autovetor: [";
	for(i=0;i<n;i++){
		cout<<autovetor[i]<<" ";
	}
	cout<<"]"<<endl;
}

int main(int argc, char const *argv[]){
	int n,i,j;
	double pos, e;
	double **a;
	double *v;
	ifstream readfile;
	ofstream file;

	readfile.open("matriz.txt");
	file.open("resultado.txt");

	readfile >> n;
	v = (double*)calloc((n),sizeof(double));
	a = (double**)malloc((n)*sizeof(double*));
	for(i=0;i<n;i++){
		a[i] = (double*)malloc((n)*sizeof(double));
		for(j=0;j<n;j++){
			readfile >> a[i][j];
		}
	}

	cout<<"Entre os valores das posições do vetor: "<<endl;
	for(i=0;i<n;i++){
		cout<<"Entre o valor do elemento v["<<i<<"]"<<endl;
		cin>>pos;
		v[i] = pos;
	}

	file<<"Vetor: [";
	cout<<"Vetor: [";
	for(i=0;i<n;i++){
		cout<<v[i]<<" ";
		file<<v[i]<<" ";
	}

	cout<<"]"<<endl;
	file<<"]"<<endl;
	
	cout<<"Entre o valor da tolerancia:"<<endl;
	cin>>e;
	file<<"Tolerancia: "<<e<<endl;
	potencia(a,v,e,n);

	file<<"Autovalor: "<<autovalor<<endl;
	file<<"Autovetor: [";
	for(i=0;i<n;i++){
		file<<autovetor[i]<<" ";
	}
	file<<"]"<<endl;

	file.close();

	cout<<"Resultado armazenado em 'resultado.txt'"<<endl;

	return 0;
}