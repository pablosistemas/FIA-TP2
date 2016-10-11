/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */
#include "Experiment.h"
#include <iostream>

//Constructor
Experiment::Experiment() : numIterations(0), numColors(0), numConflicts(0) {}

// get current number of iterations
uint32_t Experiment::getNumIterations() const {
   return numIterations;
}

// get number of colors used in this algorithm instance
uint32_t Experiment::getNumColors() const {
   return numColors;
}

// get the number of conflicts found in the graph
uint32_t Experiment::getNumberOfConflicts() const {
   return numConflicts;
}

// print the default way to show the results for all algorithms
void Experiment::printResults() const {
   std::cout << "Numero de cores utilizadas: " << numColors
      << "\nNumero de iteracoes: " << numIterations
      << "\nNumero de conflitos: " << numConflicts
      <<  std::endl;
}
