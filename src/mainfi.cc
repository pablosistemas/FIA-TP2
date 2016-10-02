/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafosBI.h"
#include "FirstImprovement.h"

int main(int argc, char **argv) {

   FirstImprovement bi(argv[1]);
   bi.runAlgorithm();
   bi.imprimeGrafo();

   std::cout << "Numero de cores utilizadas: " << bi.getNumColors() << "\nNumero de iteracoes: " << bi.getNumIterations() << "\nNumero de conflitos: " << bi.getNumberOfConflicts() <<  std::endl;

   return 0;
}
