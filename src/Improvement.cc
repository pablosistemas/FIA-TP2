/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include "Improvement.h"
// FIXME
#include "../include/registers.h"

// constructors
Improvement::Improvement() : Experiment() {}

Improvement::Improvement(char *nome_arq) : Improvement() {
   this->criaGrafo(nome_arq);
}

// destructor
Improvement::~Improvement() {
   delete grafo;
}

// calls criaGrafo method from grafoBI object
void Improvement::criaGrafo(char *nome_arq) {
   this->grafo = new GrafoBI(nome_arq);
}

// randomly initializes the graph and sets its number of colors
void Improvement::randomInit() {

   // generates a new seed
   typedef std::chrono::high_resolution_clock myclock;
   myclock::time_point beginning = myclock::now();
   myclock::duration d = myclock::now() - beginning;
   unsigned seed1 = d.count();

   std::default_random_engine generator(seed1);
   std::uniform_int_distribution<uint32_t> distColors(1,MAX_COLORS);
   std::uniform_int_distribution<uint32_t> distNodes(1,this->grafo->getSize());

   // initializes each node with a random color
   for(auto it = this->grafo->getBegin(); it != this->grafo->getEnd(); it++){
      // performs casting on each node and set a color to it
      std::shared_ptr<NodoBI> temp =
         std::dynamic_pointer_cast<NodoBI>(*it);

      temp.get()->setColor(distColors(generator));
   }

   // sets numColors and numConflicts in the object
   setNumberOfColors();
   setNumberOfConflicts();
}

// calls imprimeGrafo method from grafoBI object
void Improvement::imprimeGrafo() const {
   this->grafo->imprimeGrafo();
}

void Improvement::setNumberOfConflicts() {
   this->grafo->setGraphNumConflicts();
   numConflicts = this->grafo->getGraphNumConflicts();
}

void Improvement::setNumberOfColors() {
   this->grafo->setNumColors();
   numColors = this->grafo->getNumColors();
}


// this function decides between the result found in grafo or
// the results saved in ranking
void Improvement::printResults() {
   // looks for the minimal conflict graph inside ranking
   std::sort(ranking.begin(), ranking.end(), fifncomp());
   if(ranking.size() > 0){
      if(grafo->getGraphNumConflicts() >
            ranking.begin()->get()->getGraphNumConflicts() ||
            (grafo->getGraphNumConflicts() ==
            ranking.begin()->get()->getGraphNumConflicts() &&
            grafo->getNumColors() >
            ranking.begin()->get()->getNumColors())){

         numColors = ranking.begin()->get()->getNumColors();
         numConflicts = ranking.begin()->get()->getGraphNumConflicts();
      }
   }

   std::cout << "Numero de cores utilizadas: " << numColors
      << "\nNumero de iteracoes: " << numIterations
      << "\nNumero de conflitos: " << numConflicts
      <<  std::endl;
}

// Returns true whether n1 has less conflicts than n2. In matching,
// returns the graph that has used less colors
bool fifncomp::operator()(std::shared_ptr<GrafoBI> &n1,std::shared_ptr<GrafoBI> &n2) {
   bool isLess = n1.get()->getGraphNumConflicts() < n2.get()->getGraphNumConflicts();
   if(n1.get()->getGraphNumConflicts() == n2.get()->getGraphNumConflicts())
      return n1.get()->getNumColors() < n2.get()->getNumColors();
   else
      return isLess;
}
