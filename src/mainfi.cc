/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafosBI.h"
#include "FirstImprovement.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
   if (argc < 4){
      std::cout << "Usage:\n\t./main path-to-input-file\tmax-number-of-colors\tmax-number-of-iterations\n";
      exit(EXIT_FAILURE);
   }

   FirstImprovement bi(argv[1],atoi(argv[2]),atoi(argv[3]));
   bi.runAlgorithm();
   bi.printResults();

   return 0;
}
