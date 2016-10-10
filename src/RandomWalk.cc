#include "RandomWalk.h"

RandomWalk::RandomWalk(char *nome_arq) : LocalSearch(nome_arq) {}

RandomWalk::~RandomWalk() {}

// the stopping criterion is always false so the while loop
// is only exited when it has found a satisfying assignments. 
// (There is no random restarts)
bool RandomWalk::stoppingCriterion() const {
   return false;
}
