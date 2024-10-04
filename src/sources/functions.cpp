#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = true;

  if ((this->rows_ == other.rows_) && (this->cols_ == other.cols_)) {
    for (int i = 0; (i < this->rows_) && result; ++i) {
      for (int j = 0; (j < this->cols_) && result; ++j)
        result = this->matrix_[i][j] == other.matrix_[i][j];
    }
  } else
    result = false;

  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if ((this->rows_ == other.rows_) && (this->cols_ == other.cols_)) {
    for (int i = 0; i < this->rows_; ++i) {
      for (int j = 0; j < this->cols_; ++j)
        this->matrix_[i][j] += other.matrix_[i][j];
    }
  } else {
    throw std::invalid_argument(
        "sizes of the matrices is not equal to each other");
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if ((this->rows_ == other.rows_) && (this->cols_ == other.cols_)) {
    for (int i = 0; i < this->rows_; ++i) {
      for (int j = 0; j < this->cols_; ++j)
        this->matrix_[i][j] -= other.matrix_[i][j];
    }
  } else {
    throw std::invalid_argument(
        "sizes of the matrices is not equal to each other");
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) this->matrix_[i][j] *= num;
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (this->cols_ != other.rows_)
    throw std::invalid_argument(
        "number of columns in the first matrix is not equal to number of "
        "rows in the second matrix");

  double** new_matrix = new double*[this->rows_];
  for (int i = 0; i < this->rows_; ++i) new_matrix[i] = new double[other.cols_];

  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      new_matrix[i][j] = 0;
      for (int k = 0; k < this->cols_; k++) {
        new_matrix[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  for (int i = 0; i < this->rows_; ++i) {
    delete[] this->matrix_[i];
  }
  delete[] this->matrix_;

  this->matrix_ = new_matrix;
  this->cols_ = other.cols_;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix temp(this->cols_, this->rows_);

  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      temp.matrix_[j][i] = this->matrix_[i][j];
    }
  }

  return temp;
}

S21Matrix S21Matrix::CalcComplements() {
  if (this->rows_ != this->cols_)
    throw std::invalid_argument("matrix is not square shaped");

  S21Matrix temp(this->rows_, this->rows_);

  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      temp.matrix_[i][j] = s21_complement(this, i, j);
    }
  }

  return temp;
}

double S21Matrix::s21_complement(S21Matrix* A, int row, int column) {
  double det = 0;

  if (A->rows_ == 1)
    det = A->matrix_[0][0];
  else {
    S21Matrix minor(A->rows_ - 1, A->rows_ - 1);

    int counter_rows = 0;
    for (int i = 0; i < A->rows_; ++i) {  // строки
      int counter_columns = 0;
      for (int j = 0; j < A->rows_; ++j) {  // столбцы
        if ((i == row) || (j == column)) continue;

        minor.matrix_[counter_rows][counter_columns] = A->matrix_[i][j];
        counter_columns++;
      }

      if (i != row) counter_rows++;
    }

    det = minor.Determinant();
    // s21_determinant(&minor, &det);
    // printf("determinant: %f\n", det);

    det = ((row + column) % 2 == 1) ? -1 * det : det;
  }

  return det;
}

double S21Matrix::Determinant() {
  double result = 0;

  if (this->rows_ != this->cols_)
    throw std::invalid_argument("matrix is not square shaped");
  else if (this->rows_ == 1)
    result = this->matrix_[0][0];
  else if (this->rows_ == 2) {
    result = this->matrix_[0][0] * this->matrix_[1][1] -
             this->matrix_[0][1] * this->matrix_[1][0];
  } else {
    for (int i = 0; i < this->cols_; i++) {
      S21Matrix minor(this->rows_ - 1, this->rows_ - 1);

      for (int j = 1; j < this->rows_; j++) {
        int k = 0;
        for (int col = 0; col < this->cols_; col++) {
          if (col != i) {
            minor.matrix_[j - 1][k] = this->matrix_[j][col];
            k++;
          }
        }
      }

      double minor_det = minor.Determinant();

      result += (i % 2 == 0 ? 1 : -1) * this->matrix_[0][i] * minor_det;
    }
  }

  return result;
}