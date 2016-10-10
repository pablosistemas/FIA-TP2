/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include <iostream>
#include <random>
#include <algorithm>
#include "FirstImprovement.h"
// FIXME
#include "../include/registers.h"

FirstImprovement::FirstImprovement() {}

FirstImprovement::FirstImprovement(char *nome_arq) : FirstImprovement() {
   this->criaGrafo(nome_arq);
}

// overloads virtual destructor
FirstImprovement::~FirstImprovement() {
   delete grafo;   
}

bool FirstImprovement::runAlgorithm() {

   std::function<void(GrafoBI *)> destroy = [] (GrafoBI *p) {
      // std::cout << "deleting grafoBI\n";
      delete p;
   };

   // initializes conflicts with random graph number of conflicts
   randomInit();
   numConflicts = grafo->getGraphNumConflicts();

   this->setNumberOfConflicts();

   while(numConflicts > 0 && numIterations < MAX_ITER){
      std::cout << "Numero iteracoes: "<< numIterations << std::endl;
      GrafoBI* t = criaVizinhos();

   // updates whether the new graph is better than current one
   // else, random we reach a minimal local point, it must be updated
   // creates a new random graph whether criaVizinhos returns nullptr
      if(t == nullptr) {
         std::shared_ptr<GrafoBI> temp (grafo, destroy);
         ranking.push_back(temp);
         std::cout << ranking.size() << std::endl;
         grafo = new GrafoBI(); 
         randomInit();
         std::cout << "is null\n";
      } else {
         std::cout << "is different from null\n";
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
      }
      // updates stop criteria
      numIterations++;
      numConflicts = grafo->getGraphNumConflicts();
      std::cout << "numColors: " << grafo->getNumColors() << "\n";
   }

   // sets algorithm results
   //k = grafo->numColors();
   numColors = grafo->getNumColors();
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
         proxGrafo->setNumColors();

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

void FirstImprovement::printR() {
   // looks for the minimal conflict graph inside ranking
   std::sort(ranking.begin(), ranking.end(), fifncomp());
   if(grafo->getGraphNumConflicts() > 
         ranking.begin()->get()->getGraphNumConflicts() || 
         (grafo->getGraphNumConflicts() == 
         ranking.begin()->get()->getGraphNumConflicts() && 
         grafo->getNumColors() > 
         ranking.begin()->get()->getNumColors())){

      delete grafo;
      grafo = ranking.begin()->get();

   }
   std::cout << "Numero de cores utilizadas: " << numColors 
      << "\nNumero de iteracoes: " << numIterations
      << "\nNumero de conflitos: " << numConflicts
      <<  std::endl;
}

// Returns true whether n1 has less conflicts than n2. In matching,
// returns the graph that has used less colors
bool fifncomp::operator()(std::shared_ptr<GrafoBI> &n1,std::shared_ptr<GrafoBI> &n2) {
   bool isLess = n1.get()->getGraphNumConflicts();
   if(n1.get()->getGraphNumConflicts() == n2.get()->getGraphNumConflicts())
      return n1.get()->getNumColors() < n2.get()->getNumColors();
   else
      return isLess;
}
