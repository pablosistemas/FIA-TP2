/* ***************************************************************** */
/*                                                                   */
/* Filename:                                                         */
/* By: Pablo Goulart Silva <pablogoulart13@gmail.com>                */
/*                                                                   */
/* ***************************************************************** */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
   std::fstream in;
   in.open( argv[1], std::ios::in );
   
   std::vector array;

   std::string linha;

   std::getline (in, linha);

   while(!in.eof()){
      std::istringstream inbuf(linha);
      std::getline (in, linha);
      in >> tok >> tipo >>
      arrapy.push_back();
   }

   return 0;
}
