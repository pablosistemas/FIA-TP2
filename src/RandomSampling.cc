#include "RandomSampling.h"

RandomSampling::RandomSampling(char *nome_arq) : LocalSearch(nome_arq) {}

RandomSampling::~RandomSampling(){}

// the stopping criterion is always true so the while loop
// is never executed. Random Sampling keeps picking random assignments
// until it finds a solution that satisfies the constraints
bool RandomSampling::stoppingCriterion() const {
   return true;
}
