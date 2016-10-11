/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafosBI.h"
#include "FirstImprovement.h"
#include <iostream>

int main(int argc, char **argv) {
   if (argc < 2){
      std::cout << "Usage:\n\t./main path-to-input-file\n";
   }
   FirstImprovement bi(argv[1]);
   bi.runAlgorithm();
   bi.printResults();

   return 0;
}
