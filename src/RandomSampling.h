#ifndef __RANDOMSAMPLING_H__
#define __RANDOMSAMPLING_H__

#include "LocalSearch.h"

class RandomSampling : public LocalSearch {
public:
    RandomSampling(char *);
    RandomSampling(char *, uint32_t, uint32_t);
    // derived classes must implement this function: random walk, random restart
    bool stoppingCriterion() const;
};

#endif
