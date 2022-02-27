// Strategy pattern -- Structural example

#include <iostream>
#include "IntMatrix.h"


// The 'Strategy' abstract class
class Strategy {
    public: 
	virtual IntMatrix AlgorithmInterface(IntMatrix a, IntMatrix b) = 0;
};


// Class to multiply by rows
class ConcreteStrategyA : public Strategy  {
    IntMatrix AlgorithmInterface(IntMatrix a, IntMatrix b) {
        IntMatrix result(a.get_rows(), b.get_cols());

        for (int i = 0; i < result.get_rows(); ++i) {
            for (int j = 0; j < result.get_cols(); ++j) {
                result.at(i, j) = 0;
                for (int k = 0; k < a.get_cols(); ++k) {
                    result.at(i, j) += (a.at(i, k) * b.at(k, j));
                }
            }
        }
        return result;
    }
};

 
// Class to multiply by cols
class ConcreteStrategyB : public Strategy  {
    IntMatrix AlgorithmInterface(IntMatrix a, IntMatrix b) {
        IntMatrix result(a.get_rows(), b.get_cols());
        
        for (int i = 0; i < result.get_cols(); ++i) {
            for (int j = 0; j < result.get_rows(); ++j) {
                result.at(j, i) = 0;

                for (int k = 0; k < b.get_rows(); ++k) {
                    result.at(j, i) += (b.at(k, i) * a.at(j, k));
                }
            }
        }
        return result;
    }
};


// The 'Context' class
class Context {
    private:
	 Strategy *_strategy;
    public:
        // Constructor
        Context(Strategy *strategy) {
            _strategy = strategy;
        }
 
        IntMatrix ContextInterface(IntMatrix a, IntMatrix b) {
           return _strategy -> AlgorithmInterface(a, b);
        }

};


void GenerateRandomValues(IntMatrix& original_matrix) {
    for (int i = 0; i < original_matrix.get_rows(); ++i) {
        for (int j = 0; j < original_matrix.get_cols(); ++j) {
            original_matrix.at(i, j) = (rand() % 10);
        }
    }
}


void PrintMatrix(IntMatrix original_matrix) {
    for (int i = 0; i < original_matrix.get_rows(); ++i) {
        for (int j = 0; j < original_matrix.get_cols(); ++j) {
            std::cout << original_matrix.at(i, j) << " ";
        }
        std::cout << "\n";
    }
}

int main(void) {
    srand(2022);
    IntMatrix prueba1(2, 3), prueba2(3, 2), resultado(2, 2);
    GenerateRandomValues(prueba1);
    GenerateRandomValues(prueba2);

    PrintMatrix(prueba1);
    PrintMatrix(prueba2);

    Context *context_a, *context_b;

    context_a = new Context(new ConcreteStrategyA());
    PrintMatrix(context_a->ContextInterface(prueba1, prueba2));	// Salida de la interfaz A

    std::cout << "\n";

    context_b = new Context(new ConcreteStrategyB());
    PrintMatrix(context_b->ContextInterface(prueba1, prueba2));	// Salida de la interfaz A

    return 0;
}