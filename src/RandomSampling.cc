#include "RandomSampling.h"

RandomSampling::RandomSampling(char *nome_arq) : LocalSearch(nome_arq) {}

RandomSampling::RandomSampling(char *nome_arq,uint32_t numMaxColors,uint32_t numMaxIter) : LocalSearch(nome_arq) {
   NUM_MAX_COLORS = numMaxColors;
   NUM_MAX_ITERATIONS = numMaxIter;
}

// the stopping criterion is always true so the while loop
// is never executed. Random Sampling keeps picking random assignments
// until it finds a solution that satisfies the constraints
bool RandomSampling::stoppingCriterion() const {
   return true;
}
