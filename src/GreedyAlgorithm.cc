#include "GreedyAlgorithm.h"
#include <cstddef>
#include <vector>
#include "cnodos.h"

GreedyAlgorithm::GreedyAlgorithm(char *nomeArq){
  this->criaGrafo(nomeArq);
}

GreedyAlgorithm::~GreedyAlgorithm() {
   // std::cout << "Destructing greedy" << std::endl;
}

// updates numColors used and numConflicts
void GreedyAlgorithm::updateGraphColorsAndConflicts() {
   grafo->setGraphNumConflicts();
   grafo->setNumColors();
}

void GreedyAlgorithm::updateLocalColorsAndConflicts() {
   numConflicts = grafo->getGraphNumConflicts();
   numColors = grafo->getNumColors();
}



bool GreedyAlgorithm::runAlgorithm(){
   if(this->grafo == nullptr){
      throw "GRAFO nao alocado\n";
   }

   std::vector<std::shared_ptr<Nodo>>::iterator it;

   // inicializa a cor do primeiro vertice
   std::shared_ptr<Nodo> temp = std::dynamic_pointer_cast<Nodo>(*(grafo->getBegin()));
   temp.get()->setColor(1);
   // std::cout << "cor: " << (grafo->getBegin()+1)->getColor() << std::endl;
   // uint32_t i = 2;

   for(it = (grafo->getBegin()+1); it != grafo->getEnd(); it++){
      //std::cout<< " graph length: " << this->grafo->getSize() << std::endl;
      std::shared_ptr<Nodo> temp = 
            std::dynamic_pointer_cast<Nodo>(*it);

      uint32_t ncolor = 
         temp.get()->setAvailableColor(this->grafo->getSize());
      
      //if(ncolor > this->k)
      if(ncolor > this->numColors)
         this->numColors = ncolor;   
      // it->setColor(i++);
      // temp.get()->printNeighbors();
   }

   updateGraphColorsAndConflicts();
   updateLocalColorsAndConflicts();

  return true;
}
