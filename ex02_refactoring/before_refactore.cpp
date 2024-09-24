#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

void makeinterest(std::vector<int>& A) {
    if (A.size() < 3) return;
    for (size_t i = 2; i < A.size(); ++i) {
        if ((A[i - 2] < A[i - 1] && A[i - 1] < A[i]) || 
            (A[i - 2] > A[i - 1] && A[i - 1] > A[i])) {
            std::swap(A[i - 1], A[i]);
        }
    }
}
int main() {
    
    int n;
    std::cout << "Введите длину массива: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    makeinterest(arr);

    std::cout << "Интересный массив: ";
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
