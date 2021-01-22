#ifndef grafo
#define grafo

#include <list>

using namespace std;

class Grafo {

    int nos;
    list<int> *adjacentes;
    int *visitado;
    int contemCiclo;
    int limiteEntregas;
    int qtdCentros;
    int qtdPostos;

    public:
        Grafo(int n);
        ~Grafo();
        void setPostosECentros(int qtdPostos, int qtdCentros);
        void adicionaAresta(int no, int aresta);
        void inicializaVisitados();
        void percorreGrafo();
        void buscaProfundidade(int no, int distancia);
        void limiteDistribuicao(int temperatura);
        void printaVisitados();
};

#endif