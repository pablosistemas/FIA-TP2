#ifndef __CNODOSDSATUR_H_INCLUDED__
#define __CNODOSDSATUR_H_INCLUDED__

#include <cinttypes>
#include "cnodos.h"
#include <set>
#include <memory>

class NodoDSatur : public Nodo {
private:
   uint32_t degreeOfSaturation;
   std::set<std::shared_ptr<NodoDSatur>> nodos;

public:
   NodoDSatur();
   NodoDSatur(uint32_t);

   void setSatur();
   uint32_t getSatur() const;
};

bool fncomp (const std::shared_ptr<NodoDSatur> &,
         const std::shared_ptr<NodoDSatur> &);
#endif
