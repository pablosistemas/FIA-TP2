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

DSatur::DSatur(char *nome_arq) : GCPAlgorithmsDSatur(nome_arq) {}

void DSatur::randomInit() {
   std::set<std::shared_ptr<NodoDSatur>,fncomp>::iterator it;

   // generates a new seed
   typedef std::chrono::high_resolution_clock myclock;
   myclock::time_point beggining = myclock::now();
   myclock::duration d = myclock::now() - beggining;   
   unsigned seed1 = d.count();

   std::default_random_engine generator(seed1);
   std::uniform_int_distribution<uint32_t> distColors(1,MAX_COLORS);

   for(it = grafo->getBegin(); it != grafo->getEnd(); it++) {
      // selects random color to the node
      std::shared_ptr<NodoDSatur> temp = 
         std::dynamic_pointer_cast<NodoDSatur>(*it);  
      temp.get()->setColor(distColors(generator));

   }
   // sets new degree of saturation values
   for(it = grafo->getBegin(); it != grafo->getEnd(); it++) {
      std::shared_ptr<NodoDSatur> temp = 
         std::dynamic_pointer_cast<NodoDSatur>(*it);  
      temp.get()->setSatur();
   }
}

// FIXME
// DSATUR algorithm implementation
// It acts like a greedy algorithm, except that it executes the setSatur()
// method, that calculates the saturation degree of the vertex in each update
bool DSatur::runAlgorithm() {

   // initializes randomly
   randomInit();

   std::set<std::shared_ptr<NodoDSatur>>::iterator it = grafo->getBegin();

   // It colors the first vertex with the first color
   std::shared_ptr<NodoDSatur> temp = 
      std::dynamic_pointer_cast<NodoDSatur>(*it);  
   
   temp.get()->setColor(1);   
   
   it++;

   for(; it != grafo->getEnd(); it++) {
      std::shared_ptr<NodoDSatur> temp = 
         std::dynamic_pointer_cast<NodoDSatur>(*it);  
    
      uint32_t ncolor = temp.get()->setAvailableColor(this->grafo->getSize());
      // sets this nodo as colored because it can be reordered and
      // colored again in the same iteration without this step
      temp.get()->setIsColored(); 

      /*if(ncolor > this->k)
         this->k = ncolor;   */
   
      if(ncolor > this->numColors)
         this->numColors = ncolor;
   
   }

   return true;
}
