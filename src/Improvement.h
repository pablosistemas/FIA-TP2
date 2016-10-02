#ifndef __IMPROVEMENT_H__
#define __IMPROVEMENT_H__

#include "cgrafosBI.h"
#include <memory>
#include <vector>

class Improvement {
protected:
   GrafoBI * grafo;
   
   // Algorithm outputs
   uint32_t k; // number of colors used to completely color 'grafo'
   uint32_t numConflicts; // number of conflicts in 'grafo'
   uint32_t numIterations;

   std::vector<std::shared_ptr<GrafoBI>> ranking;

public:
   Improvement();
   Improvement(char *);
   virtual ~Improvement();

   void criaGrafo(char *);

   void imprimeGrafo() const;

   uint32_t getNumColors() const;

   virtual bool runAlgorithm() = 0;

   virtual GrafoBI* criaVizinhos() = 0;

   void setNumberOfConflicts();

   uint32_t getNumberOfConflicts() const;

   void randomInit();

   uint32_t getNumIterations() const;

};

#endif
