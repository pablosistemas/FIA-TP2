#ifndef __CGRAFOSDSATUR_H_INCLUDED__
#define __CGRAFOSDSATUR_H_INCLUDED__

#include "cnodosDSatur.h"
#include "genericGraph.h"
#include <set>
#include <cinttypes>

class GrafoDSatur : public GenericGraph {
private:
   std::multiset<std::shared_ptr<NodoDSatur>,fncomp> nodos;

public:
   GrafoDSatur();
   GrafoDSatur(char *);
   ~GrafoDSatur();

   std::multiset<std::shared_ptr<NodoDSatur>,fncomp>::iterator getBegin();
   std::multiset<std::shared_ptr<NodoDSatur>,fncomp>::iterator getEnd();

   void updateSatur();

   size_t getSize() const;

   void leDoArquivo(char *);

   /* DEBUG */
   void imprimeGrafo() const;

   void callAddVizinho(uint32_t, uint32_t);

   void insertInNodos(std::shared_ptr<NodoDSatur>&);
};

#endif
