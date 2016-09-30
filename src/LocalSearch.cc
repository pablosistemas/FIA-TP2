#include "LocalSearch.h"
#include <cstddef>
#include <vector>
#include "cnodos.h"
#include <random>
#include <iterator>
#include "../include/registers.h"

LocalSearch::LocalSearch(char *nomeArq){
  this->criaGrafo(nomeArq);
}

bool LocalSearch::runAlgorithm(){
   if(this->grafo == nullptr){
     throw "GRAFO nao alocado\n";
   }

   std::default_random_engine generator;
   std::uniform_int_distribution<uint32_t> distColors(1,MAX_COLORS);
   std::uniform_int_distribution<uint32_t> distNodes(1,this->grafo->getSize());

   std::vector<std::shared_ptr<Nodo>>::iterator it;
   // repeat 
   for(;;){ 
      // initializes each node with a random color
      for( it = this->grafo->getBegin(); it != this->grafo->getEnd(); it++){
         // performs casting on each node and set a color to it
         std::shared_ptr<Nodo> temp = 
            std::dynamic_pointer_cast<Nodo>(*it);
         temp.get()->setColor(distColors(generator));         
      }
      // stopping criterion must be redefined for each derived class
      // satisfying runs on each node verifying whether neighbors have different
      // colors
      while(!stoppingCriterion() && !satisfying()){
         uint32_t chosenNode = distNodes(generator);      
         std::vector<std::shared_ptr<Nodo>>::iterator iter;
         
         // chooses a random node of the graph
         iter = (this->grafo->getBegin() + chosenNode);
         
         // sets a random color to it
         std::shared_ptr<Nodo> temp = 
            std::dynamic_pointer_cast<Nodo>(*iter);
         temp.get()->setColor(distColors(generator));         
      }

      if(satisfying())
         return true;
   }
       
   return false;
}

// verifies all neighbors for all nodes to ensure any node has the same color
// its neighbor
bool LocalSearch::satisfying() const {
   std::vector<std::shared_ptr<Nodo>>::iterator it;
   bool isValid = true;
   for( it = this->grafo->getBegin(); it != this->grafo->getEnd(); it++){
      std::shared_ptr<Nodo> temp = 
         std::dynamic_pointer_cast<Nodo>(*it);

      std::vector<std::weak_ptr<Nodo>>::const_iterator ptr;

      uint32_t numVizinhosIt = temp.get()->getNumVizinhos();
      for(uint32_t idx = 0; idx < numVizinhosIt && isValid; idx++){
         std::vector<std::weak_ptr<Nodo>>::const_iterator ptr = 
            temp.get()->getVizinho(idx);
         std::shared_ptr<Nodo> temp2 = 
            std::dynamic_pointer_cast<Nodo>((*ptr).lock());

         if(temp2.get()->getColor() == temp.get()->getColor())
            isValid = false;
              
      }
   }
   return isValid;
}

/*
 *std::shared_ptr<Nodo> temp = std::dynamic_pointer_cast<Nodo>(*(grafo->getBegin()));
   temp.get()->setColor(1);

   for(it = (grafo->getBegin()+1); it != grafo->getEnd(); it++){
       std::shared_ptr<Nodo> temp = 
             std::dynamic_pointer_cast<Nodo>(*it);

       uint32_t ncolor = 
          temp.get()->setAvailableColor(this->grafo->getSize());
       
       if(ncolor > this->k)
          this->k = ncolor;   
   }
   */
