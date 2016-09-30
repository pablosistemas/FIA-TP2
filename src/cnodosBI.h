#ifndef __CNODOSBI_H_INCLUDED__
#define __CNODOSBI_H_INCLUDED__

#include "cnodos.h"
#include <vector>
#include <iostream>
#include <cinttypes>
#include <memory>

class NodoBI : public Nodo {
protected:
   uint32_t numConflicts;
   bool isModified;
   uint32_t id;
   std::vector<std::weak_ptr<NodoBI>> vizinhosBI;

public:
   NodoBI();
   NodoBI(uint32_t);
   NodoBI(std::shared_ptr<NodoBI> &);

   void setColor(uint32_t); // overloaded

   void setNodoNumConflicts();
   void verifyAndSetNodoNumConflicts();
   uint32_t getNodoNumConflicts() const;

   uint32_t getID() const;

   friend std::ostream &operator<<(std::ostream &, const NodoBI &);

   std::vector<std::weak_ptr<NodoBI>>::const_iterator getVizinho(uint32_t) const;

   void addVizinho (std::shared_ptr<NodoBI>);

   uint32_t getNumVizinhos() const;

   void printNeighbors() const;
};

#endif
