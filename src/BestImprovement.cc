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
BestImprovement::BestImprovement() : Experiment() {}

BestImprovement::BestImprovement(char *nome_arq) : BestImprovement() {
   this->criaGrafo(nome_arq);
}

// overloads virtual destructor from Improvement class
BestImprovement::~BestImprovement() { 
   delete grafo;
}

void BestImprovement::criaGrafo(char *nome_arq) {
   this->grafo = new GrafoBI(nome_arq);
}

bool BestImprovement::runAlgorithm() {

   std::function<void(GrafoBI *)> destroy = [] (GrafoBI *p) {
      std::cout << "deleting grafoBI\n";
      delete p;
   };

   // initializes conflicts with random graph number of conflicts
   randomInit();
   numConflicts = grafo->getGraphNumConflicts();

   //grafo->imprimeGrafo();
   this->setNumberOfConflicts();
   // int ttt;
   // std::cin >> ttt;
   while(numConflicts > 0 && numIterations < MAX_ITER){
      // std::cout << "iteracao: " << numIterations << std::endl;
      // Presuming that criaViznhos always will return a valid pointer?
      GrafoBI* t = criaVizinhos();
      // t.get()->imprimeGrafo();

      // if the new graph is better than current one, updates
      // else, random we reach a minimal local point, it must be updated
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
      numConflicts = grafo->getGraphNumConflicts();
   }

   //k = grafo->numColors();
   numColors = grafo->numColors();

   return true;
};

GrafoBI* BestImprovement::criaVizinhos() {

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
         g->setGraphNumConflicts();

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
      it->get()->setColor(corOriginal);
      this->numConflicts = conflitosOriginal;
   }
   return proxGrafo;
}

void BestImprovement::randomInit() {

   std::default_random_engine generator;
   std::uniform_int_distribution<uint32_t> distColors(1,MAX_COLORS);
   std::uniform_int_distribution<uint32_t> distNodes(1,this->grafo->getSize());

   // initializes each node with a random color
   // std::cout << "Initializing randomly: " << grafo->getEnd()-grafo->getBegin() << std::endl;
   for(auto it = this->grafo->getBegin(); it != this->grafo->getEnd(); it++){
      // performs casting on each node and set a color to it
      std::shared_ptr<NodoBI> temp =
         std::dynamic_pointer_cast<NodoBI>(*it);
      temp.get()->setColor(distColors(generator));
   }
}

void BestImprovement::imprimeGrafo() const {
   this->grafo->imprimeGrafo();
}

void BestImprovement::setNumberOfConflicts() {
   this->grafo->setGraphNumConflicts();
   numConflicts = this->grafo->getGraphNumConflicts();
}

/*uint32_t BestImprovement::getNumberOfConflicts() const {
   return numConflicts;
}

uint32_t BestImprovement::getNumColors() const {
   return k;
}

uint32_t BestImprovement::getNumIterations() const {
   return numIterations;
}*/
