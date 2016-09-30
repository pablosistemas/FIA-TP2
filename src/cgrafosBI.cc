/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafosBI.h"
#include <fstream>
#include <sstream>

GrafoBI::GrafoBI() : GenericGraph() {}

GrafoBI::GrafoBI(char *nome_arq) : GrafoBI() {
   this->leDoArquivo(nome_arq); 
}

GrafoBI::GrafoBI(const GrafoBI & gbi) {
   // copies vector of shared pointers to nodos
   this->nodos = gbi.nodos;      
   this->V = gbi.getV();
   this->E = gbi.getE();
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

   this->nodos[idx1]->addVizinho(nodos[idx2]);
   this->nodos[idx2]->addVizinho(nodos[idx1]);
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
               std::shared_ptr<NodoBI> t (new NodoBI(),[](NodoBI *p) {
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
            this->callAddVizinho(n2-1,n1-1);
         }
      }
      std::getline (inFile,linha);
   }
}

void GrafoBI::setGraphNumConflicts() {
   for(auto ptr : nodos) {
      ptr.get()->setNodoNumConflicts();  
   }
}

uint32_t GrafoBI::getGraphNumConflicts() const {
   uint32_t numConflicts = 0;
   for(auto ptr : nodos) {
      numConflicts += ptr.get()->getNodoNumConflicts();  
   }
   return numConflicts;
}

void GrafoBI::imprimeGrafo() const {
   for(auto ptr : nodos) {
      std::cout << *ptr.get();
   }
}
