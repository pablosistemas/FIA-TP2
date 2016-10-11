#ifndef __CGRAFOSDSATUR_H_INCLUDED__
#define __CGRAFOSDSATUR_H_INCLUDED__

#include "cnodosDSatur.h"
#include "genericGraph.h"
#include <set>
#include <cinttypes>

class GrafoDSatur : public GenericGraph {
private:
   //std::multiset<std::shared_ptr<NodoDSatur>,fncomp> nodos;
   std::vector<std::shared_ptr<NodoDSatur>> nodos;
   uint32_t numConflicts;
   uint32_t numColors;

public:
   GrafoDSatur();
   GrafoDSatur(char *);
   ~GrafoDSatur();

   std::vector<std::shared_ptr<NodoDSatur>>::iterator getBegin();
   std::vector<std::shared_ptr<NodoDSatur>>::iterator getEnd();

   // updates the degree of saturation for every node
   void updateSatur();

   // returns the nodos length: nodos.size()
   size_t getSize() const;

   void leDoArquivo(char *);

   /* DEBUG */
   void imprimeGrafo() const;

   // creates a edge between two nodos
   void callAddVizinho(uint32_t, uint32_t);

   // inserts a nodo into nodos vector
   void insertInNodos(std::shared_ptr<NodoDSatur>&);

   void removeFirstNodo();
   void copyNodos(const std::vector<std::shared_ptr<NodoDSatur>> &);

   void setGraphNumConflicts();
   void setNumColors();

   uint32_t getGraphNumConflicts() const;
   uint32_t getNumColors() const;
};

#endif
