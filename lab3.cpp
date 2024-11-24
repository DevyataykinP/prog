#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix {

public:
    int rows;
    int cols;
    vector<vector<int>> data;
    int sum;

    Matrix() : rows(0), cols(0), sum(0) {}

    Matrix(int size) : rows(size), cols(size), sum(0) {
        data.resize(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            data[i][i] = 1;
        }
    }

    Matrix(int r, int c) : rows(r), cols(c), sum(0) {
        data.resize(r, vector<int>(c, 0));
    }

    void input() {
        cout << "Введите " << rows << "x" << cols << " элементов:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    void fillRandom() {
        srand(time(0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = rand() % 100;
            }
        }
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    void calculateSum() {
        sum = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                sum += data[i][j];
            }
        }
        cout << "Sum: "<< sum << endl;
    }

    ~Matrix() {
    }
};

int main() {
    Matrix M1;
    Matrix M2(3);
    Matrix M3(3, 4);
    Matrix M4(2, 3);

    cout << "M2:\n";
    M2.display();

    cout << "M3:\n";
    M3.display();

    cout << "M4:\n";
    M4.display();

    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            M2.data[i-1][j-1] = i * j;
        }
    }
    cout << "M2:\n";
    M2.display();

    cout << "M3:\n";
    M3.fillRandom();
    M3.display();

    M4.input();
    cout << "M4:\n";
    M4.display();

    M3.calculateSum();
}
