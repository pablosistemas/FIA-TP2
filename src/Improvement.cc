/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include <iostream>
#include <random>
#include "Improvement.h"
// FIXME
#include "../include/registers.h"

// Improvement::Improvement() : numConflicts(0), numIterations(0) {}
Improvement::Improvement() : Experiment() {}

Improvement::Improvement(char *nome_arq) : Improvement() {
   this->criaGrafo(nome_arq);
}

Improvement::~Improvement() {}

void Improvement::criaGrafo(char *nome_arq) {
   this->grafo = new GrafoBI(nome_arq);
}

// randomly initializes the graph and sets its number of colors
void Improvement::randomInit() {

   std::default_random_engine generator;
   std::uniform_int_distribution<uint32_t> distColors(1,MAX_COLORS);
   std::uniform_int_distribution<uint32_t> distNodes(1,this->grafo->getSize());

   // initializes each node with a random color
   for(auto it = this->grafo->getBegin(); it != this->grafo->getEnd(); it++){
      // performs casting on each node and set a color to it
      std::shared_ptr<NodoBI> temp =
         std::dynamic_pointer_cast<NodoBI>(*it);
      temp.get()->setColor(distColors(generator));
   }
   // sets numColors
   grafo->setNumColors();
}

void Improvement::imprimeGrafo() const {
   this->grafo->imprimeGrafo();
}

/*uint32_t Improvement::getNumColors() const {
   return k;
}*/

void Improvement::setNumberOfConflicts() {
   this->grafo->setGraphNumConflicts();
   numConflicts = this->grafo->getGraphNumConflicts();
}

/*uint32_t Improvement::getNumberOfConflicts() const {
   return numConflicts;
}*/

/*uint32_t Improvement::getNumIterations() const {
   return numIterations;
}*/
