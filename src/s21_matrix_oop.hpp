#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows_, int cols_);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  int getRows() const;
  int getCols() const;
  void setRows(int rows);
  void setCols(int cols);
  double** getMatrix() const;
  void setMatrix(double** new_matrix);

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  double* operator[](int index);

  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  double s21_complement(S21Matrix* A, int row, int column);

  bool isValid();

  ~S21Matrix();
};