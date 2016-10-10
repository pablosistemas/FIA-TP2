/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafos.h"
#include "GreedyAlgorithm.h"
// #include "cgrafoDSatur.h"

int main(int argc, char **argv) {

   GreedyAlgorithm greedy(argv[1]);
   greedy.runAlgorithm();
   greedy.printResults();

   return 0;
}
