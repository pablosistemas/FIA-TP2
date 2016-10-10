/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */
#include "cnodosDSatur.h"
#include "../include/registers.h"
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>

NodoDSatur::NodoDSatur() : degreeOfSaturation(0) {}

NodoDSatur::NodoDSatur(uint32_t id) : idx(id), degreeOfSaturation(0) {}

bool fncomp::operator()(const std::shared_ptr<NodoDSatur> &n1, 
   const std::shared_ptr<NodoDSatur> &n2) const {
   bool isLess = n1.get()->getSatur() > n2.get()->getSatur();
   //std::cout << *n1.get() << *n2.get();
   if (n1.get()->getSatur() == n2.get()->getSatur())
      return n1.get()->getIdx() > n2.get()->getIdx();
   else
      return isLess;   
}

void NodoDSatur::setSatur() {

   std::vector<uint32_t> colors(MAX_COLORS,0);

   degreeOfSaturation = 0;

   // runs in neighbors
   for(auto ptr : this->vizinhos) {
      colors[(ptr.lock()).get()->getColor()]++;
      // increments saturation whether color is a different color
      if(colors[(ptr.lock()).get()->getColor()] == 1)
         degreeOfSaturation++;
   }
}

uint32_t NodoDSatur::getSatur() const {
   return degreeOfSaturation;
}

void NodoDSatur::addVizinho (std::shared_ptr<NodoDSatur> nodo_ptr) {
  this->vizinhos.push_back(nodo_ptr);
}

void NodoDSatur::printNeighbors() const {
  std::cout << "I am: " << idx << ": "; 
  for(auto ptr : this->vizinhos) {
      //std::cout << *(ptr.lock()) << std::endl;
      std::cout << ptr.lock()->getIdx() << " ";
  }
  std::cout << std::endl;
}

void NodoDSatur::setColor (uint32_t col) {
   this->color = col;
}

uint32_t NodoDSatur::getColor () const {
   return this->color;
}

std::ostream& operator<< (std::ostream& os, const NodoDSatur &no) {
   os << "Idx: " << no.getIdx() << " Color: " << no.getColor() << std::endl;
   return os;
}

// This method returns the color's number chosen by the vertex. It returns
// 0 if error(all colors have been used) 
uint32_t NodoDSatur::setAvailableColor(uint32_t maxNumColors) {
  std::vector<uint32_t> usedColors(maxNumColors,0);

  std::vector<std::weak_ptr<NodoDSatur>>::const_iterator it;

  for(it = vizinhos.begin(); it != vizinhos.end(); it++){
      std::shared_ptr<NodoDSatur> temp = 
            std::dynamic_pointer_cast<NodoDSatur>((*it).lock());
      // se cor ja definida (!= 0)
      if (temp.get()->getColor() != 0)
         usedColors[temp.get()->getColor()-1] = 1;
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

/*std::set<std::weak_ptr<NodoDSatur>>::const_iterator NodoDSatur::getVizinho(uint32_t idx) const {
   return (vizinhos.begin() + idx);
}*/

uint32_t NodoDSatur::getNumVizinhos() const {
   return vizinhos.size();
}

uint32_t NodoDSatur::getIdx() const {
   return idx;
}

void NodoDSatur::setIsColored() {
   isColored = true;
};

void NodoDSatur::unsetIsColored() {
   isColored = false;
};;
