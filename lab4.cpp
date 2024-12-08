#include <iostream>

using namespace std;

template <typename T>
class Matrix {
private:
    T** M;
    int m;
    int n;

public:
    Matrix() : M(nullptr), m(0), n(0) {}

    Matrix(int rows, int cols) : m(rows), n(cols) {
        M = new T*[m];
        for (int i = 0; i < m; ++i) {
            M[i] = new T[n];
            for (int j = 0; j < n; ++j) {
                M[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix& other) : m(other.m), n(other.n) {
        M = new T*[m];
        for (int i = 0; i < m; ++i) {
            M[i] = new T[n];
            for (int j = 0; j < n; ++j) {
                M[i][j] = other.M[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            for (int i = 0; i < m; ++i) {
                delete[] M[i];
            }
            delete[] M;

            m = other.m;
            n = other.n;
            M = new T*[m];
            for (int i = 0; i < m; ++i) {
                M[i] = new T[n];
                for (int j = 0; j < n; ++j) {
                    M[i][j] = other.M[i][j];
                }
            }
        }
        return *this;
    }

    void SetM(int row, int col, T value) {
        if (row >= 0 && row < m && col >= 0 && col < n) {
            M[row][col] = value;
        }
    }

    T GetM(int row, int col) const {
        if (row >= 0 && row < m && col >= 0 && col < n) {
            return M[row][col];
        }
        return T();
    }

    void Print(const string& name) const {
        cout << name << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < m; ++i) {
            delete[] M[i];
        }
        delete[] M;
    }
};

int main()
{
    Matrix <int> M(3, 4);
    M.Print("M");

    // Заполнить матрицу значениями по формуле
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            M.SetM(i, j, i + j);
        }
    }

    M.Print("M");

    Matrix < int > M1 = M; // вызов конструктора копирования
    M1.Print("M1");

    Matrix < int > M2;
    M2 = M; // вызов оператора копирования - проверка
    M2.Print("M2");

    Matrix < int > M3;
    M3 = M2 = M1 = M; // вызов оператора копирования в виде "цепочки"
    M3.Print("M3");
}
