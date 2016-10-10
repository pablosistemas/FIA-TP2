/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafosBI.h"
#include "BestImprovement.h"

int main(int argc, char **argv) {
   if (argc < 2){
      std::cout << "Usage:\n\t./main path-to-input-file\n";
   }
   BestImprovement bi(argv[1]);
   bi.runAlgorithm();
   bi.imprimeGrafo();
   bi.printResults();

   //std::cout << "Numero de cores utilizadas: " << bi.getNumColors() << "\nNumero de iteracoes: " << bi.getNumIterations() << std::endl;

   return 0;
}
