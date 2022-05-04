//mingw32-make
//Ng, Pei Aou Wilson 100332292


#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>


using namespace std;


class Matrix{
    public:
        //Creating matrix from file specified
        Matrix(const string &filename);
        //Creating a matrix and initialise the matrix to be size row * column
        Matrix(int row, int column);
        //Operator for matrix multiplication
        Matrix operator *(const Matrix &M2);
        //Operator for scalar multiplication
        Matrix operator *(const int s);
        //Operator for matrix subtraction
        Matrix operator -(const Matrix &M2);
        //Operator for matrix addition
        Matrix operator +(const Matrix &M2);
        //Operator for comparing matrix
        bool operator ==(const Matrix &M2);
        //Operator to get matrix.at(i)
        int*& operator [](int i);
        //Operator to print matrix
        ~Matrix();
        Matrix(const Matrix &M2);
        const Matrix& operator =(const Matrix& M2);
        friend ostream& operator <<(ostream &out, Matrix M);


    private:
        int** matrix;
        int row;
        int column;

};

//Creating a matrix and initialise the matrix to be size row * column
Matrix::Matrix(int r, int c) {
    row = r;
    column = c;
    matrix = new int*[row];
    for(int i = 0; i < row; i++) {
        matrix[i] = new int[column];
    }
}

//Creating matrix from file specified
Matrix::Matrix(const string &filename) {
    ifstream in;
    int c;
    in.open(filename);
    if(in.is_open()) {
        in >> row;
        in >> column;
        matrix = new int*[row];
        for(int i = 0; i < row; i++) {
            matrix[i] = new int[column]; 
            for(int j = 0; j < column; j++) {
                in >> c;
                matrix[i][j] = c;
            }
        }
        in.close();
    }
    else {
        cout << "The file specified does not exists" << endl;
        exit(0);
    }
}


Matrix::Matrix(const Matrix &M2) {
    if(M2.matrix) {
        matrix = new int*[M2.row];
        for(int i = 0; i < M2.row; i++) {
            matrix[i] = new int[M2.column];
            for(int j = 0; j < M2.column; j++) {
                matrix[i][j] = M2.matrix[i][j];
            }
        }
    }
    row = M2.row;
    column = M2.column;
    cout << "COPY" << endl;
}


//Operator to get matrix.at(i)
int*& Matrix::operator [](int i) {
    return matrix[i];
}


//Operator for matrix multiplication
Matrix Matrix::operator *(const Matrix &M2) {
    if(column != M2.row) {
        return Matrix(0, 0);
    }
    Matrix M = Matrix(row, M2.column);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < M2.column; j++) {
            M.matrix[i][j] = 0;
            for(int k = 0; k < column; k++) {
                M.matrix[i][j] += matrix[i][k] * M2.matrix[k][j];
            }
        }
    }
    return M;
}

//Operator for scalar multiplication
Matrix Matrix::operator *(const int s) {
    Matrix M = Matrix(row, column);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            M.matrix[i][j] = matrix[i][j] * s;
        }
    }
    return M;
}

//Operator for matrix subtraction
Matrix Matrix::operator -(const Matrix &M2) {
    if(row != M2.row || column != M2.column) {
        return Matrix(0, 0);
    }
    Matrix M = Matrix(row, column);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            M.matrix[i][j] = matrix[i][j] - M2.matrix[i][j];
        }
    }
    return M;
}

//Operator for matrix addition
Matrix Matrix::operator +(const Matrix &M2) {
    if(row != M2.row || column != M2.column) {
        return Matrix(0, 0);
    }
    Matrix M = Matrix(row, column);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            M.matrix[i][j] = matrix[i][j] + M2.matrix[i][j];
        }
    }
    return M;
}


//Operator for comparing matrices
bool Matrix::operator ==(const Matrix &M2) {
    if(row != M2.row || column != M2.column) {
        return false;
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            if(matrix[i][j] != M2.matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}


const Matrix& Matrix::operator =(const Matrix &M2){
    if(&M2 == this) {
        cout << "ASSIGNMENT" << endl;
        return *this;
    }
    for(int i = 0; i < row; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
    matrix = new int*[M2.row];
    for(int i = 0; i < M2.row; i++) {
        matrix[i] = new int[M2.column];
        for(int j =0; j < M2.column; j++) {
            matrix[i][j] = M2.matrix[i][j];
        }
    }
    row = M2.row;
    column = M2.column;
    cout << "ASSIGNMENT" << endl;
    return *this;
}


Matrix::~Matrix() {
    if(matrix) {
        for(int i = 0; i < row; i++) {
            delete [] matrix[i];
        }
    }
    delete [] matrix;
    cout << "DELETE" << endl;
}


//Operator to print out matrices
ostream& operator <<(ostream &out, Matrix M) {
    if(M.row == 0 && M.column == 0) {
        out << "Empty" << endl;
        return out;
    }
    for(int i = 0; i < M.row; i++) {
        for(int j = 0; j < M.column; j++) {
             out << setw(3) << M.matrix[i][j] << " " ;
        }
        out << endl;
    }
    out << endl; 
    return out;  
}

#endif
