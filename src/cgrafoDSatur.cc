/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "cgrafos.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

GrafoDSatur::GrafoDSatur() {}

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

std::set<std::shared_ptr<Nodo>>::iterator GrafoDSatur::getBegin() {
  return nodos.begin();
}

std::set<std::shared_ptr<Nodo>>::iterator GrafoDSatur::getEnd() {
  return nodos.end();
}

size_t GrafoDSatur::getSize() const {
  return this->nodos.size();
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
