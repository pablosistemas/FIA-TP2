#ifndef __DSATUR_H__
#define __DSATUR_H__

#include <set>
#include <memory>
#include "GCPAlgorithms.h"

class DSatur : public GCPAlgorithms() {
public:
   DSatur(char *);
   bool runAlgorithm();
};

#endif
