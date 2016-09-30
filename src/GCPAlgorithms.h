#ifndef __GCPALGORITHMS_H__
#define __GCPALGORITHMS_H__

#include "cgrafos.h"

class GCPAlgorithms {
protected:
  Grafo * grafo;
  // numero de cores usada
  uint32_t k; 
public:
  GCPAlgorithms();
  GCPAlgorithms(char *);
  virtual bool runAlgorithm()=0;
  void criaGrafo(char *);
  virtual ~GCPAlgorithms();
  void imprimeGrafo() const;

  uint32_t getK() const;
};

#endif
