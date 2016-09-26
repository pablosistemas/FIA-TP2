/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "DSatur.h"

bool DSatur::runAlgorithm() {
   std::set<std::shared_ptr<NodoDSatur>>::iterator it;
   for(it = grafo->getBegin(); it != grafo->getEnd(); it++) {
      std::shared_ptr<NodoDSatur> temp = 
         std::dynamic_pointer_cast<NodoDSatur>(*it);  
         temp.get()->setAvailableColor();
         temp.get()->incrementNeighborsDegree();
   }
   return true;
}
