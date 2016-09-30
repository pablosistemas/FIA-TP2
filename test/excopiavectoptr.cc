/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <memory>

class Test {
private:
   int t;

public:
   // testar mais rapidamente
   std::vector<std::weak_ptr<Test>> vizinhos;

   Test(int tt) : t(tt) {}
   void addVizinho(std::shared_ptr<Test> &);
   int getT() { return t; }
   friend std::ostream& operator<<(std::ostream &os, Test &t);
};

std::ostream& operator<<(std::ostream &os, Test &t) {
   os << t.getT() << "\nVizinhos:\n";
   for(auto ptr : t.vizinhos){
      os << ptr.lock().get()->getT() << " ";   
   }
   os << std::endl;
   return os;
}

void Test::addVizinho(std::shared_ptr<Test> &t) {
   vizinhos.push_back(t);
}

int main() {
   /*std::vector<int> t;

   t.resize(5);

   std::ostream_iterator<int> it( std::cout," ");
   copy(t.begin(),t.end(),it);
   t[0] = 1;
   t[1] = 1;
   t[2] = 1;
   t[3] = 0;
   
   auto it = std::find(t.begin(), t.end(), 0);
   std::cout << "Found: " << *it << " at:" << it - t.begin() << std::endl;*/

   std::function<void(Test *)> destroy = [](Test *t) {
      std::cout << "deleting\n";
      delete t;
   };
   
   std::vector<std::shared_ptr<Test>> t;

   /*t.push_back(std::make_shared<Test> (3));
   t.push_back(std::make_shared<Test> (2));
   t.push_back(std::make_shared<Test> (5));
   t.push_back(std::make_shared<Test> (7));
   t.push_back(std::make_shared<Test> (0));*/

   std::shared_ptr<Test> t1 (new Test(3), destroy);

   t.push_back(t1);

   std::shared_ptr<Test> t2 (new Test(1), destroy);

   t.push_back(t2);

   std::shared_ptr<Test> t3 (new Test(11), destroy);

   t.push_back(t3);

   std::shared_ptr<Test> t4 (new Test(2), destroy);

   t.push_back(t4);

   std::shared_ptr<Test> t5 (new Test(8), destroy);

   t.push_back(t5);

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

   std::vector<std::shared_ptr<Test> >::const_iterator it;
   for(it = t.begin(); it != t.end(); it++)
      std::cout << *(it->get()) << std::endl;

   std::cout << "Copiando vector\n";
   std::cout << "Imprimindo a copia:\n";
   std::vector<std::shared_ptr<Test>> tt(t);

   for(it = tt.begin(); it != tt.end(); it++)
      std::cout << *(it->get()) << std::endl;


}
