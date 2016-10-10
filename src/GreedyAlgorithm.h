#ifndef __GREEDYALGORITHM_H__
#define __GREEDYALGORITHM_H__

#include "GCPAlgorithms.h"
#include "Experiment.h"

class GreedyAlgorithm : public GCPAlgorithms {
public:
   GreedyAlgorithm(char *);
   ~GreedyAlgorithm();

   void updateGraphColorsAndConflicts();
   void updateLocalColorsAndConflicts();

   bool runAlgorithm();

};

#endif
