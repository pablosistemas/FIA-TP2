#ifndef __IMPROVEMENT_H__
#define __IMPROVEMENT_H__

#include "cgrafosBI.h"
#include <memory>
#include <vector>
#include "Experiment.h"

class Improvement : public Experiment {
protected:
   GrafoBI * grafo;
   // this vector saves the best graph found during algorithm execution
   // these graphs are sorted and the best is compared with grafo attribute to
   // return the best result
   std::vector<std::shared_ptr<GrafoBI>> ranking;

public:
   Improvement();
   Improvement(char *);
   ~Improvement();

   void criaGrafo(char *);

   void imprimeGrafo() const;

   virtual bool runAlgorithm() = 0;

   virtual GrafoBI* criaVizinhos() = 0;

   void setNumberOfConflicts();
   void setNumberOfColors();
   
   void randomInit();

   void printResults();
};

class fifncomp {
public:
   bool operator()(std::shared_ptr<GrafoBI> &, std::shared_ptr<GrafoBI> &);
};
#endif
