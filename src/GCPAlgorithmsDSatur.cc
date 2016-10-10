#include "GCPAlgorithmsDSatur.h"

void GCPAlgorithmsDSatur::criaGrafo(char * nomeArq) {
  this->grafo = new GrafoDSatur(nomeArq);
}

// construtores
GCPAlgorithmsDSatur::GCPAlgorithmsDSatur() : Experiment(), grafo(NULL) /*, k(0)*/ {}

GCPAlgorithmsDSatur::GCPAlgorithmsDSatur(char *nomeArq) : GCPAlgorithmsDSatur() {
  this->criaGrafo(nomeArq);
}

// destrutor
GCPAlgorithmsDSatur::~GCPAlgorithmsDSatur() {
   // std::cout << "deleting graph" << std::endl;
   delete grafo;
}

void GCPAlgorithmsDSatur::imprimeGrafo() const {
   this->grafo->imprimeGrafo();
}

/*uint32_t GCPAlgorithmsDSatur::getK() const {
   return k;
}*/
