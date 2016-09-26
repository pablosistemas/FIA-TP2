#include "RandomWalk.h"

// the stopping criterion is always false so the while loop
// is only exited when it has found a satisfying assignments. 
// (There is no random restarts)
bool RandomWalk::stoppingCriterion() const {
   return false;
}
