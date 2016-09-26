#ifndef __CGRAFOSDSATUR_H_INCLUDED__
#define __CGRAFOSDSATUR_H_INCLUDED__

#include "cnodosDSatur.h"
#include "genericGraph.h"
#include <set>
#include <cinttypes>

class GrafoDSatur : public GenericGraph {
private:
   std::set<std::shared_ptr<NodoDSatur>> nodos;

public:
   GrafoDSatur();
   GrafoDSatur(char *);

   std::set<std::shared_ptr<Nodo>>::iterator getBegin();
   std::set<std::shared_ptr<Nodo>>::iterator getEnd();

   size_t getSize() const;

   void leDoArquivo(char *);

   /* DEBUG */
   void imprimeGrafo() const;
};

#endif
