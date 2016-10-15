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

FirstImprovement::FirstImprovement(char *nome_arq, uint32_t numMaxColors, uint32_t numMaxIter) : FirstImprovement() {
   this->criaGrafo(nome_arq);
   NUM_MAX_COLORS = numMaxColors;
   NUM_MAX_ITERATIONS = numMaxIter;
}

// overloads virtual destructor
// Improvement class deletes grafo object
FirstImprovement::~FirstImprovement() {}

bool FirstImprovement::runAlgorithm() {

   std::function<void(GrafoBI *)> destroy = [] (GrafoBI *p) {
      // std::cout << "deleting grafoBI\n";
      delete p;
   };

   // initializes conflicts with random graph number of conflicts
   // randomInit() also updates the number of colors and conflicts of the graph
   // we must apply their values locally
   randomInit();

   while(numConflicts > 0 && numIterations < NUM_MAX_ITERATIONS){
      std::cout << "Numero iteracoes: "<< numIterations << std::endl;
      std::cout << "Numero cores: "<< numColors << std::endl;
      std::cout << "Numero conflitos: "<< numConflicts << std::endl;
      GrafoBI* t = criaVizinhos();
      // int temp;
      // std::cin >> temp;
   // updates whether the new graph is better than current one
   // else, random we reach a minimal local point, it must be updated
   // creates a new random graph whether criaVizinhos returns nullptr
      if(t == nullptr) {
         std::shared_ptr<GrafoBI> temp (new GrafoBI(*grafo), destroy);
         ranking.push_back(temp);
         // creates another grafoBI and restarts again!
         // std::cout << "Antes\n";
         // std::cout << "Numero cores: "<< numColors << std::endl;
         // std::cout << "Numero conflitos: "<< numConflicts << std::endl;
         randomInit();
         // std::cout << "Depois\n";
         // std::cout << "Numero cores: "<< numColors << std::endl;
         // std::cout << "Numero conflitos: "<< numConflicts << std::endl;
         std::cout << "is null\n";
      } else {
         if(t->getGraphNumConflicts() < grafo->getGraphNumConflicts()){
            delete grafo;
            //grafo = new GrafoBI(*t);
            grafo = t;
            std::cout << "is different from nulld\n";
         } else {
            delete t;
            // TODO: saves current graph and reinitializes the search
            std::shared_ptr<GrafoBI> tt (new GrafoBI(*grafo),destroy);
            ranking.push_back(tt);
            std::cout << "is different from null\n";

            randomInit();
         }
      }

      // sets algorithm results and updates stop criteria
      numConflicts = grafo->getGraphNumConflicts();
      numColors = grafo->getNumColors();
      numIterations++;
   }

   std::cout << "Numero cores fim: " << numColors << std::endl;
   return true;
};

GrafoBI* FirstImprovement::criaVizinhos() {
   // creates a null pointer that will be filled with the first graph
   // that improves the current graph state
   GrafoBI* proxGrafo(nullptr);

   auto begin = this->grafo->getBegin();
   auto end   = this->grafo->getEnd();

   uint32_t corOriginal, conflitosOriginal;
   for(auto it = begin; it != end; it++) {

      // saves the current graph state
      corOriginal = it->get()->getColor();
      conflitosOriginal = this->getNumberOfConflicts();

      for(uint32_t i = 1; i <= NUM_MAX_COLORS; i++) {
         // do not selects current graph as a new option
         if(i == corOriginal) continue;

         //std::cout << "conflicts: " << getNumberOfConflicts() << std::endl;
         // creates a total independent copy of current graph
         proxGrafo = new GrafoBI(*(this->grafo));

         // sets color in appropriate nodo in g
         auto itg = proxGrafo->getBegin() + (it-begin);

         itg->get()->setColor(i);
         proxGrafo->setGraphNumConflicts();
         proxGrafo->setNumColors();

         // First improvement algorithm returns in the first improvement of
         // number of conflicts function
         // Alternatively, the best improvement always explores all state space
         // to find the best option to return
         if(proxGrafo->getGraphNumConflicts() < conflitosOriginal)
            return proxGrafo;
         // deletes proxGraph whether it is worse than the current one
         else
            delete proxGrafo;
      }
   }
   // no improvement :(
   return nullptr;
}
