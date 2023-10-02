#include <iostream>

using namespace std;

template<class T>
class Matrix
{
    int rows;
    int cols;
    T** cont;
public:
    Matrix();
    ~Matrix();
    Matrix<T> operator+(const Matrix<T>&)
};


int main()
{
    std::cout << "Hello World!\n";
}

template<class T>
Matrix<T>::Matrix()
{
    rows = 0;
    cols = 0;
    cont = nullptr;
}

template<class T>
Matrix<T>::Matrix(int r, int c)
{
    rows = r;
    cols = c;
    cont = new T * [rows];  

    for (int i = 0; i < rows; i++) {
        cont[i] = new T[cols]; 
    }
}

template<class T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < rows; i++) {
        delete[] cont[i];
    }
    delete[] cont;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& b)
{
    if (this->rows != b.rows || this->cols != b.cols)
    {
        cout << "Error: matrices must have the same number of rows and the same number of columns.";
        return;
    }
    Matrix<T> temp(this->rows, this->cols)
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; i < cols; i++)
        {
            temp.cont[i][j] = this->cont[i][j] + b.cont[i][j];
        }
    }
}
