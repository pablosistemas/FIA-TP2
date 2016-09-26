#ifndef __CNODOS_H_INCLUDED__
#define __CNODOS_H_INCLUDED__

#include <vector>
#include <iostream>
#include <cinttypes>
#include <memory>

class Nodo {
private:
   uint32_t color;
   // std::vector<std::shared_ptr<Nodo>> vizinhos;
   std::vector<std::weak_ptr<Nodo>> vizinhos;

public:
   Nodo();
   Nodo(uint32_t);

   void addVizinho (std::shared_ptr<Nodo>);
   std::vector<std::weak_ptr<Nodo>>::const_iterator getVizinho(uint32_t) const;
   uint32_t getNumVizinhos() const;

   void printNeighbors() const;

   void setColor (uint32_t);
   uint32_t getColor () const;

   uint32_t setAvailableColor(uint32_t);

   const Nodo* operator=(const Nodo& );
   friend std::ostream& operator<<(std::ostream&,const Nodo&);
};

#endif
