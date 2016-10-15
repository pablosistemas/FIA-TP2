#include "RandomWalk.h"

RandomWalk::RandomWalk(char *nome_arq) : LocalSearch(nome_arq) {}

RandomWalk::RandomWalk(char *nome_arq,uint32_t numMaxColors,uint32_t numMaxIter) : LocalSearch(nome_arq) {
   NUM_MAX_COLORS = numMaxColors;
   NUM_MAX_ITERATIONS = numMaxIter;
}

RandomWalk::~RandomWalk() {}

// the stopping criterion is always false so the while loop
// is only exited when it has found a satisfying assignments.
// (There is no random restarts)
bool RandomWalk::stoppingCriterion() const {
   return false;
}
