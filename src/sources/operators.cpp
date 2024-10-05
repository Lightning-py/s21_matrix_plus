#include "../s21_matrix_oop.h"

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    if (matrix_ != nullptr) {
      for (int i = 0; i < rows_; ++i) {
        delete[] matrix_[i];
      }
      delete[] matrix_;
    }

    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = new double[cols_];
    }

    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }

  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& arg) {
  this->SumMatrix(arg);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& arg) {
  this->SubMatrix(arg);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& arg) {
  this->MulMatrix(arg);
  return *this;
}

S21Matrix& S21Matrix::operator*=(double arg) {
  this->MulNumber(arg);
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& arg) const {
  S21Matrix result = *this;
  result += arg;
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& arg) const {
  S21Matrix result = *this;
  result -= arg;

  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& arg) const {
  S21Matrix result = *this;
  result *= arg;

  return result;
}

S21Matrix S21Matrix::operator*(double arg) const {
  S21Matrix result = *this;
  result *= arg;

  return result;
}

bool S21Matrix::operator==(const S21Matrix& arg) const {
  return this->EqMatrix(arg);
}

bool S21Matrix::operator!=(const S21Matrix& arg) const {
  return !(*this == arg);
}
