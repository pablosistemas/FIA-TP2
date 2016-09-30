/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include <iostream>
#include <vector>
#include <inttypes.h>

class Teste {
private:
   uint32_t a;
   uint32_t b;

public:
   Teste() : a(0), b(0) {}
   Teste(uint32_t, uint32_t=0);
   uint32_t getA() const { return a;}
   uint32_t getB() const { return b;}

   friend std::ostream& operator<<(std::ostream&,const Teste &);
};

class Temp {
   std::vector<Teste> temp;

public:

   Temp (uint32_t size) {
      temp.resize(size);
   }
   
   void print();
};

void Temp::print() {
   std::vector<Teste>::iterator it;
   for(it = this->temp.begin(); it != this->temp.end(); it++) {
      std::cout << (*it);
      //std::cout << it->getA() << " " << it->getB() << std::endl;
   }
}

Teste::Teste(uint32_t a1, uint32_t b1) : a(a1), b(b1) {}

std::ostream& operator<<(std::ostream &os, const Teste &t) {
   std::cout << "a: " << t.getA() << " b: " << t.getB() << std::endl;
   return os;
}

int main() {
   Temp ttemp (10);
   ttemp.print();

   return 0;
}
