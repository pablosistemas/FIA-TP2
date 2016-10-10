#include "GCPAlgorithms.h"

void GCPAlgorithms::criaGrafo(char * nomeArq) {
  this->grafo = new Grafo(nomeArq);
}

// construtores
GCPAlgorithms::GCPAlgorithms() : Experiment(), grafo(nullptr), minimal(nullptr)/*, k(0)*/ {}

GCPAlgorithms::GCPAlgorithms(char *nomeArq) : GCPAlgorithms() {
   this->criaGrafo(nomeArq);
}

// destrutor
GCPAlgorithms::~GCPAlgorithms() {
   // std::cout << "deleting graph" << std::endl;
   delete grafo;
   delete minimal;
}

void GCPAlgorithms::imprimeGrafo() const {
  this->grafo->imprimeGrafo();
}

/*uint32_t GCPAlgorithms::getK() const {
   return k;
}*/
