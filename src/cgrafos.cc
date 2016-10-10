/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include "cgrafos.h"
#include "genericGraph.h"
#include "../include/registers.h"

Grafo::Grafo() : GenericGraph() {}

// construtor invoca leitura do arquivo para alocação do grafo
Grafo::Grafo(char *nomeArq) {
   this->leDoArquivo(nomeArq);   
}

Grafo::Grafo(const Grafo &gh) {
   nodos        = gh.getNodos();   
   numConflicts = gh.getGraphNumConflicts();
   numColors    = gh.getNumColors();
}

Grafo::~Grafo() {}

void Grafo::imprimeGrafo() const {
   for(auto ptr : nodos) {
      std::cout << *ptr << std::endl;
   }
   return;
}

std::vector<std::shared_ptr<Nodo>>::iterator Grafo::getBegin() {
  return nodos.begin();
}

std::vector<std::shared_ptr<Nodo>>::iterator Grafo::getEnd() {
  return nodos.end();
}

size_t Grafo::getSize() const {
  return this->nodos.size();
}

void Grafo::insertInNodos(std::shared_ptr<Nodo> &n) {
   this->nodos.push_back(n);
}

// Sets the graph's conflicts number. This is equal the sum of the
// conflicts for each node in the graph. Nodes conflicts are
// re-evaluated only when there is a pending modification, on the
// other hand, the current node conflict number is returned to
// save time
void Grafo::setGraphNumConflicts() {
   numConflicts = 0;
   for(auto ptr : nodos) {
      ptr.get()->setNodoNumConflicts(); 
      numConflicts += ptr.get()->getNodoNumConflicts();
   }
}

uint32_t Grafo::getGraphNumConflicts() const {
   return numConflicts;
}

void Grafo::callAddVizinho(uint32_t idx1, uint32_t idx2) {

   this->nodos[idx1]->addVizinho(nodos[idx2]);
   this->nodos[idx2]->addVizinho(nodos[idx1]);
}

void Grafo::setNumColors() {
   std::vector<uint32_t> usedColors(MAX_COLORS,0);
   uint32_t differentColors = 0;
   for (auto ptr : nodos) {
      if(usedColors[ptr.get()->getColor()-1] == 0){
         usedColors[ptr.get()->getColor()-1]++;
         differentColors++;
      }
   }
   numColors = differentColors;
}

uint32_t Grafo::getNumColors() const {
   return numColors;
}

std::vector<std::shared_ptr<Nodo>> Grafo::getNodos() const {
   return nodos;
}

void Grafo::leDoArquivo(char *nomeArq) {

   std::fstream inFile;

   inFile.open( nomeArq, std::ios::in );

   std::string linha;

   char tok, tipo [10];

   uint32_t n1, n2;

   std::getline (inFile,linha);

   while(!inFile.eof()){

      // se comentario, ignora
      if(!(linha[0] == 'c')) {

         std::istringstream inbuf(linha);

         // propriedades do Grafo
         if(linha[0] == 'p') {

            inbuf >> tok >> tipo >> this->V >> this->E;

            //std::cout <<  tok << " " << tipo << " " << numNos << " " << numVertices << std::endl;

            // nodos.resize(this->V);
            for(uint32_t i = 0; i < this->V; i++) {
               std::shared_ptr<Nodo> t (new Nodo(),[](Nodo *p) {
                  // std::cout << "deleting element\n";
                  delete p;  
               });
               // set container
               // std::cout << "This guy1\n"; 
               this->insertInNodos(t);
            }

         }
         // vertices - arestas (e)
         else {
            /*if(nodos == NULL){
               std::cout << "Vc deve alocar os nos primeiro" << std::endl;
               exit(-1);
            }*/

            inbuf >> tok >> n1 >> n2;

            // std::cout << tok << " " <<n1 << " " << n2 << std::endl;
            this->callAddVizinho(n1-1,n2-1);
            this->callAddVizinho(n2-1,n1-1);
         }
      }
      std::getline (inFile,linha);
   }
}
