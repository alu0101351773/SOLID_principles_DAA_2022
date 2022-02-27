/**
 * @file main.cc
 * @author Jorge Cabrera (alu0101351773@ull.edu.es)
 * @brief Main program of the project
 * @version 1.1
 * @date 2022-02-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <stdlib.h>

#include "IntMatrix.h"
#include "strategy.h"
#include "context.h"

int main(int argc, char* argv[]) {
    srand(2022);

    int a = atoi(argv[1]), b = atoi(argv[2]), c = atoi(argv[3]);

    IntMatrix prueba1(a, b), prueba2(b, c);
    GenerateRandomValues(prueba1);
    GenerateRandomValues(prueba2);

    Context *context_a, *context_b;

    context_a = new Context(new MultiplyByRows());
    context_b = new Context(new MultiplyByCols());

    std::cout << "Multiplication by rows:\n";
    context_a->ContextInterface(prueba1, prueba2);

    std::cout << "\nMultiplication by columns:\n";
    context_b->ContextInterface(prueba1, prueba2);

    return 0;
}