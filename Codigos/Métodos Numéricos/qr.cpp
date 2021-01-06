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

Matriz montar_Qij( Matriz A, int i, int j){
    Matriz Q;
    double teta;
    int n = A.size();

    alocar( Q, n);
    for( int k = 0; k < n; k++)
        Q[k][k] = 1;

    if( A[j][j] == 0)
        teta = M_PI_2;
    else
        teta = atan( A[i][j]/A[j][j]);

    Q[j][j] = cos(teta);
    Q[i][j] = sin(teta);
    Q[i][i] = cos(teta);
    Q[j][i] = -sin(teta);


    return Q;

}

MatrizDupla obter_QR( Matriz A){

    MatrizDupla QR;
    Matriz  Q, _Q, _Qt, R;

    int n = A.size();
    alocar( Q, n);
    for( int i = 0; i < n; i++)
        Q[i][i] = 1;

    for( int j = 0; j < n - 1; j++){
        for( int i = j +1; i < n; i++){
            _Q = montar_Qij( A, i, j);

            _Qt = transposta(_Q);
            R = produto( _Qt, A);
            Q = produto( Q, _Q);
            A = R;
        }
    }

    QR.A = A;
    QR.Q = Q;

    deletar(Q); deletar(_Q); deletar(R);
    return QR;
}

Matriz QR (Matriz A, double tol){
    MatrizDupla Aux;
    Matriz Q, _A, Ast;
    _A = A;
    int n = A.size();
    alocar( Q, n);
    for( int i = 0; i < n; i++)
        Q[i][i] = 1;

    int a = 0;
    while(1 ){
        Aux = obter_QR(_A);

        Q = produto(Q, Aux.Q);

        Ast = produto( Aux.A, Aux.Q);

        double norma = normaMatriz(Ast);

        if( norma < tol)
            break;

        _A = Ast;

        a++;
    }
    cout << " Autovalores da Matriz A: " << endl;
    for( int i = 0; i < n; i++){
        cout << "   " << _A[i][i] << endl;
    }
    cout << " Matriz Q: " << endl;
    imprimir(Q);

    deletar(Q);
    deletar(Ast);

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

        A = QR( A, 0.001);
        cout << "Matriz QR: \n";
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