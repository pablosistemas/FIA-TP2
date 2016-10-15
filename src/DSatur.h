#ifndef __DSATUR_H__
#define __DSATUR_H__

#include <memory>
#include "GCPAlgorithmsDSatur.h"

class DSatur : public GCPAlgorithmsDSatur {
public:
   DSatur(char *);
   DSatur(char *,uint32_t,uint32_t);
   void randomInit();
   bool runAlgorithm();
};

#endif
