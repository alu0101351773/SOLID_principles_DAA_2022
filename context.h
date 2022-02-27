/**
 * @file context.h
 * @author Jorge Cabrera (alu0101351773@ull.edu.es)
 * @brief program to manage matrix-multiplication algorithms
 * @version 1.1
 * @date 2022-02-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CONTEXT
#define CONTEXT

#include "strategy.h"
#include "IntMatrix.h"
#include <chrono>

// The 'Context' class
class Context {
    private:
	    Strategy *_strategy;
    public:
        // Constructor
        Context(Strategy *strategy) {
            _strategy = strategy;
        }
 
        void ContextInterface(IntMatrix a, IntMatrix b) {
            std::chrono::time_point<std::chrono::system_clock> start, end;
            std::chrono::duration<double> elapsed_seconds;
            start = std::chrono::system_clock::now();

            _strategy->AlgorithmInterface(a, b);

            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
            
            std::cout << "Elapsed time:\t" << elapsed_seconds.count() << " s.\n";
        }

};

#endif