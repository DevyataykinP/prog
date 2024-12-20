#include <iostream>
#include <ctime>

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

int main(){
    srand(time(0));
    int size = rand() % 10;
    int maxValue = 100;
    int *arr = genRandArray(size, maxValue);
    print(arr);
    delete[] arr;
}
