/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */
#include "cnodos.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

Nodo::Nodo(): color(0), numConflicts(0) {}

Nodo::Nodo(uint32_t col) {
   color = col;
}

void Nodo::addVizinho (std::shared_ptr<Nodo> nodo_ptr) {
  this->vizinhos.push_back(nodo_ptr);
  //std::cout << "Adding: " << idxV << std::endl;
}

void Nodo::printNeighbors() const {
  /*td::ostream_iterator<uint32_t> outIter( std::cout, " ");
  std::cout << "Vizinhos: ";*/
  // copy(vizinhos.begin(), vizinhos.end(), outIter);
  /*copy(vizinhos.begin(), vizinhos.end(), [] (std::shared_ptr<Nodo> p) -> bool
  {
      std::shared_ptr<Nodo> temp = std::dynamic_pointer_cast<Nodo>(p);
      return temp.get() != nullptr;        
  });*/
  for(auto ptr : vizinhos) {
      std::cout << *(ptr.lock()) << std::endl;
  }

  std::cout << std::endl;
}

void Nodo::setColor (uint32_t col) {
   this->color = col;
}

uint32_t Nodo::getColor () const {
   return this->color;
}

void Nodo::setNodoNumConflicts() {
   this->numConflicts = 0;
   for(auto ptr : vizinhos) {
      // Also calls setNodoNumConflicts for the neighbors
      // to guarantee persistence
      if(ptr.lock().get()->getColor() == color)
         this->numConflicts++;
   }
}

uint32_t Nodo::getNodoNumConflicts() const {
   return numConflicts;
}

std::ostream& operator<< (std::ostream& os, const Nodo &no) {
   os << "Color: " << no.getColor();
   return os;
}

uint32_t Nodo::setAvailableColor(uint32_t maxNumColors) {
  std::vector<uint32_t> usedColors(maxNumColors,0);

  // inicializados em 0
  // usedColors.resize();

  //std::vector<std::shared_ptr<Nodo>>::const_iterator it;
  std::vector<std::weak_ptr<Nodo>>::const_iterator it;

  for(it = vizinhos.begin(); it != vizinhos.end(); it++){
      //if( this->getColor() != 0 )
      //std::shared_ptr<Nodo> temp = std::dynamic_pointer_cast<Nodo>(*it);
      std::shared_ptr<Nodo> temp = std::dynamic_pointer_cast<Nodo>((*it).lock());
      // se cor ja definida (!= 0)
      if (temp.get()->getColor() != 0)
         usedColors[temp.get()->getColor()-1] = 1;

      //std::cout << "get color: " << temp->getColor() << std::endl;
  }
  // seleciona primeira cor nao utilizada nos vizinhos para ser cor atual
  auto idxfound = std::find(usedColors.begin(), usedColors.end(), 0);

  if(idxfound != usedColors.end()) {
     auto idx = idxfound - usedColors.begin();
     // std::cout << "length: " << vizinhos.size() << " " << idx << std::endl;
     this->setColor(idx+1);
     return idx;   
  } else
     throw "All colors are used!\n";   
  
  return 0;   
}

std::vector<std::weak_ptr<Nodo>>::const_iterator Nodo::getVizinho(uint32_t idx) const {
   return (vizinhos.begin() + idx);
}

uint32_t Nodo::getNumVizinhos() const {
   return vizinhos.size();
}
