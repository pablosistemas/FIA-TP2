#ifndef __CNODOSBI_H_INCLUDED__
#define __CNODOSBI_H_INCLUDED__

#include "cnodos.h"
#include <vector>
#include <iostream>
#include <cinttypes>
#include <memory>

class NodoBI : public Nodo {
private:
   uint32_t numConflicts;
   bool isModified;

public:
   NodoBI();

   void setColor(uint32_t); // overloaded

   void setNodoNumConflicts();
   uint32_t getNodoNumConflicts() const;
};

#endif
