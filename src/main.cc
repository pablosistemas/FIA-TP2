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
   //Grafo temp(argv[1]);

   //temp.imprimeGrafo();

   GreedyAlgorithm greedy(argv[1]);

   //greedy.imprimeGrafo();

   greedy.runAlgorithm();

   greedy.imprimeGrafo();

   // DSaturGreedyAlgorithm greedy(argv[1]);
   // greedy.runAlgorithm();

   return 0;
}
