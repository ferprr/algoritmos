#include "headers/Grafo.hpp"
#include <iostream>
#include <sstream>
#include <list>

using namespace std;

Grafo::Grafo(int n) {
    this->nos = n;
    adjacentes = new list<int>[n];
    this->contemCiclo = 0;
}
Grafo::~Grafo(){
    delete this;
}
void Grafo::setPostosECentros(int qtdPostos, int qtdCentros) {
    this->qtdPostos = qtdPostos;
    this->qtdCentros = qtdCentros;
}
void Grafo::adicionaAresta(int no, int aresta) {
    adjacentes[no].push_back(aresta);
}
void Grafo::inicializaVisitados() {
    visitado = new int[qtdPostos];
    for(int i = 0; i < qtdPostos; i++) {
        visitado[i] = 0;
    }
}
void Grafo::limiteDistribuicao(int temperatura){
    this->limiteEntregas = 30/temperatura;
}
void Grafo::percorreGrafo() {
    for (int i = 0; i < qtdCentros; i++) {
		for(auto iterador = adjacentes[i].begin(); iterador != adjacentes[i].end(); iterador++){
			buscaProfundidade(*iterador, 1);
		}
	}
}
void Grafo::buscaProfundidade(int no, int distancia) {

    if(visitado[no-1] == 1) {
        contemCiclo = 1;
    }
    if(distancia > limiteEntregas || visitado[no -1] == -1) {
        return;
    }
    visitado[no-1] = 1;

    for(auto iterador = adjacentes[qtdCentros + no - 1].begin(); iterador != adjacentes[qtdCentros + no - 1].end(); iterador++){
		buscaProfundidade(*iterador, distancia + 1);
	}
    
    visitado[no-1] = -1;
}
void Grafo::printaVisitados() {
    int visitados = 0;

    for (int i = 0; i < qtdPostos; i++){
		if (visitado[i] == 1 || visitado[i] == -1) {
			visitados++;
		}
	}

    cout << visitados << endl;

    if(!visitados) {
        cout << "*" << endl;
    } else {
        for(int i = 0; i < qtdPostos; i++) {
			if(visitado[i] == 1 || visitado[i] == -1) {
				cout << i+1 << " ";
			}
		}
        cout << endl;
    }

    cout << contemCiclo << endl;
}