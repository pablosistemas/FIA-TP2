#ifndef __CGRAFOSBI_H_INCLUDED__
#define __CGRAFOSBI_H_INCLUDED__

#include "genericGraph.h"
#include "cnodosBI.h"
#include <vector>
#include <cinttypes>

class GrafoBI : public GenericGraph {
protected:
   std::vector<std::shared_ptr<NodoBI>> nodos;
public:

   GrafoBI();
   GrafoBI(char *);
   GrafoBI(const GrafoBI &);

   std::vector<std::shared_ptr<NodoBI>>::iterator getBegin();
   std::vector<std::shared_ptr<NodoBI>>::iterator getEnd();

   size_t getSize() const;

   /* DEBUG */
   void imprimeGrafo() const;

   void leDoArquivo(char *);

   void callAddVizinho(uint32_t, uint32_t);

   void insertInNodos(std::shared_ptr<NodoBI> &);

   void setGraphNumConflicts();

   uint32_t getGraphNumConflicts() const;
};

#endif
