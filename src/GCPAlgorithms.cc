#include "GCPAlgorithms.h"

void GCPAlgorithms::criaGrafo(char * nomeArq) {
  this->grafo = new Grafo(nomeArq);
}

// construtores
GCPAlgorithms::GCPAlgorithms() : grafo(NULL) {}

GCPAlgorithms::GCPAlgorithms(char *nomeArq){
  this->criaGrafo(nomeArq);
}

// destrutor
GCPAlgorithms::~GCPAlgorithms() {
   // std::cout << "deleting graph" << std::endl;
   delete grafo;
}

void GCPAlgorithms::imprimeGrafo() const {
  this->grafo->imprimeGrafo();
}
