/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include <iostream>
#include <random>
#include "FirstImprovement.h"
// FIXME
#include "../include/registers.h"

FirstImprovement::FirstImprovement() {}

FirstImprovement::FirstImprovement(char *nome_arq) : FirstImprovement() {
   this->criaGrafo(nome_arq);
}

FirstImprovement::~FirstImprovement() {
   delete grafo;   
}

bool FirstImprovement::runAlgorithm() {

   std::function<void(GrafoBI *)> destroy = [] (GrafoBI *p) {
      // std::cout << "deleting grafoBI\n";
      delete p;
   };

   randomInit();

   this->setNumberOfConflicts();

   while(grafo->getGraphNumConflicts() > 0 && numIterations < MAX_ITER){
      GrafoBI* t = criaVizinhos();

      // updates whether the new graph is better than current one
      // else, random we reach a minimal local point, it must be updated
      if(t == nullptr) continue;

      if(t->getGraphNumConflicts() < grafo->getGraphNumConflicts()){
         delete grafo;
         grafo = t;
      } else {

         delete t;
         // TODO: saves current graph
         std::shared_ptr<GrafoBI> tt (new GrafoBI(*grafo),destroy);

         ranking.push_back(tt);
         randomInit();
      }

      numIterations++;
   }
   // sets algorithm results
   k = grafo->numColors();
   numConflicts = grafo->getGraphNumConflicts();

   return true;
};

GrafoBI* FirstImprovement::criaVizinhos() {

   GrafoBI* proxGrafo(nullptr);

   auto begin = this->grafo->getBegin();
   auto end   = this->grafo->getEnd();

   uint32_t corOriginal, conflitosOriginal;
   for(auto it = begin; it != end; it++) {

      // saves the current graph state
      corOriginal = it->get()->getColor();
      conflitosOriginal = this->getNumberOfConflicts();

      for(uint32_t i = 1; i <= MAX_COLORS; i++) {
         // do not selects current graph as a new option
         if(i == corOriginal) continue;

         //std::cout << "conflicts: " << getNumberOfConflicts() << std::endl;
         // creates a total independent copy of current graph
         proxGrafo = new GrafoBI(*(this->grafo));

         // sets color in appropriate nodo in g
         auto itg = proxGrafo->getBegin() + (it-begin);

         itg->get()->setColor(i);
         proxGrafo->setGraphNumConflicts();

         if(proxGrafo->getGraphNumConflicts() < conflitosOriginal)
            return proxGrafo;
      }
   }
   // no improvement :(
   return nullptr;
}
