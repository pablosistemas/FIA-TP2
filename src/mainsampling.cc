/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafosBI.h"
#include "RandomSampling.h"

int main(int argc, char **argv) {
   if (argc < 2){
      std::cout << "Usage:\n\t./main path-to-input-file\n";
   }

   RandomSampling s(argv[1]);
   s.runAlgorithm();
   s.printResults();

   return 0;
}
