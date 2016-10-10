/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include <fstream>
#include <sstream>
#include "cgrafosBI.h"
#include "../include/registers.h"

GrafoBI::GrafoBI() : GenericGraph() {}

GrafoBI::GrafoBI(char *nome_arq) : GrafoBI() {
   this->leDoArquivo(nome_arq);
}

GrafoBI::GrafoBI(GrafoBI & gbi) {
   // std::cout << "Grafo copy constructor called\n";
   // gbi.imprimeGrafo();
   // copies vector of NEW shared pointers to nodos
   // The copy is necessary to avoid that internal modification
   // could affect the original graph
   //this->nodos = gbi.getNodos();
   std::function<void(NodoBI *)> destroy = [](NodoBI *p) {
         // std::cout << "deleting copy: "<< p << "\n";
         delete p;
   };

   // copies all nodes
   for(auto ptr : gbi.getNodos()) {
      std::shared_ptr<NodoBI> t (new NodoBI(ptr),destroy);
      nodos.push_back(t);
   }

   for(auto ptr : gbi.getNodos()) {
      // copies the neighbors for each node
      uint32_t numV = ptr.get()->getNumVizinhos();
      for(uint32_t i = 0; i < numV; i++){
         auto it = ptr.get()->getVizinho(i);
         uint32_t idVizinho = (it->lock()).get()->getID();
         // std::cout << "id vizinho: " << idVizinho << "\n";
         nodos[ptr.get()->getID()-1].get()->addVizinho(nodos[idVizinho-1]);
      }
   }

   this->V = gbi.getV();
   this->E = gbi.getE();
   this->numConflicts = gbi.getGraphNumConflicts();
}

std::vector<std::shared_ptr<NodoBI>>& GrafoBI::getNodos() {
   return nodos;
}

std::vector<std::shared_ptr<NodoBI>>::iterator GrafoBI::getBegin() {
  return nodos.begin();
}

std::vector<std::shared_ptr<NodoBI>>::iterator GrafoBI::getEnd() {
  return nodos.end();
}

size_t GrafoBI::getSize() const {
  return this->nodos.size();
}

void GrafoBI::insertInNodos(std::shared_ptr<NodoBI> &n) {
   this->nodos.push_back(n);
}

void GrafoBI::callAddVizinho(uint32_t idx1, uint32_t idx2) {
   // 0 indexed
   // std::cout << "1: " << idx1+1 << " 2: " << idx2+1 << "\n";
   this->nodos[idx1]->addVizinho(nodos[idx2]);
}

void GrafoBI::leDoArquivo(char *nomeArq) {

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

         // propriedades do GrafoBI
         if(linha[0] == 'p') {

            inbuf >> tok >> tipo >> this->V >> this->E;

            for(uint32_t i = 0; i < this->V; i++) {
               std::shared_ptr<NodoBI> t (new NodoBI(i+1),[](NodoBI *p) {
                  // std::cout << "deleting element\n";
                  delete p;
               });
               // set container
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
   //std::cout << "tamanho: " << nodos.size() << "\n";
   //imprimeGrafo();
}

// Sets the graph's conflicts number. This is equal the sum of the
// conflicts for each node in the graph. Nodes conflicts are
// re-evaluated only when there is a pending modification, on the
// other hand, the current node conflict number is returned to
// save time
void GrafoBI::setGraphNumConflicts() {
   numConflicts = 0;
   for(auto ptr : nodos) {
      ptr.get()->setNodoNumConflicts();
      numConflicts += ptr.get()->getNodoNumConflicts();
   }
}

uint32_t GrafoBI::getGraphNumConflicts() const {
   return numConflicts;
}

void GrafoBI::imprimeGrafo() const {
   for(auto ptr : nodos) {
      std::cout << *ptr.get() << std::endl;
   }
}

void GrafoBI::setNumColors() {
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

uint32_t GrafoBI::getNumColors() const {
   return numColors;
}
