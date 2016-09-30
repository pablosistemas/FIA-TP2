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
   Test(int tt) :t(tt) {}
   int getT() { return t; }
   friend std::ostream& operator<<(std::ostream &os, Test &t) {
      std::cout << "s: " <<t.getT() << std::endl;
      return os;
   }
};


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

   std::vector<std::shared_ptr<Test>> t;

   /*t.push_back(std::make_shared<Test> (3));
   t.push_back(std::make_shared<Test> (2));
   t.push_back(std::make_shared<Test> (5));
   t.push_back(std::make_shared<Test> (7));
   t.push_back(std::make_shared<Test> (0));*/

   std::shared_ptr<Test> t1 (new Test(3), [](Test *t) {
      std::cout << "deleting\n";
      delete t;
   });

   t.push_back(t1);

   std::shared_ptr<Test> t2 (new Test(1), [](Test *t) {
      std::cout << "deleting\n";
      delete t;
   });

   t.push_back(t2);

   std::shared_ptr<Test> t3 (new Test(11), [](Test *t) {
      std::cout << "deleting\n";
      delete t;
   });

   t.push_back(t3);

   std::shared_ptr<Test> t4 (new Test(2), [](Test *t) {
      std::cout << "deleting\n";
      delete t;
   });

   t.push_back(t4);

   std::shared_ptr<Test> t5 (new Test(8), [](Test *t) {
      std::cout << "deleting\n";
      delete t;
   });

   t.push_back(t5);

   std::vector<std::shared_ptr<Test> >::const_iterator it;
   for(it = t.begin(); it != t.end(); it++)
      std::cout << (*it)->getT() << std::endl;
}
