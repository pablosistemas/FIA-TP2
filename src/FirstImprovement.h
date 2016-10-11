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
   ~FirstImprovement();

   GrafoBI* criaVizinhos();
   bool runAlgorithm();

   void printR();
};

class fifncomp {
public:
   bool operator()(std::shared_ptr<GrafoBI> &, std::shared_ptr<GrafoBI> &);
};

#endif
