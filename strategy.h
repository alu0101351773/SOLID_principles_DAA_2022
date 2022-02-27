/**
 * @file strategy.h
 * @author Jorge Cabrera (alu0101351773@ull.edu.es)
 * @brief program to implement different matrix-multiplicaction algorithms
 * @version 1.1
 * @date 2022-02-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STRATEGY
#define STRATEGY

#include "IntMatrix.h"

// The 'Strategy' abstract class
class Strategy {
    public: 
	virtual IntMatrix AlgorithmInterface(IntMatrix a, IntMatrix b) = 0;
};


// Class to multiply by rows
class MultiplyByRows : public Strategy  {
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
class MultiplyByCols : public Strategy  {
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

#endif