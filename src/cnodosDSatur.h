#ifndef __CNODOSDSATUR_H_INCLUDED__
#define __CNODOSDSATUR_H_INCLUDED__

#include <cinttypes>
#include <vector>
#include <memory>
#include <iostream>

class NodoDSatur {
protected:
   uint32_t idx;
   uint32_t color;
   // number of different colors used by the neighbors
   uint32_t degreeOfSaturation;

   uint32_t numConflicts;

   bool isColored;
   std::vector<std::weak_ptr<NodoDSatur>> vizinhos;

public:
   NodoDSatur();
   NodoDSatur(uint32_t);

   void setSatur();
   uint32_t getSatur() const;

   uint32_t getIdx() const;

   void addVizinho (std::shared_ptr<NodoDSatur>);

   uint32_t getNumVizinhos() const;
    uint32_t getNodoNumConflicts() const;
   uint32_t getColor () const;

   void printNeighbors() const;

   void setColor (uint32_t);
   void setNodoNumConflicts();
   uint32_t setAvailableColor();

   void setIsColored();
   void unsetIsColored();

   //std::set<std::weak_ptr<NodoDSatur>>::const_iterator getVizinho(uint32_t) const;

   friend std::ostream& operator<<(std::ostream&,const NodoDSatur&);

};

struct fncomp {
   bool operator()(const std::shared_ptr<NodoDSatur> &n1,
      const std::shared_ptr<NodoDSatur> &n2) const;
};



#endif
