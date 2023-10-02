#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "A.h"

using namespace std;

template<class T>
class Matrix
{
    int rows;
    int cols;
    T** cont;
public:
    static int count;
    Matrix();
    Matrix(int, int);
    Matrix(Matrix&);
    ~Matrix();

    void print();
    void randomize();
    static int getCount();

    T max();
    T min();

    Matrix operator+(const Matrix<T>&);
    Matrix operator+(T);
    Matrix operator-(const Matrix<T>&);
    Matrix operator-(T);

    Matrix operator*(T);
    Matrix operator/(T);
};


int main()
{
    std::cout << "Hello World!\n";
    Matrix<int> m1(2, 2);
    m1.randomize();
    m1.print();
    cout << endl;

    Matrix<int> m2(2, 2);
    m2.randomize();
    m2.print();
    cout << endl;

    Matrix<int> m3(2, 5);
    m3.randomize();
    m3.print();
    cout << endl;

    (m1 + m2).print();
    cout << endl;

    (m1 * 2).print();
    int x = 3;
    (m1 * x).print();
    
    Matrix<A> mA(2, 3);
    (mA).print();

    cout << Matrix<int>::getCount();
    cout << endl;
    cout << Matrix<A>::getCount();
}

template<class T>
int Matrix<T>::count = 0;

template<class T>
Matrix<T>::Matrix()
{
    rows = 0;
    cols = 0;
    cont = nullptr;
    count++;
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
    count++;
}

template<class T>
Matrix<T>::Matrix(Matrix& b)
{
    for (int i = 0; i < rows; i++) {
        delete[] cont[i];
    }
    delete[] cont;

    rows = b.rows;
    cols = b.cols;
    cont = new T * [rows];

    for (int i = 0; i < rows; i++) {
        cont[i] = new T[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cont[i][j] = b.cont[i][j];
        }
    }
    count++;
}

template<class T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < rows; i++) {
        delete[] cont[i];
    }
    delete[] cont;
    count--;
}

template<class T>
void Matrix<T>::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << " " << cont[i][j];
        }
        cout << endl;
    }
}

template<class T>
void Matrix<T>::randomize()
{
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cont[i][j] = rand() % 100;
        }
    }
}

template<class T>
int Matrix<T>::getCount()
{
    return count;
}

template<class T>
T Matrix<T>::max()
{
    T max = cont[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (cont[i][j] > max)
            {
                max = cont[i][j];
            }
        }
    }
    return max;
}

template<class T>
T Matrix<T>::min()
{
    T min = cont[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (cont[i][j] > max)
            {
                min = cont[i][j];
            }
        }
    }
    return min;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& b)
{
    if (this->rows != b.rows || this->cols != b.cols)
    {
        Matrix<T> x;
        return x;
    }
    Matrix<T> temp(*this);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.cont[i][j] += b.cont[i][j];
        }
    }
    return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator+(T b)
{
    Matrix<T> temp(*this);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.cont[i][j] += b;
        }
    }
    return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& b)
{
    if (this->rows != b.rows || this->cols != b.cols)
    {
        Matrix<T> x;
        return x;
    }
    Matrix<T> temp(*this);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.cont[i][j] -= b.cont[i][j];
        }
    }
    return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator-(T b)
{
    Matrix<T> temp(*this);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.cont[i][j] -= b;
        }
    }
    return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator*(T b)
{
    Matrix<T> temp(*this);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.cont[i][j] *= b;
        }
    }
    return temp;
}

template<class T>
Matrix<T> Matrix<T>::operator/(T b)
{
    Matrix<T> temp(*this);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.cont[i][j] /= b;
        }
    }
    return temp;
}
