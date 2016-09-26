/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "genericGraph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cinttypes>

GenericGraph::GenericGraph() : V(0), E(0) {}

GenericGraph::GenericGraph(char *nomearq) : GenericGraph() {
   std::cout << "Building" << std::endl;
   //this->leDoArquivo(nomearq);   
}

uint32_t GenericGraph::getV() const {
   return V;
}

uint32_t GenericGraph::getE() const {
   return E;
}


