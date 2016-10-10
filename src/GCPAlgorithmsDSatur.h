#ifndef __GCPALGORITHMSDSATUR_H__
#define __GCPALGORITHMSDSATUR_H__

#include "cgrafoDSatur.h"
#include "Experiment.h"

class GCPAlgorithmsDSatur : public Experiment {
protected:
  GrafoDSatur * grafo;
  // numero de cores usada
  // uint32_t k; 
public:
  GCPAlgorithmsDSatur();
  GCPAlgorithmsDSatur(char *);
  virtual bool runAlgorithm()=0;
  void criaGrafo(char *);
  virtual ~GCPAlgorithmsDSatur();
  void imprimeGrafo() const;

  //uint32_t getK() const;
};

#endif
