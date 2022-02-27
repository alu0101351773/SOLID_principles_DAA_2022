#include "IntMatrix.h"
#include <iostream>
#include <stdlib.h>


int main(void) {
   IntMatrix random_matrix(3, 7);
   for (size_t i = 0; i < random_matrix.rows_size(); i++) {
      for (size_t j = 0; j < random_matrix.cols_size(); j++) {
         random_matrix.at(i, j) = (rand() % 20);
         std::cout << random_matrix.at(i, j) << "\t";
      }
      std::cout << "\n";
   }
}


