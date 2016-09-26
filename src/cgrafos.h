#ifndef __CGRAFOS_H_INCLUDED__
#define __CGRAFOS_H_INCLUDED__

#include "cnodos.h"
#include "genericGraph.h"
#include <vector>
#include <cinttypes>

class Grafo : public GenericGraph {
private:
   std::vector<std::shared_ptr<Nodo>> nodos;

public:
   Grafo();
   Grafo(char *);

   std::vector<std::shared_ptr<Nodo>>::iterator getBegin();
   std::vector<std::shared_ptr<Nodo>>::iterator getEnd();

   size_t getSize() const;

   /* DEBUG */
   void imprimeGrafo() const;

   void leDoArquivo(char *);

   void callAddVizinho(uint32_t, uint32_t);
   void insertInNodos(std::shared_ptr<Nodo> &);
};

#endif
