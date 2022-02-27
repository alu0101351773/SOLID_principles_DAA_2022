#ifndef TMATRIX
#define TMATRIX

/**
 * @file daa_1.cc
 * @author Jorge Cabrera (alu0101351773@ull.edu.es)
 * @brief program to compare the performance of two algorithms
 * @version 0.2
 * @date 2022-02-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>
#include <iostream>


class IntMatrix {
public:
    IntMatrix(const int& i_size = 1, const int& j_size = 1);
    ~IntMatrix();

    void Resize(const int& new_i_size = 1, const int& new_j_size = 1);

    const int get_rows(void);
    const int get_cols(void);

    int& at(const int& i, const int& j);

private:
    int rows_size_;
    int cols_size_;
    std::vector<std::vector<int>> inner_vector_;
};


IntMatrix::IntMatrix(const int& i_size, const int& j_size) {
    Resize(i_size, j_size);
}


IntMatrix::~IntMatrix() {

}


void
IntMatrix::Resize(const int& new_i_size, const int& new_j_size) {
    rows_size_ = new_i_size;
    cols_size_ = new_j_size;
    inner_vector_.resize(rows_size_);
    for (int i = 0; i < rows_size_; ++i) {
        inner_vector_[i].resize(cols_size_);
    }
}


const int
IntMatrix::get_rows(void) { return rows_size_; }


const int
IntMatrix::get_cols(void) { return cols_size_; }


int&
IntMatrix::at(const int& i, const int& j) {
    return inner_vector_[i][j];
}

#endif