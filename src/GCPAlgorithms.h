#ifndef __GCPALGORITHMS_H__
#define __GCPALGORITHMS_H__

#include "cgrafos.h"
#include "Experiment.h"

class GCPAlgorithms : public Experiment {
protected:
  Grafo * grafo;
  // numero de cores usada
  // uint32_t k; 
  Grafo * minimal;

public:
  GCPAlgorithms();
  GCPAlgorithms(char *);
  ~GCPAlgorithms();

  virtual bool runAlgorithm()=0;
  void criaGrafo(char *);
  void imprimeGrafo() const;

  // uint32_t getK() const;
};

#endif
