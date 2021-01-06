#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;


class Utils {

    public:

        static float** inicializarMatriz(int linhas, int colunas){

            float** a = 0;
            a = new float*[linhas];

            for (int i = 0; i < linhas; i++)
            {
                a[i] = new float[colunas];
            }

            return a;
        }

        static float** inicializarMatrizIdentidade(int linhas){

            float** a = 0;
            a = new float*[linhas];
            int colunas = linhas;

            for (int i = 0; i < linhas; i++)
            {
                a[i] = new float[colunas];
            }

            for(int i = 0; i < linhas; i++)
            {
                a[i][i] = 1;
            }

            return a;
        }

        static void copiarMatriz(int n, float **a, float **b){

            for(int linha = 0; linha < n; linha++)
            {
                for(int coluna = 0; coluna<n; coluna++)
                {
                    a[linha][coluna] = b[linha][coluna];
                }
            }

        }

        static void copiarVetor(int n, float *a, float *b){

            for(int i = 0; i<n; i++)
            {
                a[i] = b[i];
            }
        }

};

class MatrizInfo {

    float** matrizA;
    float *b, *dLUNormal, *dLUMod;
    int codErroLU, codErroLDU, n;

    public:

        void setN(int nn){
            n = nn;
        }

        void setMatrizA(int n, float **a){
            matrizA = Utils::inicializarMatriz(n, n);
            Utils::copiarMatriz(n, matrizA, a);
        }

        void setB(int n, float bb[]){
            b = new float[n];
            Utils::copiarVetor(n, b, bb);
        }

        void setDLUNormal(int n, float dLU[]){
            dLUNormal = new float[n];
            dLUNormal = dLU;
        }

        void setDLUMod(int n, float dLU[]){
            dLUMod = new float[n];
            dLUMod = dLU;
        }

        void setCodErroLU(int e){
            codErroLU = e;
        }

        void setCodErroLDU(int e){
            codErroLDU = e;
        }

        int getN(){
            return n;
        }

        float** getMatrizA(){
            return matrizA;
        }

        float* getB(){
            return b;
        }

        float* getDLUNormal(){
            return dLUNormal;
        }

        float* getDLUMod(){
            return dLUMod;
        }

        int getCodErroLU(){
            return codErroLU;
        }

        int getCodErroLDU(){
            return codErroLDU;
        }

};



class View {

    public:

        // Metodo para ler o numero de deslocamentos n
        int lerNumDeslocamentos(){
            int n;

            cout<<"Entre o numero de deslocamentos (n):\n";
            cin>>n;

            return n;
        }

        float** lerMatrizesAF(int n){

            int i, j;

            float** matrizA = Utils::inicializarMatriz(n , n+1);


            for (i=0; i<n; i++)
            {
                //system ("cls");
                system("clear");

                cout<<"Digite os elementos da linha "<< i+1 <<":\n\n";
                float temp;
                int ok = 0;
                j = 0;
                while(j < n || ok == 0)
                {
                    ok = 0;

                    cout<<"a["<< i+1 <<"]["<< j+1 <<"] = ";
                    cin>>temp;

                    if(temp == 0 && j == i)

                    {
                        cout<<"Nao e possivel computar o sistema com zero na diagonal, insira outro valor\n";
                    }
                    else
                    {
                        matrizA[i][j] = temp;
                        j++;
                        ok = 1;
                    }

                }
                cout<<"\nb["<< i+1 <<"] = ";
                cin>>matrizA[i][n];
            }

            return matrizA;
        }

        //Imprime a matriz a ser resolvida
        void mostrarMatriz(MatrizInfo mInfo){

            float **matrizA = mInfo.getMatrizA();
            float *b = mInfo.getB();
            int n = mInfo.getN();

            const char separator = ' ';
            const int numWidthA = 10;
            const int numWidthB = 25;
            const int tituloTam = 7; //metade do tamanho do titulo
            int spcTemp;

            //Alinha os titulos
            spcTemp = numWidthA + (((n-1) * numWidthA + numWidthB)/2) + tituloTam;

            cout<<"\n";
            cout << right << setw(spcTemp) << setfill(separator) << "Matriz Inicial";
            cout << endl;
            cout<<"\n\n";

            spcTemp = numWidthA + (((n-1) * numWidthA)/2);
            cout << right << setw(spcTemp) << setfill(separator) << "A";

            spcTemp = (n * numWidthA) - spcTemp + numWidthB;
            cout << right << setw(spcTemp) << setfill(separator) << "f";

            cout << endl;
            cout<<"\n";

            //Imprime o sistema inicial
            for(int linha = 0; linha < n; linha++)
            {
                //Imprime a linha da matriz A
                for(int coluna = 0; coluna < n; coluna++)
                {
                    cout << right << setw(numWidthA) << setfill(separator) << matrizA[linha][coluna];
                }

                //Imprime a linha do vetor b
                cout << right << setw(numWidthB) << setfill(separator) << b[linha];
                cout << endl;
            }

            cout<<"\n\n";
        }

        //Imprime a tabela de resultados se não houver nenhum erro
        void mostrarTabelaResultados(MatrizInfo mInfo){

            int n = mInfo.getN();
            float *dLU = mInfo.getDLUNormal();
            float *dLDU = mInfo.getDLUMod();

            const char separator = ' ';
            const int numWidthA = 18;
            int spc = ((numWidthA * 3) / 2) + 5;

            cout << right << setw(spc) << setfill(separator) << "Resultados";
            cout << endl;
            cout << "\n";

            cout << left << setw(numWidthA-4) << setfill(separator) << "";
            cout << left << setw(numWidthA) << setfill(separator) << "Fatoracao LU";
            cout << left << setw(numWidthA) << setfill(separator) << "Fatoracao LDU";
            cout << right << setw(numWidthA-6) << setfill(separator) << "Avaliacao";
            cout << endl;

            for(int i = 0; i < n; i++)
            {
                cout <<"d";
                cout << left << setw(numWidthA) << setfill(separator) << i+1;
                cout << left << setw(numWidthA) << setfill(separator) << dLU[i];
                cout << left << setw(numWidthA) << setfill(separator) << dLDU[i];
                if((fabs( (dLU[i] + dLDU[i]) / 2)) > 2)
                {
                    cout << left << setw(numWidthA) << setfill(separator) <<"Inseguro";
                }
                else
                {
                    cout << left << setw(numWidthA) << setfill(separator) <<"Seguro";
                }
                cout << endl;

            }

            cout<<"\n";
        }

        //Imprime a tabela de resultados quando ha erro em algum metodo
        void mostrarTabelaResultadosErro(MatrizInfo mInfo){

            if(mInfo.getCodErroLDU() != 0 && mInfo.getCodErroLU() != 0)
            {
                cout<<"Os resultados nao poderam ser calculados, pois os sistemas informados \n precisam de operacoes que nao sao possiveis serem feitas.\n\n";
            }
            else
            {
                int n = mInfo.getN();
                float *d = new float[n];
                int met = 0;

                if(mInfo.getCodErroLU() != 0)
                {
                    met = 2;
                    cout<<"Os resultados do metodo de fatoracao LU nao poderam ser calculados, pois os sistemas informados precisam de \n operacoes que nao sao possiveis serem feitas.\n\n";
                    d = mInfo.getDLUMod();
                }
                else
                {
                    met = 1;
                    cout<<"Os resultados do metodo de fatoracao LDU nao poderam ser calculados, pois os sistemas informados precisam de \n operacoes que nao sao possiveis serem feitas.\n\n";
                    d = mInfo.getDLUNormal();
                }


                const char separator = ' ';
                const int numWidthA = 18;
                int spc = ((numWidthA * 3) / 2) + 5;

                cout << right << setw(spc) << setfill(separator) << "Resultados";
                cout << endl;
                cout << "\n";

                cout << left << setw(numWidthA-4) << setfill(separator) << "";
                if(met == 1)
                {
                    cout << left << setw(numWidthA) << setfill(separator) << "Fatoracao LU";
                }
                else if(met == 2)
                {
                    cout << left << setw(numWidthA) << setfill(separator) << "Fatoracao LDU";
                }

                cout << right << setw(numWidthA-6) << setfill(separator) << "Avaliacao";
                cout << endl;

                for(int i = 0; i < n; i++)
                {
                    cout <<"d";
                    cout << left << setw(numWidthA) << setfill(separator) << i+1;
                    cout << left << setw(numWidthA) << setfill(separator) << d[i];
                    //cout << left << setw(numWidthA) << setfill(separator) << dLDU[i];
                    if((fabs(d[i])) > 2)
                    {
                        cout << left << setw(numWidthA) << setfill(separator) <<"Inseguro";
                    }
                    else
                    {
                        cout << left << setw(numWidthA) << setfill(separator) <<"Seguro";
                    }
                    cout << endl;

                }

                cout<<"\n";

            }
        }

        //Monta todos os resultados na tela, chamando os metodos responsaveis por cada parte
        void mostrarResultados(MatrizInfo mInfo){

            //Limpar tela
            //system("cls");
            system("clear");

            mostrarMatriz(mInfo);

            if(mInfo.getCodErroLU() == 0 && mInfo.getCodErroLDU() == 0)
            {
                mostrarTabelaResultados(mInfo);
            }
            else
            {
                mostrarTabelaResultadosErro(mInfo);
            }

            //testarResultados(mInfo.getN(), mInfo.getMatrizA(), mInfo.getDLUMod());
        }

        void testarResultados(int n, float **vetorInicial, float x[]){

            int i, j;

            float temp;

            for(i = 0; i < n; i++)
            {
                j = 0;
                temp = (vetorInicial[i][j]*x[j]) + (vetorInicial[i][j+1]*x[j+1]) + (vetorInicial[i][j+2]*x[j+2]);
                cout<<"Resultado linha "<<i+1<<" = "<<temp<<"\n";
            }


        }

};



class LU {

    public:

        float* substituicaoDiagonal(int n, float ** a, float b[]){

            float *y;
            y = new float[n];

            for(int linha = 0; linha < n; linha++)
            {
                y[linha] = b[linha] / a[linha][linha];
            }

            return y;
        }

        float* substituicaoSucessiva(int n, float ** a, float b[]){

            float *y;
            y = new float[n];
            float soma;

            //Resolve o sistema L Y = B, obtendo Y
            for (int linha=0; linha<n; linha++)
            {
                soma=0.0;
                for (int coluna=0; coluna<linha; coluna++)
                {
                    soma = soma + y[coluna]*a[linha][coluna];
                }
                y[linha] = (b[linha] - soma)/a[linha][linha];

            }

            return y;
        }

        float* substituicaoRetroativa(int n, float **a, float y[]){

            float *x;
            x = new float[n];
            float soma;

            //Resolve o sistema U X = Y, obtendo X
            if (a[n-1][n-1] != 0.0)
            {
                x[n-1] = y[n-1] / a[n-1][n-1];
            }
            else
            {
                //mInfo.setCodErro(2);
                return NULL;
            } //erro de divisão por zero

            for (int i=n-2; i>-1; i--)
            {
                soma = 0.0;
                for (int j=i+1; j<n; j++)
                {soma = soma + a[i][j]*x[j];}

                if (a[i][i] != 0)
                {
                    x[i] = (y[i] - soma)/a[i][i];
                }
                else
                {
                    //mInfo.setCodErro(2);
                    return NULL;
                } //erro de divisão por zero
             }

            return x;
        }

        void pivoteamentoParcial(int n, float **a, float b[], int k){

            float pivo, aux;
            int i, j, posl;

            pivo=fabs(a[k][k]); //pivo inicial
            posl=k; //posicao da linha do pivo
            for (i=k+1; i<n; i++)
            {
                if (fabs(a[i][k])>pivo)
                {
                    pivo=fabs(a[i][k]); //passa a ser o novo pivo
                    posl=i; //guarda a posicao da linha do maior pivo
                }
            }
            if (posl!=k) //caso o pivo nao esteja na linha k, troca linha k pela linha posl
            {
                for (j=0; j<n; j++)//permuta as linhas da matriz a[][]
                {
                    aux=a[k][j];
                    a[k][j]=a[posl][j];
                    a[posl][j]=aux;
                }
                aux=b[k]; //tambem permuta as linhas da matriz b[]
                b[k]=b[posl];
                b[posl]=aux;
            }
        }

        int triangularizacao(int n, float **a, float **matrizL, int k){

            int i, j;
            float m;

            //Triangularizacao da matriz a[][], para a obtenção da matriz LU
            if (a[k][k] != 0.0) //Evita erros de divisao por zero, caso o pivo seja zero
            {
                for (i=k+1; i<n; i++)
                {
                    m = a[i][k]/a[k][k]; //calcula o multiplicador
                    //guarda os multiplicadores nas respectivas posicoes da matrizL
                    matrizL[i][k] = m;
                    a[i][k] = 0;

                    for (j=k+1; j<n; j++) //comeca do elemento apos o valor a ser zerado
                    {
                        a[i][j] = a[i][j] - (m*a[k][j]);
                    }
                }
            }
            else
            {
                //erro = 1; break;
                return 1;
            } //Houve erro de divisão por zero

            return 0;
        }

        int gaussPivotParcLU(int n, float **a, float **matrizL, float b[]){

            int k, erro;
            erro = 0;


            k = 0;
            while(k<(n-1) && erro == 0)
            {
                //pivoteamentoParcial(n, a, b, k);

                //Triangularizacao da matriz a[][], para a obtenção da matriz LU
                erro = triangularizacao(n, a, matrizL, k);

                k++;
            }

            if (erro == 1) //Houve erro de divisão por zero. Retorna 2, indicando esse erro.
            {
                //mInfo.setCodErro(2);
                return 1;
            }

            return 0;
        }


        MatrizInfo fatoracaoLU(int n, float **a, float b[]){

            int k, i, j, posl, erro;
            float m, soma, aux, pivo, *y, *x;
            y = new float[n];
            x = new float[n];
            MatrizInfo mInfo;

            mInfo.setMatrizA(n, a);
            mInfo.setB(n, b);
            mInfo.setN(n);

            float **matrizL = Utils::inicializarMatrizIdentidade(n);

            if (n<2)
            {
                mInfo.setCodErroLU(1);
                return mInfo;
            } //a ordem do sistema tem que ser maior ou igual a 2

            for (i=0; i<n; i++) //inicializa as variaveis x (por precaução)
            {x[i]=0;}

            erro=0; //A variavel erro se tornara 1 caso haja erros de divisao por zero

            erro = gaussPivotParcLU(n, a, matrizL, b);

            if (erro == 1) //Houve erro de divisão por zero. Retorna 2, indicando esse erro.
            {
                mInfo.setCodErroLU(2);
                return mInfo;
            }

            //Resolve o sistema L Y = B, obtendo Y
            y = substituicaoSucessiva(n, matrizL, b);

            //Resolve o sistema U X = Y, obtendo X, utilizando o metodo da resolucao de um sistema triangular superior
            x = substituicaoRetroativa(n, a, y);

            if(x == NULL)
            {
                mInfo.setCodErroLU(2);
            }
            else
            {
                mInfo.setDLUNormal(n, x);
                mInfo.setCodErroLU(0);
            }

            return mInfo;
        }

        float** multiplicacaoMatrizes(int n, float **a, float **b){

            float **matrizM = Utils::inicializarMatriz(n, n);

            int linha;
            int coluna;
            int i;
            int somaprod;

            int M1L=3, M1C=3, M2L=3, M2C=3;

            for(linha=0; linha<n; linha++)
            {
                for(coluna=0; coluna<n; coluna++){
                    somaprod=0;
                    for(i=0; i<n; i++){ somaprod+=a[linha][i]*b[i][coluna]; }
                    matrizM[linha][coluna]=somaprod;
                }
            }

            return matrizM;
        }


        MatrizInfo fatoracaoLDU(int n, float **a, float b[], MatrizInfo mInfo){

            int k, i, j, posl, erro;
            float m, soma, aux, pivo, *y, *x, *z;    //declarei o vetor z
            float **matrizU = Utils::inicializarMatriz(n, n);    //veririfcar se esta correta a forma de declarar matriz
            y = new float[n];
            x = new float[n];
            z = new float[n];


            float **matrizL = Utils::inicializarMatrizIdentidade(n);

            if (n<2)
            {
                mInfo.setCodErroLDU(1);
                return mInfo;
            } //a ordem do sistema tem que ser maior ou igual a 2

            for (i=0; i<n; i++) //inicializa as variaveis x (por precaução)
            {x[i]=0;}

            erro=0; //A variavel erro se tornara 1 caso haja erros de divisao por zero

            erro = gaussPivotParcLU(n, a, matrizL, b);

            if (erro == 1) //Houve erro de divisão por zero. Retorna 2, indicando esse erro.
            {
                mInfo.setCodErroLDU(2);
                return mInfo;
            }

            Utils::copiarMatriz(n, matrizU, a);    //Tentando copiar a matriz a em u(verificar se esta correto


            for(int t = 0; t < n; t++)
            {
                m = matrizU[t][t];

                for(int c = 0; c < n; c++)
                {
                    if(matrizU[t][c]!=0)
                    {
                        matrizU[t][c] = matrizU[t][c]/m;
                    }

                    if(t != c)
                    {
                        a[t][c] = 0;                        //obtendo matrizD
                    }
                }
            }


            z = substituicaoSucessiva(n, matrizL, b);   // L z = b


            y = substituicaoDiagonal(n, a, z);        // D y = z


            x = substituicaoRetroativa(n, matrizU, y);  // U x = y


            if(x == NULL)
            {
                mInfo.setCodErroLDU(2);
            }
            else
            {
                mInfo.setDLUMod(n, x);
                mInfo.setCodErroLDU(0);
            }

            return mInfo;
        }


        MatrizInfo executarMetodos(int n , float **a, float b[]){

            MatrizInfo mInfo;

            mInfo = fatoracaoLU(n , a, b);

            Utils::copiarMatriz(n, a, mInfo.getMatrizA());

            mInfo = fatoracaoLDU(n, a, b, mInfo);

            return mInfo;
        }
};


int main() {

    int n;

    // Instancia para a view
	View view;

    // Ler os dados de entrada
    n = view.lerNumDeslocamentos();

    float **a = Utils::inicializarMatriz(n , n);
    float x[n], b[n]; // temp[n][n+1];
    float** temp;
    temp = view.lerMatrizesAF(n);

    // Quebrando a matriz temp em duas, A e B
    for(int linha = 0; linha < n; linha++)
    {
        for(int coluna = 0; coluna < n; coluna++)
        {
            a[linha][coluna] = temp[linha][coluna];
            //cout<<"a["<< linha+1 <<"]["<< coluna+1 <<"] = "<<a[linha][coluna]<<"\n";
        }
    }

    for(int linha = 0; linha < n; linha++)
    {
        b[linha] = temp[linha][n];
        //cout<<"\nb["<< linha+1 <<"] = "<<b[linha]<<"\n";
    }


    //Calcular o metodo
    LU metodoLU;
    MatrizInfo mInfo;
    mInfo = metodoLU.executarMetodos(n , a, b);


    //Mostrar os resultados
    view.mostrarResultados(mInfo);

}
