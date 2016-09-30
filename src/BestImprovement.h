#ifndef __BESTIMPROVEMENT_H__
#define __BESTIMPROVEMENT_H__

#include "cgrafosBI.h"
#include <memory>

class BestImprovement {
protected:
   GrafoBI * grafo;
   uint32_t k; // number of colors used to completely color 'grafo'
   uint32_t numConflicts; // number of conflicts in 'grafo'
public:
   BestImprovement();
   BestImprovement(char *);
   ~BestImprovement();

   void criaGrafo(char *);
   void imprimeGrafo() const;

   uint32_t getK() const;

   bool runAlgorithm();
   std::shared_ptr<GrafoBI> criaVizinhos();

   void setNumberOfConflicts();

   uint32_t getNumberOfConflicts() const;

   void randomInit();
};

#endif
