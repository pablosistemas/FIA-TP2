#ifndef __GENERICGRAPH_H_INCLUDED__
#define __GENERICGRAPH_H_INCLUDED__

#include <cinttypes>
#include <memory>
#include "cnodos.h"

class GenericGraph {
protected:
  // numero de vertices e arestas
   uint32_t V;
   uint32_t E;

public:
   GenericGraph();
   GenericGraph(char *);
   ~GenericGraph();

   uint32_t getV() const;
   uint32_t getE() const;

   virtual size_t getSize() const = 0;

   // virtual void insertInNodos(std::shared_ptr<Nodo>&) = 0;
   virtual void callAddVizinho(uint32_t, uint32_t) = 0;

   /* DEBUG */
   virtual void imprimeGrafo() const = 0;

   virtual void leDoArquivo(char *) = 0;

};

#endif
