#ifndef __EXPERIMENT_H__
#define __EXPERIMENT_H__

#include <cinttypes>

class Experiment {
protected:
   // Algorithm outputs
   uint32_t numIterations;
   uint32_t numColors;
   uint32_t numConflicts;
public:
  // constructor
   Experiment();
   uint32_t getNumColors() const;
   uint32_t getNumberOfConflicts() const;
   uint32_t getNumIterations() const;

   void printResults() const;
};

#endif
