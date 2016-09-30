/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cnodosBI.h"

NodoBI::NodoBI() : Nodo(), numConflicts(0), isModified(false) {}

void NodoBI::setColor (uint32_t col) {
   this->color = col;
   // it is needed to know when we must call setNodoNumConflicts again
   isModified = true;
}

   // calculates num of conflicts only when the nodo was modified
void NodoBI::setNodoNumConflicts() {
   if(isModified){
      this->numConflicts = 0;
      for(auto ptr : vizinhos) {
         if(ptr.lock().get()->getColor() == color)
            this->numConflicts++;
      }
   }

   isModified = false;
}

uint32_t NodoBI::getNodoNumConflicts() const {
   return numConflicts;
}
