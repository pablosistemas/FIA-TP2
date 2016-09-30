/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafosBI.h"
#include "BestImprovement.h"

int main(int argc, char **argv) {

   BestImprovement bi(argv[1]);
   bi.runAlgorithm();
   bi.imprimeGrafo();

   std::cout << "Numero de cores utilizadas: " << bi.getNumColors() << "\nNumero de iteracoes: " << bi.getNumIterations() << std::endl;

   return 0;
}
