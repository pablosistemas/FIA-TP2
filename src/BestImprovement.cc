/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include <iostream>
#include <random>
#include "BestImprovement.h"
// FIXME
#include "../include/registers.h"

//BestImprovement::BestImprovement() : numConflicts(0), numIterations(0) {}
BestImprovement::BestImprovement() : Improvement() {}

BestImprovement::BestImprovement(char *nome_arq) : BestImprovement() {
   this->criaGrafo(nome_arq);
}

// overloads virtual destructor from Improvement class
BestImprovement::~BestImprovement() {}

bool BestImprovement::runAlgorithm() {

   std::function<void(GrafoBI *)> destroy = [] (GrafoBI *p) {
      //std::cout << "deleting grafoBI\n";
      delete p;
   };

   // initializes conflicts with random graph number of conflicts
   randomInit();

   while(numConflicts > 0 && numIterations < MAX_ITER){
      std::cout << "Numero iteracoes: "<< numIterations << std::endl;
      std::cout << "Numero cores: "<< numColors << std::endl;
      std::cout << "Numero conflitos: "<< numConflicts << std::endl;
      GrafoBI* t = criaVizinhos();

      if(t == nullptr) {
         std::shared_ptr<GrafoBI> temp (new GrafoBI(*grafo), destroy);
         ranking.push_back(temp);
         randomInit();
      }
      // if the new graph is better than current one, updates
      // else, random we reach a minimal local point, it must be updated
      else if(t->getGraphNumConflicts() < grafo->getGraphNumConflicts()){
         delete grafo;
         grafo = t;
      } else {
         delete t;
         // TODO: saves current graph
         std::shared_ptr<GrafoBI> tt (new GrafoBI(*grafo),destroy);

         ranking.push_back(tt);
         randomInit();
      }

      // updates stop criteria
      numConflicts = grafo->getGraphNumConflicts();
      numColors = grafo->getNumColors();
      numIterations++;
   }
   std::cout << "Numero cores fim: " << numColors << std::endl;
   return true;
};

GrafoBI* BestImprovement::criaVizinhos() {
   // creates a null pointer that will be filled with the first graph
   // that improves the current graph state
   GrafoBI* proxGrafo(nullptr);

   auto begin = this->grafo->getBegin();
   auto end   = this->grafo->getEnd();

   // Current graph state
   // std::cout << "grafo original:\n";
   // this->imprimeGrafo();

   GrafoBI* g(nullptr);

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
         g = new GrafoBI(*(this->grafo));

         // sets color in appropriate nodo in g
         auto itg = g->getBegin() + (it-begin);
         itg->get()->setColor(i);

        // configures the nummber of conflicts for each nodo
         g->setGraphNumConflicts();
         g->setNumColors();
         //std::cout << "grafo modificado:\n";
         //g.get()->imprimeGrafo();

         // int temp;
         // std::cin >> temp;

         if(g->getGraphNumConflicts() < conflitosOriginal){
            // std::cout << "improvement: " << g->getGraphNumConflicts() << "\n";
            if(proxGrafo != nullptr) {
               // updates proxGrafo if the newest is better
               if(g->getGraphNumConflicts()
                        < proxGrafo->getGraphNumConflicts()) {
                  delete proxGrafo;
                  proxGrafo = g;
               }
               // else do not replace a graph for a worse one
            } else
               proxGrafo = g;
            // returns imediately whether numConflicts is 0
            if(g->getGraphNumConflicts() == 0)
               return proxGrafo;
         // discards new graph if there is no improvement
         } else
            delete g;
      }
      // sets graph's original state
      //it->get()->setColor(corOriginal);
      //this->numConflicts = conflitosOriginal;
   }
   return proxGrafo;
}
