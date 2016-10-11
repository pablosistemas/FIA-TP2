#ifndef __GCPALGORITHMSDSATUR_H__
#define __GCPALGORITHMSDSATUR_H__

#include "cgrafoDSatur.h"
#include "Experiment.h"

class GCPAlgorithmsDSatur : public Experiment {
protected:
  GrafoDSatur * grafo;
public:
  GCPAlgorithmsDSatur();
  GCPAlgorithmsDSatur(char *);
  ~GCPAlgorithmsDSatur();

  virtual bool runAlgorithm()=0;
  void criaGrafo(char *);
  void imprimeGrafo() const;
};

#endif
