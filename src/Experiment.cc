/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */
#include "Experiment.h"
#include <iostream>

Experiment::Experiment() : numIterations(0), numColors(0), numConflicts(0) {}

uint32_t Experiment::getNumIterations() const {
   return numIterations;
}

uint32_t Experiment::getNumColors() const {
   return numColors;
}

uint32_t Experiment::getNumberOfConflicts() const {
   return numConflicts;
}

void Experiment::printResults() const {
   std::cout << "Numero de cores utilizadas: " << numColors 
      << "\nNumero de iteracoes: " << numIterations
      << "\nNumero de conflitos: " << numConflicts
      <<  std::endl;
}
