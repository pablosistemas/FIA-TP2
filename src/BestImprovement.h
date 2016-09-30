#ifndef __BESTIMPROVEMENT_H__
#define __BESTIMPROVEMENT_H__

#include "cgrafosBI.h"
#include <memory>
#include <vector>

class BestImprovement {
protected:
   GrafoBI * grafo;
   
   // Algorithm outputs
   uint32_t k; // number of colors used to completely color 'grafo'
   uint32_t numConflicts; // number of conflicts in 'grafo'
   uint32_t numIterations;

   std::vector<std::shared_ptr<GrafoBI>> ranking;

public:
   BestImprovement();
   BestImprovement(char *);
   ~BestImprovement();

   void criaGrafo(char *);
   void imprimeGrafo() const;

   uint32_t getNumColors() const;

   bool runAlgorithm();
   GrafoBI* criaVizinhos();

   void setNumberOfConflicts();
   uint32_t getNumberOfConflicts() const;

   void randomInit();

   uint32_t getNumIterations() const;
};

#endif
