/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafoDSatur.h"

int main(int argc, char **argv) {

   DSaturGreedyAlgorithm dsatur(argv[1]);
   dsatur.runAlgorithm();
   dsatur.imprimeGrafo();

   return 0;
}
