/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

//g++ exfindsetclass.cc  -std=c++11 -o exfind -Wall

#include <set>
#include <iostream>
#include <memory>

class Teste {
   int t;
   int u;

   public:
   Teste(int,int);
   int getT() const;
   int getU() const;

   bool operator<(const Teste &);

   friend std::ostream& operator<< (std::ostream &, const Teste &);
};

struct fncomp {
   bool operator()(const std::shared_ptr<Teste> &t1, const std::shared_ptr<Teste> &t2) const {
      std::cout << *t1.get() << *t2.get();
      return t1.get()->getT() < t2.get()->getT();
   }
};

Teste::Teste(int tt, int uu) : t(tt), u(uu) {}

int Teste::getT() const { return t; }

int Teste::getU() const { return u; }

bool Teste::operator<(const Teste &t1){
   return this->t < t1.getT();
}

std::ostream& operator<< (std::ostream &stream, const Teste &t){
   stream << "t: " << t.getT() << " u: " << t.getU() << std::endl;
   return stream;
}

int main() {
   std::set<std::shared_ptr<Teste>,fncomp> settest;
   std::function<void(Teste *)> destroy = [](Teste *p) {
      std::cout << "deleting p\n";   
      delete p;
   };

   std::shared_ptr<Teste> t1(new Teste(2,3),destroy);
   std::shared_ptr<Teste> t2(new Teste(5,8),destroy);
   std::shared_ptr<Teste> t3(new Teste(1,5),destroy);
   std::shared_ptr<Teste> t4(new Teste(4,5),destroy);
   std::shared_ptr<Teste> t5(new Teste(13,5),destroy);
   
   settest.insert(t1);
   settest.insert(t2);
   settest.insert(t3);
   settest.insert(t4);
   settest.insert(t5);

   std::set<std::shared_ptr<Teste>>::iterator it;

   std::shared_ptr<Teste> te (new Teste(2,3),destroy);
   it = settest.find(te);
   if(it != settest.end()){
      std::cout << "Found: " << *(it->get());
   }

   te.reset (new Teste(5,3),destroy);
   it = settest.find(te);
   if(it != settest.end()){
      std::cout << "Found: " << *(it->get());
   }

   te.reset (new Teste(1,3),destroy);
   it = settest.find(te);
   if(it != settest.end()){
      std::cout << "Found: " << *(it->get());
   }

   te.reset (new Teste(4,3),destroy);
   it = settest.find(te);
   if(it != settest.end()){
      std::cout << "Found: " << *(it->get());
   }

   te.reset (new Teste(13,3),destroy);
   it = settest.find(te);
   if(it != settest.end()){
      std::cout << "Found: " << *(it->get());
   }
}

