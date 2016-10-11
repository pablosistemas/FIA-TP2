#include "LocalSearch.h"
#include <cstddef>
#include <vector>
#include "cnodos.h"
#include <random>
#include <iterator>
#include <chrono>
#include "../include/registers.h"

LocalSearch::LocalSearch(char *nomeArq){
  this->criaGrafo(nomeArq);
}

bool LocalSearch::isMinimalWorse() const {
   return (minimal->getGraphNumConflicts() >
      grafo->getGraphNumConflicts() ||
         (minimal->getGraphNumConflicts() ==
         grafo->getGraphNumConflicts() &&
         grafo->getNumColors() < minimal->getNumColors()));
}

void LocalSearch::grafo2Minimal() {
   if(minimal == nullptr)
      minimal = new Grafo(*this->grafo);
   // copies the current graph in the minimal
   else if(isMinimalWorse()) {
      //std::cout << "NumColors: " << minimal->getNumColors() << "\nNumConflicts: " << minimal->getGraphNumConflicts() << std::endl;
      //std::cout << "NumColors: " << grafo->getNumColors() << "\nNumConflicts: " << grafo->getGraphNumConflicts() << std::endl;
      delete minimal;
      minimal = new Grafo(*this->grafo);
      //std::cout << "NumColors: " << minimal->getNumColors() << "\nNumConflicts: " << minimal->getGraphNumConflicts() << "\n\n";
   }
}

// updates numColors used and numConflicts
void LocalSearch::updateGraphColorsAndConflicts() {
   grafo->setGraphNumConflicts();
   grafo->setNumColors();
}

void LocalSearch::updateLocalColorsAndConflicts() {
   numConflicts = grafo->getGraphNumConflicts();
   numColors    = grafo->getNumColors();
}

bool LocalSearch::runAlgorithm(){

   if(this->grafo == nullptr){
     throw "GRAFO nao alocado\n";
   }

   // generate a random seed
   // uses chrono time clock
   typedef std::chrono::high_resolution_clock myclock;
   myclock::time_point beggining = myclock::now();

   // chooses a random node of the graph
   myclock::duration d = myclock::now()-beggining;
   uint32_t seed1 = d.count();

   std::default_random_engine generator(seed1);
   std::uniform_int_distribution<uint32_t> distColors(1,MAX_COLORS_RANDOM);
   std::uniform_int_distribution<uint32_t> distNodes(0,this->grafo->getSize()-1);

   std::vector<std::shared_ptr<Nodo>>::iterator it;
   // repeat
   //for(;;){
   while(numIterations < MAX_LOCAL_ITER){
      // initializes each node with a random color
      randomRestart();

      // updates numColors used and numConflicts
      updateGraphColorsAndConflicts();
      updateLocalColorsAndConflicts();

      grafo2Minimal();

      // stopping criterion must be redefined for each derived class
      // satisfying() runs on each node verifying whether neighbors have different
      // colors

      uint32_t inIter = 0;
      //while(!stoppingCriterion() && !satisfying()){
      // local search : RANDOM WALK
      while(!stoppingCriterion() && !satisfying() && inIter < MAX_IN_LOCAL_ITER){
         uint32_t chosenNode = distNodes(generator);

         std::vector<std::shared_ptr<Nodo>>::iterator iter;
         // iteration operation
         iter = (this->grafo->getBegin() + chosenNode);

         // sets a random color to it
         std::shared_ptr<Nodo> temp =
            std::dynamic_pointer_cast<Nodo>(*iter);
         temp.get()->setColor(distColors(generator));

         // updates numColors used and numConflicts
         updateGraphColorsAndConflicts();
         updateLocalColorsAndConflicts();

         // copies grafo for minimal whether new grafo is better
         grafo2Minimal();

         inIter++;
      }

      // iterations control
      numIterations++;

      // Returns true whether graph has no conflict
      if(satisfying()){
         return true;
      }
   }

   if(!isMinimalWorse()) {
      delete grafo;
      grafo = new Grafo(*minimal);
      updateLocalColorsAndConflicts();
   }

   return false;
}

// verifies all neighbors for all nodes to ensure any node has the same color
// its neighbor
bool LocalSearch::satisfying() const {
   // std::cout << "Satisfying\n";
   std::vector<std::shared_ptr<Nodo>>::iterator it;
   bool isValid = true;
   for(it = this->grafo->getBegin(); it != this->grafo->getEnd(); it++){
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
   //std::cout << "Satisfying\n";
   return isValid;
}

// initializesall nodes of graph randomly
void LocalSearch::randomRestart() {
  // generate a random seed
  // uses chrono time clock
  typedef std::chrono::high_resolution_clock myclock;
  myclock::time_point beggining = myclock::now();
  myclock::duration d = myclock::now()-beggining;
  uint32_t seed1 = d.count();

  std::default_random_engine generator(seed1);
  std::uniform_int_distribution<uint32_t> distColors(1,MAX_COLORS_RANDOM);
  std::uniform_int_distribution<uint32_t> distNodes(0,this->grafo->getSize()-1);

  for(auto it = this->grafo->getBegin(); it != this->grafo->getEnd(); it++){

     // performs casting on each node and set a color to it
     std::shared_ptr<Nodo> temp =
        std::dynamic_pointer_cast<Nodo>(*it);

     temp.get()->setColor(distColors(generator));
  }
}

void LocalSearch::printResults() const {
   std::cout << "Numero de cores utilizadas: " << numColors
      << "\nNumero de iteracoes: " << numIterations
      << "\nNumero de conflitos: " << numConflicts
      <<  std::endl;
}
