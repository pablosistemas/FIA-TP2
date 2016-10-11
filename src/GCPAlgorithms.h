#ifndef __GCPALGORITHMS_H__
#define __GCPALGORITHMS_H__

#include "cgrafos.h"
#include "Experiment.h"

class GCPAlgorithms : public Experiment {
protected:
  // this graph saves the current graph being processed
  Grafo * grafo;
  // this graph saves the minimal graph found by the algorithms before
  // the random restarting step
  Grafo * minimal;

public:
  GCPAlgorithms();
  GCPAlgorithms(char *);
  // destructor of derives classes must delete only pointers that are not
  // deleted for this destructor to avoid segfault
  ~GCPAlgorithms();

  virtual bool runAlgorithm()=0;
  void criaGrafo(char *);
  void imprimeGrafo() const;
};

#endif
