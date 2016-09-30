/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cnodosBI.h"

NodoBI::NodoBI() : Nodo(), numConflicts(0), isModified(false) {}

NodoBI::NodoBI(uint32_t iid) : NodoBI() { id = iid; }

NodoBI::NodoBI(std::shared_ptr<NodoBI> & n) { 
   id = n.get()->getID();
   color = n.get()->getColor();
   numConflicts = n.get()->getNodoNumConflicts();
}

// Changes the color for this node
void NodoBI::setColor (uint32_t col) {
   // std::cout << "setting color: " << col << "\n";
   this->color = col;
   // it is needed to know when we must call setNodoNumConflicts again
   this->isModified = true;
}

// calculates num of conflicts only when the nodo was modified
// We consider a conflict when a neighbor has the same color
// that this node
void NodoBI::verifyAndSetNodoNumConflicts() {
   if(isModified){
      setNodoNumConflicts();
   } else {
      std::cout<<"nao foi modificado\n";
      // std::cout<<"conflicts "<<id<<" : "<<numConflicts;
   }

   isModified = false;
}

void NodoBI::setNodoNumConflicts() {
   this->numConflicts = 0;
   for(auto ptr : vizinhosBI) {
      // Also calls setNodoNumConflicts for the neighbors 
      // to guarantee persistence
      // ptr.lock().get()->setNodoNumConflicts();
      if(ptr.lock().get()->getColor() == color)
         this->numConflicts++;
   }
}

// Returns the number of conflicts for this node
uint32_t NodoBI::getNodoNumConflicts() const {
   return numConflicts;
}

// Returns the ID for the current node
uint32_t NodoBI::getID() const {
   return id;
}

// For printing nodes in easy way, only type std::cout << node;
std::ostream &operator<<(std::ostream &stream, const NodoBI &n) {
   
   stream << "Addr: " << &n <<"\tId: " << n.getID() << "\tColor: " << n.getColor() << "\tNum conflicts: " << n.getNodoNumConflicts()<<"\nVizinhos: ";
   for(uint32_t i = 0; i < n.getNumVizinhos(); i++){

      auto it = n.getVizinho(i);
      stream << (it->lock()).get()->getID() << " ";
   }

   return stream;
}

std::vector<std::weak_ptr<NodoBI>>::const_iterator NodoBI::getVizinho(uint32_t idx) const {
   return (vizinhosBI.begin() + idx);
}

uint32_t NodoBI::getNumVizinhos() const {
   return vizinhosBI.size();
}

void NodoBI::addVizinho (std::shared_ptr<NodoBI> nodo_ptr) {
  this->vizinhosBI.push_back(nodo_ptr);
  // std::cout << id << " is adding: " << nodo_ptr.get()->getID() << std::endl;
}

void NodoBI::printNeighbors() const {
   for(auto ptr : vizinhosBI)
      std::cout << *(ptr.lock()) << std::endl;
}
