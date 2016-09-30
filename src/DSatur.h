#ifndef __DSATUR_H__
#define __DSATUR_H__

#include <memory>
#include "GCPAlgorithmsDSatur.h"

class DSatur : public GCPAlgorithmsDSatur {
public:
   DSatur(char *);
   void randomInit();
   bool runAlgorithm();
};

#endif
