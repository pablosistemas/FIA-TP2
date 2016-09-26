#ifndef __LOCALSEARCH_H__
#define __LOCALSEARCH_H__

#include "GCPAlgorithms.h"

class LocalSearch : public GCPAlgorithms {
public:
    LocalSearch(char *);
    bool runAlgorithm();
    // derived classes must implement this function: random walk, random restart
    virtual bool stoppingCriterion() const = 0;
    bool satisfying() const;
};

#endif
