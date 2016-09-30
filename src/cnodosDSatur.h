#ifndef __CNODOSDSATUR_H_INCLUDED__
#define __CNODOSDSATUR_H_INCLUDED__

#include <cinttypes>
#include <vector>
#include <memory>
#include <iostream>

class NodoDSatur {
private:
   uint32_t idx;
   uint32_t color;
   uint32_t degreeOfSaturation;
   std::vector<std::weak_ptr<NodoDSatur>> vizinhos;

public:
   NodoDSatur();
   NodoDSatur(uint32_t);

   void setSatur();
   uint32_t getSatur() const;

   uint32_t getIdx() const;

   void addVizinho (std::shared_ptr<NodoDSatur>);

   uint32_t getNumVizinhos() const;
   void printNeighbors() const;

   void setColor (uint32_t);
   uint32_t getColor () const;

   //std::set<std::weak_ptr<NodoDSatur>>::const_iterator getVizinho(uint32_t) const;

   uint32_t setAvailableColor(uint32_t);

   friend std::ostream& operator<<(std::ostream&,const NodoDSatur&);

};

struct fncomp {
   bool operator()(const std::shared_ptr<NodoDSatur> &n1, 
      const std::shared_ptr<NodoDSatur> &n2) const;
};



#endif
