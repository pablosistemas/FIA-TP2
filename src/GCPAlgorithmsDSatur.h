#ifndef __GCPALGORITHMSDSATUR_H__
#define __GCPALGORITHMSDSATUR_H__

#include "cgrafoDSatur.h"

class GCPAlgorithmsDSatur {
protected:
  GrafoDSatur * grafo;
  // numero de cores usada
  uint32_t k; 
public:
  GCPAlgorithmsDSatur();
  GCPAlgorithmsDSatur(char *);
  virtual bool runAlgorithm()=0;
  void criaGrafo(char *);
  virtual ~GCPAlgorithmsDSatur();
  void imprimeGrafo() const;

  uint32_t getK() const;
};

#endif
