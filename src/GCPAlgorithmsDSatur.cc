#include "GCPAlgorithmsDSatur.h"

void GCPAlgorithmsDSatur::criaGrafo(char * nomeArq) {
  this->grafo = new GrafoDSatur(nomeArq);
}

// construtores
GCPAlgorithmsDSatur::GCPAlgorithmsDSatur() : Experiment(), grafo(NULL) {}

GCPAlgorithmsDSatur::GCPAlgorithmsDSatur(char *nomeArq) : GCPAlgorithmsDSatur() {
  this->criaGrafo(nomeArq);
}

// destructor
GCPAlgorithmsDSatur::~GCPAlgorithmsDSatur() {
   delete grafo;
}

void GCPAlgorithmsDSatur::imprimeGrafo() const {
   this->grafo->imprimeGrafo();
}
