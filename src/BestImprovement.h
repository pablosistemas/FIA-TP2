#ifndef __BESTIMPROVEMENT_H__
#define __BESTIMPROVEMENT_H__

#include "cgrafosBI.h"
#include <memory>
#include <vector>
#include "Improvement.h"

class BestImprovement : public Improvement {
public:
   BestImprovement();
   BestImprovement(char *);
   BestImprovement(char *, uint32_t, uint32_t);
   ~BestImprovement();

   bool runAlgorithm();
   GrafoBI* criaVizinhos();

};

#endif
