#ifndef __LOCALSEARCH_H__
#define __LOCALSEARCH_H__

#include "GCPAlgorithms.h"

class LocalSearch : public GCPAlgorithms {
public:
   LocalSearch(char *);
   virtual ~LocalSearch();
   bool runAlgorithm();
   void grafo2Minimal();
   bool isMinimalWorse() const;
   void updateGraphColorsAndConflicts();
   void updateLocalColorsAndConflicts();
   
   // overloading
   void printResults() const;

   // derived classes must implement this function: random walk, random restart
   virtual bool stoppingCriterion() const = 0;
   bool satisfying() const;
};

#endif
