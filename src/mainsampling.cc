/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafosBI.h"
#include "RandomSampling.h"

int main(int argc, char **argv) {
   if (argc < 4){
      std::cout << "Usage:\n\t./main path-to-input-file\tmax-number-of-colors\tmax-number-of-iterations\n";
      exit(EXIT_FAILURE);
   }

   RandomSampling s(argv[1],atoi(argv[2]),atoi(argv[3]));
   s.runAlgorithm();
   s.printResults();

   return 0;
}
