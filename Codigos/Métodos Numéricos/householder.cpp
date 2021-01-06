#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <time.h>
#include <string>

#define DEBUG 0

using namespace std;

typedef vector< vector <double> > Matriz;
typedef vector<double> Vetor;

struct MatrizDupla{
    Matriz A;
    Matriz Q;
};

double normaMatriz(Matriz);
Matriz construirJ(Matriz, int, int);
Matriz jacobi(Matriz , double );

// rótulos pelo Householder

Matriz Householder( Matriz, int);
double normaVetor( Vetor);
Matriz Tridiagonal ( Matriz);
Matriz produtoVetor( Vetor, Vetor);

// Rótulos pelo QR

Matriz montar_Qij( Matriz, int, int);
MatrizDupla obter_QR( Matriz);
Matriz QR (Matriz, double);

Matriz transposta(Matriz A){

	int n = A.size();
	Matriz T;

	T.resize(n);

	for(int i = 0; i < n; i++)
		T[i].resize(n);

	for(int i = 0 ; i < n; i++){
		for (int j = 0; j < n; j++)
			T[j][i] = A[i][j];
	}

	return T;
}

void alocar(Matriz &A, int n){
	A.resize(n);
	for(int i = 0; i < n; i++){
		A[i].resize(n);
		for(int j = 0; j < n; j++)
			A[i][j] = 0;
	}
}

void lerArquivo(Matriz &A, string arq){

	ifstream entrada;

	entrada.open(arq.c_str());

	if(!entrada.is_open()){
		cout << "Ocorreu um erro na leitura do arquivo! \n";
		entrada.clear();
		exit(-1);
	}

	int n;

	entrada >> n;

	alocar(A, n); // alocando a matriz n x n

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			entrada >> A[i][j];

}

/*	Função imprimir, imprime a matriz A
*/
void imprimir(Matriz &A){
	cout << "\n";
	for (int i = 0 ; i < A.size(); i++){
		cout << "\t";
		for(int j = 0 ; j < A[i].size() ; j++)
			cout << A[i][j] << "\t\t ";
		cout << "\n";
	}
	cout << "\n";
}

void deletar(Matriz &A){
	for(int i = 0; i < A.size(); i++)
		A[i].resize(0);
	A.resize(0);
}


void gravarArquivo(string arq, double lambda, Vetor x){

	//ofstream outFile (arq.c_str(), ios::ate);
	ofstream outFile;
	outFile.open(arq.c_str());

	if(!outFile.is_open()){
		cerr << "Erro na gravação de solução no arquivo! \n";
		outFile.clear();
		exit(-1);
	}

	outFile << "Maior autovalor: " << lambda << endl;

	outFile << "Autovetor: ";
	for(int i = 0; i < x.size(); i++){
		outFile << x[i] << " ";
	}

	outFile.close();
}

Matriz produto(Matriz &A, Matriz &B) {
	Matriz J;

	int n = A.size();

	J.resize(n);

	// inicializando cada posição de J com 0
	for(int i = 0; i < n; i++)
		J[i].resize(n);


	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)

	for (int i = 0 ; i < n; i++)
		for(int j = 0 ; j < n; j++){
			J[i][j] = 0;
			for(int k = 0; k < n; k++)
				J[i][j] = A[i][k] * B[k][j] + J[i][j];
		}

	return J;
}

double normaMatriz(Matriz A){

    int n = A.size();

    double soma =0;

    for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                soma += pow(A[i][j],2);

    return sqrt(soma);
}

double normaVetor( Vetor v ){

    double norma = 0;

    for ( int i = 0; i < v.size(); i++)
        norma += pow( v[i], 2);

    return sqrt(norma);
}
Matriz produtoVetor( Vetor v, Vetor u){
    Matriz M;
    int n = v.size();
    M.resize(n);

    alocar(M, n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            M[i][j] = v[i]*u[j];


    return M;
}

Matriz Householder( Matriz A, int h){

    int tam = A.size();
    int a = 0;
    Vetor v, N, _n, n;
    Matriz Q, m;
    int p = tam - h - 1;
    v.resize( p);

    for ( int i = 0; i < p; i++){
        v[i] = A[h+i+1][h];
    }


    double norma_v = normaVetor(v);

    N = v;

    if(v[0] > 0)
        N[0] = N[0] + norma_v;
    else
        N[0] = N[0] - norma_v;

    double norma_N = normaVetor(N);

    _n.resize(p);


    for ( int i = 0; i < p; i++){
        _n[i] = N[i]/norma_N;
    }


    n.resize(tam);
    for( int i = 0; i < tam; i++){
        n[i] = 0;
    }
    for ( int i = h + 1; i < tam; i++){
        n[i] = _n[i - h - 1];
    }

    alocar(Q, tam);

    for(int i = 0; i < tam; i++){
        Q[i][i] = 1;
    }

    m = produtoVetor( n, n);

    for ( int i = 0; i < tam; i++){
        for ( int j = 0; j < tam; j++){
            Q[i][j] = Q[i][j] - 2*m[i][j];
        }
    }

    deletar(m);
    imprimir(Q);
    return Q;
}

Matriz Tridiagonal ( Matriz A ){
    int n = A.size();
    Matriz H, _A, Q;

    alocar(H, n);
    alocar(Q, n);

    for(int i = 0; i < n; i++)
        H[i][i] = 1;

    _A = A;

    for( int h = 0; h < n - 2; h++ ){
        cout << "Matriz de HouseHolder " << h + 1 <<": \n";
        Q = Householder( _A, h);
        H = produto( H, Q);

        _A = produto( Q, _A);
        _A = produto( _A, Q);

    }

    deletar(H); deletar(Q);

    return _A;
}



int main(int argn, const char **argc){

	// Condição para entrada da arquivo por linha de comando
		srand((unsigned) time( NULL));

		Matriz A; Vetor x, y; // vetor inicial

		lerArquivo(A, "eq.txt");

		int n = A.size();

		cout << " Matriz de entrada A: " << endl;
		imprimir(A);

        A = Tridiagonal(A);

        cout << "Matriz Tridiagonal: \n";
        imprimir(A);

        //cout << " autovalores da matriz diagonalizada : " << endl;
        //for( int i = 0; i < A.size(); i++){
        //    cout << "     " << A[i][i] << " " << endl;
        //}

		deletar(A);
		//destruir(x);

		// comando para o ubuntu ler o arquivo
		//system("cat autovalor.txt");

	return EXIT_SUCCESS;
}