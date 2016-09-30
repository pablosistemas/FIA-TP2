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

std::multiset<std::shared_ptr<NodoDSatur>,fncomp>::iterator GrafoDSatur::getBegin() {
   return nodos.begin();
}

std::multiset<std::shared_ptr<NodoDSatur>,fncomp>::iterator GrafoDSatur::getEnd() {
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
            // std::cout << "inserting: " << tok << " " << tipo << " " << this->V << " " << this->E << std::endl;

            // nodos.resize(this->V);
            for(uint32_t i = 0; i < this->V; i++) {
               std::shared_ptr<NodoDSatur> t (new NodoDSatur(i+1),[](NodoDSatur *p) {
                  // std::cout << "deleting element from dsatur graph\n";
                  delete p;  
               });
               // multiset container
               //std::cout << "inserting : " << i << std::endl;
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
   inFile.close();
   
   // imprimeGrafo();
}

// Defines the number of unique neighboring colors. In case of a tie,
// returns the node with largest degree.
// This method presumes a initialized graph.
void GrafoDSatur::updateSatur() {
   
   std::multiset<std::shared_ptr<NodoDSatur>>::iterator it;

   for(it = this->nodos.begin(); it != this->nodos.end(); it++){
      // TODO      
      std::shared_ptr<NodoDSatur> temp = std::dynamic_pointer_cast<NodoDSatur>(*it);

      std::vector<uint32_t> colors(MAX_COLORS,0);

      temp.get()->setSatur();
   }

   return;
}

void GrafoDSatur::insertInNodos(std::shared_ptr<NodoDSatur> &n) {
   nodos.insert(n);
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

   //std::cout << "Call add vizinho: " << idx1 << " " << idx2 << std::endl;

   std::function<void(NodoDSatur *)> destroy = [](NodoDSatur *p) {
      delete p;  
   };

   //std::shared_ptr<NodoDSatur> t1 (new NodoDSatur(idx1),destroy);

   //std::shared_ptr<NodoDSatur> t2 (new NodoDSatur(idx2),destroy);

   // std::multiset<std::shared_ptr<NodoDSatur>>::iterator it1 = nodos.find(t1);
   // std::multiset<std::shared_ptr<NodoDSatur>>::iterator it2 = nodos.find(t2);

   std::multiset<std::shared_ptr<NodoDSatur>>::iterator it1 = 
      std::find_if(nodos.begin(), nodos.end(), isIdx(idx1));

   std::multiset<std::shared_ptr<NodoDSatur>>::iterator it2 = 
      std::find_if(nodos.begin(), nodos.end(), isIdx(idx2));

   if(it1 == nodos.end()) {
      //std::cout<<"ENding\n";
   }
   
   if(!(it1 == nodos.end() || it2 == nodos.end())){
      //std::cout << "Found? " << std::endl;
      //std::cout << "Found: " << it1->get()->getIdx() << std::endl;
      //std::cout << "Found: " << it2->get()->getIdx() << std::endl;

      it2->get()->addVizinho(*(it1));
      it1->get()->addVizinho(*(it2));

   } else {
      std::cout << "Not found!" << std::endl;
   }

}


