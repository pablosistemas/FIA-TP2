/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafoDSatur.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "../include/registers.h"

GrafoDSatur::GrafoDSatur() : numConflicts(0), numColors(0) {}

GrafoDSatur::~GrafoDSatur() {}

// construtor invoca leitura do arquivo para alocação do grafo
GrafoDSatur::GrafoDSatur (char *nomeArq) : GrafoDSatur() {
   leDoArquivo (nomeArq);
}

void GrafoDSatur::imprimeGrafo() const {
   for(auto ptr : nodos) {
      std::cout << *ptr << std::endl;
   }
   return;
}

// returns an iterator for begin nodo
std::vector<std::shared_ptr<NodoDSatur>>::iterator GrafoDSatur::getBegin() {
   return nodos.begin();
}

// returns an iterator for end nodo
std::vector<std::shared_ptr<NodoDSatur>>::iterator GrafoDSatur::getEnd() {
   return nodos.end();
}

size_t GrafoDSatur::getSize() const {
   return this->nodos.size();
}

// Defines the number of unique neighboring colors. In case of a tie,
// returns the node with largest degree.
// This method presumes a initialized graph.
void GrafoDSatur::updateSatur() {

   for(auto it = nodos.begin(); it != nodos.end(); it++){
      // TODO
      std::shared_ptr<NodoDSatur> temp = std::dynamic_pointer_cast<NodoDSatur>(*it);
      // reevaluates the degree of saturation
      temp.get()->setSatur();
   }
   return;
}

void GrafoDSatur::insertInNodos(std::shared_ptr<NodoDSatur> &n) {
   nodos.push_back(n);
   //std::cout << "length: " << nodos.size() << std::endl;
}

struct isIdx {
   isIdx(uint32_t an_index) : index(an_index) {}
   uint32_t index;
   bool operator()(const std::shared_ptr<NodoDSatur> &n) const {
      //std::cout << n.get()->getIdx() << " vs. " << index << std::endl;
      return n.get()->getIdx() == index;
   }
};

void GrafoDSatur::callAddVizinho(uint32_t idx1, uint32_t idx2) {
   std::function<void(NodoDSatur *)> destroy = [](NodoDSatur *p) {
      delete p;
   };
   nodos[idx1].get()->addVizinho(nodos[idx2]);
}

// removes the first nodo from the vector
void GrafoDSatur::removeFirstNodo() {
   nodos.erase(nodos.begin());
}

void GrafoDSatur::copyNodos(const std::vector<std::shared_ptr<NodoDSatur>> &n){
   nodos = n;
}

// Sets the graph's conflicts number. This is equal the sum of the
// conflicts for each node in the graph. Nodes conflicts are
// re-evaluated only when there is a pending modification, on the
// other hand, the current node conflict number is returned to
// save time
void GrafoDSatur::setGraphNumConflicts() {
   numConflicts = 0;
   for(auto ptr : nodos) {
      ptr.get()->setNodoNumConflicts();
      numConflicts += ptr.get()->getNodoNumConflicts();
   }
}

uint32_t GrafoDSatur::getNumColors() const {
   return numColors;
}

uint32_t GrafoDSatur::getGraphNumConflicts() const {
   return numConflicts;
}

void GrafoDSatur::setNumColors() {
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

void GrafoDSatur::leDoArquivo(char *nomeArq) {

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
            
            // nodos.resize(this->V);
            for(uint32_t i = 0; i < this->V; i++) {
               std::shared_ptr<NodoDSatur> t (new NodoDSatur(i+1),[](NodoDSatur *p) {
                  // std::cout << "deleting element from dsatur graph\n";
                  delete p;
               });
               // multiset container
               this->insertInNodos(t);
            }

         }
         // vertices - arestas (e)
         else {

            inbuf >> tok >> n1 >> n2;
            this->callAddVizinho(n1-1,n2-1);
         }
      }
      std::getline (inFile,linha);
   }
   inFile.close();

   // imprimeGrafo();
}
