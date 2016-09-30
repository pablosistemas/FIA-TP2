/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include "../src/cgrafosBI.h"
#include "../src/cnodosBI.h"
#include <iostream>

int main() {

   GrafoBI *grafo = new GrafoBI();
   
   std::function<void(NodoBI*)> destroy = [](NodoBI *p){
      std::cout << "deleting: " << p << std::endl;
      delete p;  
   };

   std::shared_ptr<NodoBI> t1(new NodoBI(1),destroy);
   std::shared_ptr<NodoBI> t2(new NodoBI(2),destroy);
   std::shared_ptr<NodoBI> t3(new NodoBI(3),destroy);
   std::shared_ptr<NodoBI> t4(new NodoBI(4),destroy);
   std::shared_ptr<NodoBI> t5(new NodoBI(5),destroy);
   
   t1.get()->setColor(3);
   t2.get()->setColor(2);
   t3.get()->setColor(2);
   t4.get()->setColor(4);
   t5.get()->setColor(1);

   t1.get()->addVizinho(t2);
   t1.get()->addVizinho(t3);
   t1.get()->addVizinho(t4);
   t1.get()->addVizinho(t5);

   t2.get()->addVizinho(t1);
   t2.get()->addVizinho(t3);
   t2.get()->addVizinho(t4);
   t2.get()->addVizinho(t5);

   t3.get()->addVizinho(t1);
   t3.get()->addVizinho(t2);
   t3.get()->addVizinho(t4);
   t3.get()->addVizinho(t5);

   t4.get()->addVizinho(t1);
   t4.get()->addVizinho(t2);
   t4.get()->addVizinho(t2);
   t4.get()->addVizinho(t5);

   t5.get()->addVizinho(t1);
   t5.get()->addVizinho(t2);
   t5.get()->addVizinho(t3);
   t5.get()->addVizinho(t4);

   t1.get()->setNodoNumConflicts();
   t2.get()->setNodoNumConflicts();
   t3.get()->setNodoNumConflicts();
   t4.get()->setNodoNumConflicts();
   t5.get()->setNodoNumConflicts();

   grafo->insertInNodos(t1);
   grafo->insertInNodos(t2);
   grafo->insertInNodos(t3);
   grafo->insertInNodos(t4);
   grafo->insertInNodos(t5);

   std::cout << "Creating a new graph\n";
   GrafoBI *grafo2 = new GrafoBI(*grafo);
   
   grafo->imprimeGrafo();
   std::cout << "new graph\n";
   grafo2->imprimeGrafo();

   delete grafo;
   delete grafo2;
}
