/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafosBI.h"
#include "RandomWalk.h"

int main(int argc, char **argv) {
   if (argc < 4){
      std::cout << "Usage:\n\t./main path-to-input-file\tmax-number-of-colors\tmax-number-of-iterations\n";
      exit(EXIT_FAILURE);
   }

   RandomWalk rwalk(argv[1],atoi(argv[2]),atoi(argv[3]));
   rwalk.runAlgorithm();
   rwalk.printResults();

   return 0;
}
