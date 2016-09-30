/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include <set>
#include <iostream>
#include <memory>

class Teste {
   
   int x;
   int y;
public:
   Teste (int a, int b) : x(a), y(b) {}
   int getX() const { return x; }
   int getY() const { return y; }
   void setX(int a) {  x = a; }
   void setY(int b) {  y = b; }
   friend std::ostream& operator<<(std::ostream &, Teste &);
};

struct fncomp {
   bool operator()(const std::shared_ptr<Teste> &t1, const std::shared_ptr<Teste> &t2) const {
      return (t1.get()->getX()+t1.get()->getY()) < (t2.get()->getX()+t2.get()->getY());
   }
};

std::ostream& operator<<(std::ostream &stream, Teste &t1) {
   std::cout << "x: " << t1.x << " y: " << t1.y << std::endl; 
   return stream;
}

int main() {
   
   std::function<void(Teste *)> destroy = [](Teste* ptr) { 
      std::cout << "deletando: " << ptr->getX() << " " << ptr->getY() << std::endl;
      delete ptr;
   };

   std::shared_ptr<Teste> t1(new Teste(1,2),destroy);

   std::shared_ptr<Teste> t2(new Teste(2,3),[](Teste *ptr) {
      //std::shared_ptr<Teste> temp = std::dynamic_pointer_cast<Teste>(*ptr);
      //std::cout << "deletando: " << temp.get()->getX() << " " << temp.get->getY() << std::endl;
      std::cout << "deletando: " << ptr->getX() << " " << ptr->getY() << std::endl;
      delete ptr;
   });

   std::shared_ptr<Teste> t3(new Teste(3,4),[](Teste *ptr) {
      std::cout << "deletando: " << ptr->getX() << " " << ptr->getY() << std::endl;
      delete ptr;
   });

   std::set<std::shared_ptr<Teste>,fncomp> conj;

   conj.insert(t1);
   conj.insert(t2);
   conj.insert(t3);

   std::set<std::shared_ptr<Teste>>::iterator it = conj.begin();
   for(; it != conj.end(); it++){
      std::shared_ptr<Teste> temp = std::dynamic_pointer_cast<Teste>(*it);
      std::cout << *(temp.get());
   }

   return 0;
}
