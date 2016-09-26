#ifndef __RANDOMWALK_H__
#define __RANDOMWALK_H__

#include "cgrafos.h"
#include "GCPAlgorithms.h"

class RandomWalk : public GCPAlgorithms {
public:
  Grafo * grafo;
private:
  void criaGrafo(char *);
};

#endif
