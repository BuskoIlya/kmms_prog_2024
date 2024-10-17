#include <iostream>

int main() {
	const int arr_size = 10;
    int arr[arr_size];
	std::cout << "Надо ввести массив из 10-и элементов." << std::endl;
    for (int i = 0; i < arr_size; i++) {
        std::cout << "Введите " << i + 1 << "-ый элемент: ";
        std::cin >> arr[i];
    }
	
    int is_increasing = true;
    int i = 0;
    while (i < arr_size - 1) {
        if (arr[i] > arr[i + 1]) {
            is_increasing = false;
			break;
		}
        i++;
    }
	
    if (is_increasing) {
        std::cout << "Последовательность возрастающая." << std::endl;
    } else {
        std::cout << "Последовательность не возрастающая." << std::endl;
    }

    return 0;
}
