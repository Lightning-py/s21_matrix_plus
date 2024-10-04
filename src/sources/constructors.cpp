#include "../s21_matrix_oop.hpp"

double* S21Matrix::operator[](int index) { return this->matrix_[index]; }

S21Matrix::S21Matrix() {
  this->rows_ = 0;
  this->cols_ = 0;
  this->matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows_, int cols_) {
  if ((rows_ < 1) || (cols_ < 1))
    throw std::invalid_argument("rows or columns less than zero");

  // -- allocate new memory
  double** matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]();
  }

  this->rows_ = rows_;
  this->cols_ = cols_;
  this->matrix_ = matrix_;
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  this->cols_ = other.cols_;
  this->rows_ = other.rows_;
  this->matrix_ = new double*[this->rows_];
  for (int i = 0; i < other.rows_; ++i)
    this->matrix_[i] = new double[this->cols_];
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < this->rows_; ++i) delete[] this->matrix_[i];
  delete[] this->matrix_;
}

int S21Matrix::getRows() const { return this->rows_; }
int S21Matrix::getCols() const { return this->cols_; }

void S21Matrix::setRows(int rows) {
  // memory allocation
  double** new_matrix = new double*[rows];
  for (int i = 0; i < rows; ++i) new_matrix[i] = new double[cols_];

  // filling
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (i < rows_)
        new_matrix[i][j] = this->matrix_[i][j];
      else
        new_matrix[i][j] = 0.0;
    }
  }

  // data updating
  this->setMatrix(new_matrix);
  this->rows_ = rows;
}

void S21Matrix::setCols(int cols) {
  // memory allocation
  double** new_matrix = new double*[rows_];
  for (int i = 0; i < rows_; ++i) new_matrix[i] = new double[cols];

  // filling
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (j < cols_)
        new_matrix[i][j] = this->matrix_[i][j];
      else
        new_matrix[i][j] = 0.0;
    }
  }

  // updating
  this->setMatrix(new_matrix);
  this->cols_ = cols;
}

double** S21Matrix::getMatrix() const { return this->matrix_; }

void S21Matrix::setMatrix(double** new_matrix) {
  if (this->matrix_ != nullptr) {
    for (int i = 0; i < this->cols_; ++i) delete[] this->matrix_[i];
    delete[] this->matrix_;
  }

  this->matrix_ = new_matrix;
}