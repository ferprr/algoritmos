#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include "headers/Grafo.hpp"

using namespace std;

int main() {

    int qtdCentros, qtdPostos, perdaTemperatura;
    cin >> qtdCentros >> qtdPostos >> perdaTemperatura;

    Grafo entrega(qtdCentros + qtdPostos);

    string entrada;
    int no;

    for (int i = 0; i <= qtdPostos + qtdCentros; i++) {
        getline(cin, entrada);
        istringstream iss(entrada);

        while(iss >> no && no != 0) {
            entrega.adicionaAresta(i-1, no);
        }
    }
    
    entrega.setPostosECentros(qtdPostos, qtdCentros);
    entrega.limiteDistribuicao(perdaTemperatura);
    entrega.inicializaVisitados();
    entrega.percorreGrafo();
    entrega.printaVisitados();
    entrega.~Grafo();

}