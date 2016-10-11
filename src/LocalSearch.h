#ifndef __LOCALSEARCH_H__
#define __LOCALSEARCH_H__

#include "GCPAlgorithms.h"

class LocalSearch : public GCPAlgorithms {
public:
   LocalSearch(char *);
   bool runAlgorithm();

   // initializes all nodes randomly
   void randomRestart();

   // copies current grafo to minimal whether minimal is nullptr or
   // either minimal is worse candidate than grafo
   void grafo2Minimal();

   // returns true whether minial grafo has more conflicts than
   // grafo
   bool isMinimalWorse() const;

   // call grafo setNumColors() and grafo setGraphNumConflicts
   // after, you must invoke updateLocalColorsAndConflicts to
   // record the grafo conflicts and colors numbers into algorithm instance
   void updateGraphColorsAndConflicts();
   void updateLocalColorsAndConflicts();

   // overloading
   void printResults() const;

   // derived classes must implement this function: random walk, random restart
   virtual bool stoppingCriterion() const = 0;

   // returns true whether grafo has no conflicts
   bool satisfying() const;
};

#endif
