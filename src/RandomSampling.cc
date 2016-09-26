#include "RandomSampling.h"

// the stopping criterion is always true so the while loop
// is never executed. Random Sampling keeps picking random assignments
// until it finds a solution that satisfies the constraints
bool RandomSampling::stoppingCriterion() const {
   return true;
}
