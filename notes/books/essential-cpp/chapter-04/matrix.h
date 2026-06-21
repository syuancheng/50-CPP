//
// Created by Siyuan Cheng on 2022/4/24.
//

#ifndef INC_50_CPP_MATRIX_H
#define INC_50_CPP_MATRIX_H

#include <cstddef>
#include <stdexcept>
#include <vector>

class Matrix {
public:
    Matrix(std::size_t rows, std::size_t cols)
        : rows_(rows), cols_(cols), data_(rows * cols, 0.0) {
        if (rows == 0 || cols == 0) {
            throw std::invalid_argument("matrix dimensions must be positive");
        }
    }

    double& at(std::size_t row, std::size_t col) {
        check_index(row, col);
        return data_[row * cols_ + col];
    }

    const double& at(std::size_t row, std::size_t col) const {
        check_index(row, col);
        return data_[row * cols_ + col];
    }

    std::size_t rows() const noexcept { return rows_; }
    std::size_t cols() const noexcept { return cols_; }

private:
    void check_index(std::size_t row, std::size_t col) const {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("matrix index out of range");
        }
    }

    std::size_t rows_;
    std::size_t cols_;
    std::vector<double> data_;
};

#endif //INC_50_CPP_MATRIX_H
