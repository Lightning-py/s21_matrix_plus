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

    bool EqMatrix(const S21Matrix& other) const;

    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);

    double* operator[](int index);
    double& operator()(int row, int col);
    S21Matrix& operator+=(const S21Matrix& rhs);
    S21Matrix& operator-=(const S21Matrix& rhs);
    S21Matrix& operator*=(const S21Matrix& rhs);
    S21Matrix& operator*=(double rhs);
    S21Matrix operator+(const S21Matrix& rhs) const;
    S21Matrix operator-(const S21Matrix& rhs) const;
    S21Matrix operator*(const S21Matrix& rhs) const;
    S21Matrix operator*(double rhs) const;
    bool operator==(const S21Matrix& rhs) const;
    bool operator!=(const S21Matrix& rhs) const;

    S21Matrix Transpose() const;
    double Determinant() const;
    S21Matrix CalcComplements() const;
    double s21_complement(const S21Matrix* A, int row, int column) const;
    S21Matrix& operator=(S21Matrix&& other);
    S21Matrix& operator=(const S21Matrix& other);

    bool isValid();

    ~S21Matrix();
};