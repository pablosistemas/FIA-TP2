#ifndef __FIRSTIMPROVEMENT_H__
#define __FIRSTIMPROVEMENT_H__

#include "cgrafosBI.h"
#include "Improvement.h"
#include <memory>
#include <vector>

class FirstImprovement : public Improvement {
public:
   FirstImprovement();
   FirstImprovement(char *);
   FirstImprovement(char *, uint32_t, uint32_t);
   ~FirstImprovement();

   GrafoBI* criaVizinhos();
   bool runAlgorithm();

};

#endif
