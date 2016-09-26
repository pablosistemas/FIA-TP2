/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include "genericGraph.h"

Grafo::Grafo() : GenericGraph() {}

// construtor invoca leitura do arquivo para alocação do grafo
Grafo::Grafo(char *nomeArq) {
   this->leDoArquivo(nomeArq);   
}

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

void Grafo::callAddVizinho(uint32_t idx1, uint32_t idx2) {

   this->nodos[idx1]->addVizinho(nodos[idx2]);
   this->nodos[idx2]->addVizinho(nodos[idx1]);
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
