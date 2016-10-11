/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafoDSatur.h"
#include "DSatur.h"

int main(int argc, char **argv) {

   DSatur dsatur(argv[1]);
   dsatur.runAlgorithm();
   dsatur.printResults();
   //std::cout << "Numero de cores utilizadas: " << dsatur.getK() << std::endl;

   return 0;
}
