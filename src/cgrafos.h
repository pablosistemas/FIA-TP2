#ifndef __CGRAFOS_H_INCLUDED__
#define __CGRAFOS_H_INCLUDED__

#include "cnodos.h"
#include "genericGraph.h"
#include <vector>
#include <cinttypes>

class Grafo : public GenericGraph {
protected:
   std::vector<std::shared_ptr<Nodo>> nodos;
   uint32_t numConflicts;
   uint32_t numColors;

public:
   Grafo();
   Grafo(char *);
   Grafo(const Grafo &);
   ~Grafo();

   std::vector<std::shared_ptr<Nodo>>::iterator getBegin();
   std::vector<std::shared_ptr<Nodo>>::iterator getEnd();

   size_t getSize() const;
   uint32_t getGraphNumConflicts() const;
   uint32_t getNumColors() const;
   std::vector<std::shared_ptr<Nodo>> getNodos() const;

   void setGraphNumConflicts();
   void setNumColors();

   /* DEBUG */
   void imprimeGrafo() const;

   void leDoArquivo(char *);

   void callAddVizinho(uint32_t, uint32_t);

   void insertInNodos(std::shared_ptr<Nodo> &);
};

#endif
