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

BestImprovement::BestImprovement() : numConflicts(0) {}

BestImprovement::BestImprovement(char *nome_arq) : BestImprovement() {
   this->criaGrafo(nome_arq);
}

BestImprovement::~BestImprovement() {}

void BestImprovement::criaGrafo(char *nome_arq) {
   this->grafo = new GrafoBI(nome_arq);
}

bool BestImprovement::runAlgorithm() {
   
   uint32_t iter = 0;
    
   while(this->numConflicts > 0 || iter < MAX_ITER){
      std::shared_ptr<GrafoBI> t = criaVizinhos();
      
      // if the new graph is better than current, updates
      // else, random we reach a minimal local point, it must be updated
      if(t.get()->getGraphNumConflicts() < grafo->getGraphNumConflicts()){
         delete grafo;
         grafo = t.get();
      } else {
         // TODO: saves current graph
         randomInit();
      }
   }

   return true;
};

std::shared_ptr<GrafoBI> BestImprovement::criaVizinhos() {
   
   std::function<void(GrafoBI *)> destroy = [] (GrafoBI *p) {
      std::cout << "deleting grafoBI\n";
      delete p; 
   };
   
   std::shared_ptr<GrafoBI> proxGrafo(NULL);

   std::vector<std::shared_ptr<NodoBI>>::iterator it;
   std::vector<std::shared_ptr<NodoBI>>::iterator end = this->grafo->getEnd();
   std::vector<std::shared_ptr<NodoBI>>::iterator begin = this->grafo->getBegin();
   
   // Current graph state
   uint32_t corOriginal, conflitosOriginal;
   for(it = begin; it != end; it++) {

      corOriginal = it->get()->getColor();          
      conflitosOriginal = this->getNumberOfConflicts();

      for(uint32_t i = 1; i <= MAX_COLORS; i++) { 
         // do not selects current graph as a new option
         if(i != corOriginal) continue;

         // TODO: implementar construtor de copia
         it->get()->setColor(i);
         this->setNumberOfConflicts();

         std::shared_ptr<GrafoBI> g (new GrafoBI(*(this->grafo)), destroy);      
         if(g.get()->getGraphNumConflicts() < conflitosOriginal){
            if(proxGrafo.get() != NULL) {
               if(g.get()->getGraphNumConflicts()
                        < proxGrafo.get()->getGraphNumConflicts())
                     proxGrafo = g;
               // else do not replace a graph for a worse one
            } else 
               proxGrafo = g;
         }
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
   for( auto it = this->grafo->getBegin(); it != this->grafo->getEnd(); it++){
      // performs casting on each node and set a color to it
      std::shared_ptr<Nodo> temp = 
         std::dynamic_pointer_cast<Nodo>(*it);
      temp.get()->setColor(distColors(generator));         
   }
}



void BestImprovement::imprimeGrafo() const {
   this->grafo->imprimeGrafo();
}

uint32_t BestImprovement::getK() const {
   return k;
}

void BestImprovement::setNumberOfConflicts() {
   this->grafo->setGraphNumConflicts();
   numConflicts = this->grafo->getGraphNumConflicts();
}

uint32_t BestImprovement::getNumberOfConflicts() const {
   return numConflicts;
}
