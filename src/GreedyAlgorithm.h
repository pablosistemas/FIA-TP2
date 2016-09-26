#ifndef __GREEDYALGORITHM_H__
#define __GREEDYALGORITHM_H__

#include "GCPAlgorithms.h"

class GreedyAlgorithm : public GCPAlgorithms {
public:
    GreedyAlgorithm(char *);
    ~GreedyAlgorithm();

    bool runAlgorithm();
};

#endif
