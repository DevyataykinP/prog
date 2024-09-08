#include <iostream>
#include <ctime>
#include <cstdlib>

int *genRandArray(int size, int maxValue){
    int *arr = new int[size + 1];
    arr[0] = size;
    for (int i = 1; i <= size;i++){
        arr[i] = rand() % maxValue;
    }
    return arr;
}

void print(int *arr){
    std::cout << arr[0] << ": ";
    for (int i = 1; i <= arr[0]; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int** genRandMatrix(int size, int maxValue){
    int **arr = new int *[size];
    for (int i = 0; i < size; i++){
        arr[i] = genRandArray(rand() % 10, maxValue);
    }
    return arr;
}

void printMatrix(int** matrix,int size){
    for (int i = 0; i < size;i++){
        std::cout << matrix[i][0] << ": ";
        for (int j = 0; j < matrix[i][0] - 1; j++){
            std::cout << matrix[i][j + 1] << " ";
        }
        std::cout << matrix[i][(matrix[i][0] - 1)]<<"\n";
    }
}

int main(){
    srand(time(0));
    int size = rand() % 10;
    std::cout << size << "\n";
    int maxValue = 100;
    int **matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix,size);
}
