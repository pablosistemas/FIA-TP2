#ifndef __EXPERIMENT_H__
#define __EXPERIMENT_H__

#include <cinttypes>

class Experiment {
protected:
   // Algorithm outputs
   uint32_t numIterations;
   uint32_t numColors;
   uint32_t numConflicts;

   // these properties must be setted by the leaf object
   // by default its values is equal to MAX_COLORS and MAX_ITER in
   // ../include/registers.h, respectively
   uint32_t NUM_MAX_COLORS;
   uint32_t NUM_MAX_ITERATIONS;

public:
  // constructor
   Experiment();
   uint32_t getNumColors() const;
   uint32_t getNumberOfConflicts() const;
   uint32_t getNumIterations() const;

   void printResults() const;
};

#endif
