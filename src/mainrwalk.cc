/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafosBI.h"
#include "RandomWalk.h"

int main(int argc, char **argv) {
   if (argc < 2){
      std::cout << "Usage:\n\t./main path-to-input-file\n";
   }

   RandomWalk rwalk(argv[1]);
   //rwalk.imprimeGrafo();
   rwalk.runAlgorithm();
   rwalk.printResults();
   // std::cout << "Numero de cores utilizadas: " << bi.getNumColors() << "\nNumero de iteracoes: " << bi.getNumIterations() << "\nNumero de conflitos: " << bi.getNumberOfConflicts() <<  std::endl;

   return 0;
}
