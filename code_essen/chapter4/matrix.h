//
// Created by Siyuan Cheng on 2022/4/24.
//

#ifndef INC_50_CPP_MATRIX_H
#define INC_50_CPP_MATRIX_H

class Matrix{
public:
    Matrix(int row, int col): _row(row), _col(col) {
        _pmat = new double[row * col];
    }
    Matrix( const Matrix &rhs): _row(rhs._row), _col(rhs._col) {
        int ele_cnt = _row*_col;
        _pmat = new double[_row*_col];

        for (int i = 0; i < ele_cnt; ++i) {
            _pmat[i] = rhs._pmat[i];
        }
    }

    ~Matrix()
    {
        delete [] _pmat;
    }

private:
    int _row, _col;
    double* _pmat;
};

#endif //INC_50_CPP_MATRIX_H
