#include <iostream>
#include <math.h>
#include <iomanip>

#define EULER 2.71828182845904523536

using namespace std;

class Info {
    float isoA, isoB, raiz, fd, Ea;
    int iteracoes, fogueteId;
    char *metodo , *status , *aval;

    public:
        void setIsoA(float iso){
            isoA = iso;
        }

        void setIsoB(float iso){
            isoB = iso;
        }

        void setRaiz(float r){
            raiz = r;

            if(r <= 2)
            {
                aval = new char[7];
                aval = "Seguro";
            }
            else
            {
                aval = new char[9];
                aval = "Inseguro";
            }
        }

        void setFd(float f){
            fd = f;
        }

        void setIteracoes(int i){
            iteracoes = i;
        }

        void setMetodo(char *met){
            metodo = met;
        }

        void setStatus(char *s){
            status = s;
        }

        void setEa(float e){
            Ea = e;
        }

        void setFogueteId(int id){
            fogueteId = id;
        }

        float getIsoA(){
            return isoA;
        }

        float getIsoB(){
            return isoB;
        }

        float getRaiz(){
            return raiz;
        }

        float getFd(){
            return fd;
        }

        int getIteracoes(){
            return iteracoes;
        }

        char* getMetodo(){
            return metodo;
        }

        char* getStatus(){
            return status;
        }

        char* getAval(){
            return aval;
        }

        float getEa(){
            return Ea;
        }

        int getFogueteId(){
            return fogueteId;
        }

};

class Bissecao {

	public:
		Info calcular(float a, float E, int fogueteId , double isoA , double isoB){
			double media = 0, Fa = 0, Fb = 0, Fm = 0;
			//double isoA = 2.0, isoB = 3.0;
			double err;
			int iteracoes = 0;
			Info info;


			char *met;
			met = new char[9];
			met = "Bissecao";
			info.setMetodo(met);

			Fa = resFuncao(a, isoA);
            Fb = resFuncao(a, isoB);

            if(Fa * Fb < 0)
            {
                char *stat;
                stat = new char[7];
                stat = "Valido";
                info.setStatus(stat);

                info.setIsoA(isoA);
                info.setIsoB(isoB);
                info.setFogueteId(fogueteId);

                do {
                    media = ( isoA + isoB ) / 2;

                    //Calculando valores de Fx
                    Fa = resFuncao(a, isoA);
                    Fm = resFuncao(a, media);
                    Fb = resFuncao(a, isoB);

                    err = fabs(isoB - isoA);

                    if ( Fa * Fm < 0 )
                       isoB = media;
                    else
                       isoA = media;


                   iteracoes++;

                } while(err > E && Fm > 0.000001);

                info.setEa(err);
                info.setRaiz(media);
                info.setFd(Fm);
                info.setIteracoes(iteracoes);

            }
			else
            {
                char *stat;
                stat = new char[9];
                stat = "Invalido";
                info.setStatus(stat);

                info.setIsoA(isoA);
                info.setIsoB(isoB);
                info.setFogueteId(fogueteId);

                info.setEa(0);
                info.setRaiz(0);
                info.setFd(0);
                info.setIteracoes(0);
            }


	        return info;
		}

		double resFuncao(float a, double d){
			double res = ((a * d) - ( d * ( log(d) ) ));
			return res;
		}
};

class PosicaoFalsa {

	public:
		Info calcular(float a, float E, int fogueteId , double isoA , double isoB){
			double Pf = 0.0, Fa = 0, Fb = 0, Fpf = 0;
			//double isoA = 2.0, isoB = 3.0;
			double err;
			int iteracoes = 0;
			Info info;


			char *met;
			met = new char[14];
			met = "Posicao Falsa";
			info.setMetodo(met);

			Fa = resFuncao(a, isoA);
            Fb = resFuncao(a, isoB);

            if(Fa * Fb < 0)
            {
                char *stat;
                stat = new char[7];
                stat = "Valido";
                info.setStatus(stat);

                info.setIsoA(isoA);
                info.setIsoB(isoB);
                info.setFogueteId(fogueteId);


                do {

                    //Calculando valores de Fx
                    Fa = resFuncao(a, isoA);
                    Fb = resFuncao(a, isoB);
                    Pf = (((isoA*Fb) - (isoB*Fa))/(Fb - Fa));
                    Fpf = resFuncao(a, Pf);


                    err = fabs(isoB - isoA);

                    if ( Fa * Fpf < 0 )
                       isoB = Pf;
                    else
                       isoA = Pf;

                   iteracoes++;

                } while(err > E && Fpf > 0.000001);

                info.setEa(err);
                info.setRaiz(Pf);
                info.setFd(Fpf);
                info.setIteracoes(iteracoes);

            }
            else
            {
                char *stat;
                stat = new char[9];
                stat = "Invalido";
                info.setStatus(stat);

                info.setIsoA(isoA);
                info.setIsoB(isoB);
                info.setFogueteId(fogueteId);

                info.setEa(0);
                info.setRaiz(0);
                info.setFd(0);
                info.setIteracoes(0);
            }


	        return info;
		}

		double resFuncao(float a, double d){
			double res = ((a * d) - ( d * ( log(d) ) ));
			return res;
		}
};

class NewtonRaphson {

	public:
		Info calcular(float a, float E, int fogueteId , double isoA , double isoB){
			double DFx = 0, Fx = 0, y = 0, NR = 0;
			double x;
			double err;
			int iteracoes = 0;

			x = (isoB + isoA)/2;

			Info info;
			info.setFogueteId(fogueteId);

			char *met;
			met = new char[14];
			met = "Newton Raphson";
			info.setMetodo(met);

			do {

				//Calculando valores de Fx
	        	Fx = resFuncao(a, x);
                DFx = resFuncao2(a, x);
                NR = x - (Fx/DFx);
                y = x;
                x = NR;
	        	err = fabs(x - y);


		       iteracoes++;

	        } while(err > E );

	        info.setEa(err);
	        info.setRaiz(x);
	        info.setIteracoes(iteracoes);

	        return info;
		}

		double resFuncao(float a, double d){
			double res = ((a * d) - ( d * ( log((double) d) ) ));
			return res;
		}

		double resFuncao2 (float a, double d)
		{
		    double res2 = (a - ((log(d)) + 1));
		    return res2;
		}
};


class View {

    public:
        // Metodo para ler o numero de foguetes
        int lerNumFog(){
            int n;

            cout<<"Entre o numero de foguetes (n):\n";
            cin>>n;

            return n;
        }

        // Metodo para ler os valores de "a" para cada foguete
        float* lerA(int n){
            float *vecA;
            vecA = new float[n];

            for(int i = 0; i < n; i++)
            {
                cout<<"Entre o parametro de ajuste (a) do foguete "<<i+1<<":\n";
                cin>>vecA[i];
            }

            return vecA;
        }

        float lerPrecisao(){
            float E;

            cout<<"Entre a precisao (E):\n";
            cin>>E;

            return E;
        }

        //Mostra o quadro que relaciona cada foguete a um "a"
        void quadroRespostaA(float *vecA, int numFog){

            cout<<"\nValores de \"a\" para cada foguete:\n";

            for(int i = 0; i < numFog; i++)
            {
                cout<<"Foguete n. : "<<i+1<<" | a: "<<vecA[i]<<"\n";
            }

        }

        //Mostra o quadro que relaciona cada foguete a um "a"
        void quadroRespostaATabela(float *vecA, int numFog){

            const char separator    = ' ';
            const int numWidth      = 12;

            cout<<"\nValores de \"a\" para cada foguete:\n\n";

            //Cabeçalho da tabela
            cout << left << setw(numWidth) << setfill(separator) << "Foguete n.";
            cout << left << setw(numWidth) << setfill(separator) << "a";
            cout << endl;

            for(int i = 0; i < numFog; i++)
            {
                cout << left << setw(numWidth) << setfill(separator) << i+1;
                cout << left << setw(numWidth) << setfill(separator) << vecA[i];
                cout << endl;
            }

            cout<<"\n";

        }

        void quadroRespostaGeral(Info *infoVec, int tam){

            cout<<"\nQuadro Resposta Geral\n";

            for(int i = 0 ; i < tam ; i++)
            {
                // Mudar para exibir todas as informações do tipo Info, preguiça de fazer isso agora
                cout<<"Foguete n. : "<<infoVec[i].getFogueteId()<<" | Metodo: "<<infoVec[i].getMetodo()<<" | ErroAbs: "<<infoVec[i].getEa()<<
                " | Isolamento Inf. : "<<infoVec[i].getIsoA()<<" | Isolamento Sup. : "<<infoVec[i].getIsoB()<<" | N. Iteracoes: "<<infoVec[i].getIteracoes()<<
                " | Raiz: "<<infoVec[i].getRaiz()<<" | Avaliacao: "<<infoVec[i].getAval()<<"\n";
            }

        }

        void quadroRespostaGeralTabela(Info *infoVec, int tam){

            const char separator    = ' ';
            const int numWidth      = 17;

            cout<<"\nQuadro Resposta Geral\n\n";

            //Cabeçalho da tabela
            cout << left << setw(numWidth) << setfill(separator) << "Foguete n.";
            cout << left << setw(numWidth) << setfill(separator) << "Metodo";
            cout << left << setw(numWidth) << setfill(separator) << "ErroAbs";
            cout << left << setw(numWidth) << setfill(separator) << "Isolamento Inf.";
            cout << left << setw(numWidth) << setfill(separator) << "Isolamento Sup.";
            cout << left << setw(numWidth) << setfill(separator) << "N. Iteracoes";
            cout << left << setw(numWidth) << setfill(separator) << "Raiz";
            cout << left << setw(numWidth) << setfill(separator) << "Avaliacao";
            cout << endl;

            //Conteudo
            for(int i = 0 ; i < tam ; i++)
            {
                cout << left << setw(numWidth) << setfill(separator) << infoVec[i].getFogueteId();
                cout << left << setw(numWidth) << setfill(separator) << infoVec[i].getMetodo();
                cout << left << setw(numWidth) << setfill(separator) << infoVec[i].getEa();
                cout << left << setw(numWidth) << setfill(separator) << infoVec[i].getIsoA();
                cout << left << setw(numWidth) << setfill(separator) << infoVec[i].getIsoB();
                cout << left << setw(numWidth) << setfill(separator) << infoVec[i].getIteracoes();
                cout << left << setw(numWidth) << setfill(separator) << infoVec[i].getRaiz();
                cout << left << setw(numWidth) << setfill(separator) << infoVec[i].getAval();
                cout << endl;
            }

            cout<<"\n";

        }


};


int main(){

	int n;
	float a, E;
	float *vecA;

	// Instancia para a view
	View view;

    // Lendo informações
	n = view.lerNumFog();
	vecA = view.lerA(n);
    E = view.lerPrecisao();

    // Tamanho do vetor de info igual ao numero de foguetes vezes o numero de metodos implementados
    // Alterar n quando implementar mais metodos
    int tam = n * 3;

    Info *infoVec;
    infoVec = new Info[tam];

    int j = 0;
    Bissecao bissecao;
    PosicaoFalsa posicaofalsa;
    NewtonRaphson newtonraphson;

    // Calcula o valor dos metodos para cada foguete
    for(int i = 0 ; i < n ; i++)
    {
        // Prevendo o isolamento
        double isoA = pow(EULER, vecA[i] - 0.5);
        double isoB = pow(EULER, vecA[i] + 0.5);

        // Calculando bissecao do n-esimo foguete
        infoVec[j] = bissecao.calcular(vecA[i], E, i+1, isoA , isoB);
        j++;

        //Calcular posicao falsa do n-esimo foguete
        infoVec[j] = posicaofalsa.calcular(vecA[i], E, i+1 , isoA , isoB);
        j++;

        //Calcular newton-raphson do n-esimo foguete
        infoVec[j] = newtonraphson.calcular(vecA[i], E, i+1 , isoA , isoB);
        j++;
    }


    // Mostrando informações e resultados
    //view.quadroRespostaA(vecA, n);
    //view.quadroRespostaGeral(infoVec, tam);
    view.quadroRespostaATabela(vecA, n);
    view.quadroRespostaGeralTabela(infoVec, tam);

	return 0;
}
