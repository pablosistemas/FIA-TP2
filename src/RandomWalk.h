#ifndef __RANDOMWALK_H__
#define __RANDOMWALK_H__

#include "LocalSearch.h"

class RandomWalk : public LocalSearch {
public:
    RandomWalk(char *);
    RandomWalk(char *, uint32_t, uint32_t);
    virtual ~RandomWalk();

    // derived classes must implement this function: random walk, random restart
    bool stoppingCriterion() const;
};

#endif
