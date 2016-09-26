/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */
#include "cnodosDSatur.h"

bool fncomp (const std::shared_ptr<NodoDSatur> &n1, 
      const std::shared_ptr<NodoDSatur> &n2) {
   // TODO
   return n1->getSatur() > n2->getSatur();
   /*return std::dynamic_pointer_cast<NodoDSatur>(*n1).get()->getSatur() > 
            std::dynamic_pointer_cast<NodoDSatur>(*n2).get()->getSatur();*/
}

NodoDSatur::NodoDSatur() : degreeOfSaturation(0) {}

NodoDSatur::NodoDSatur(uint32_t dS) : degreeOfSaturation(dS) {}

void NodoDSatur::setSatur() {
   std::set<std::shared_ptr<NodoDSatur>>::iterator it;
   for(it = this->nodos.begin(); it != this->nodos.end(); it++){
      // TODO      
   }
}
