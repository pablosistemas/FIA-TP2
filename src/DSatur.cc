/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "DSatur.h"
#include "../include/registers.h"
#include "cnodosDSatur.h"
#include <random>
#include <chrono>
#include <iterator>
#include <cinttypes>
#include <iostream>
#include <algorithm>

DSatur::DSatur(char *nome_arq) : GCPAlgorithmsDSatur(nome_arq) {}

DSatur::DSatur(char *nome_arq,uint32_t numMaxColors,uint32_t numMaxIter)  : GCPAlgorithmsDSatur(nome_arq) {
   NUM_MAX_COLORS = numMaxColors;
   NUM_MAX_ITERATIONS = numMaxIter;
}

void DSatur::randomInit() {
   std::vector<std::shared_ptr<NodoDSatur>>::iterator it;

   // generates a new seed
   typedef std::chrono::high_resolution_clock myclock;
   myclock::time_point beggining = myclock::now();
   myclock::duration d = myclock::now() - beggining;
   unsigned seed1 = d.count();

   std::default_random_engine generator(seed1);
   std::uniform_int_distribution<uint32_t> distColors(1,NUM_MAX_COLORS);

   for(it = grafo->getBegin(); it != grafo->getEnd(); it++) {
      // selects a random color to the node
      std::shared_ptr<NodoDSatur> temp =
         std::dynamic_pointer_cast<NodoDSatur>(*it);
      temp.get()->setColor(distColors(generator));
   }

   // sets new degree of saturation values
   grafo->updateSatur();
}

// FIXME
// DSATUR algorithm implementation
// It acts like a greedy algorithm, except that it executes the setSatur()
// method, that calculates the saturation degree of the vertex in each update
bool DSatur::runAlgorithm() {
  // solved nodos
    std::vector<std::shared_ptr<NodoDSatur>> solvedNodos;
    std::vector<std::shared_ptr<NodoDSatur>>::iterator it;

    // sorts the nodos vector by degreOfSaturation
   std::sort(grafo->getBegin(), grafo->getEnd(), fncomp());

   it = grafo->getBegin();
   // It colors the first vertex with the first color
   std::shared_ptr<NodoDSatur> temp =
      std::dynamic_pointer_cast<NodoDSatur>(*it);

   temp.get()->setColor(1);

     // updates the degreeOfSaturation of all nodes
     grafo->updateSatur();

     // removes the nodo that was colored ad insert it into solved
     solvedNodos.push_back(temp);
     grafo->removeFirstNodo();

    while( grafo->getSize() > 0) {
      // sorts the nodos vector by degreOfSaturation
      std::sort(grafo->getBegin(), grafo->getEnd(), fncomp());

      it = grafo->getBegin();
      // It colors the first vertex with the first color
      std::shared_ptr<NodoDSatur> temp =
         std::dynamic_pointer_cast<NodoDSatur>(*it);

         // the return value is unused
         temp.get()->setAvailableColor();

       // updates the degreeOfSaturation of all nodes
       grafo->updateSatur();

       // removes the nodo that was colored ad insert it into solved
       solvedNodos.push_back(temp);

       grafo->removeFirstNodo();
    }


   // copies thesolution into nodos
   grafo->copyNodos(solvedNodos);

   grafo->setNumColors();
   grafo->setGraphNumConflicts();

   numColors = grafo->getNumColors();
   numConflicts = grafo->getGraphNumConflicts();

   return true;
}
