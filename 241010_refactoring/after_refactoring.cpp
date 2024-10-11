#include <algorithm>
#include <ctime>
#include <iostream>

void print_array(const char* const comment, int* arr, const int size);

int main() {
	int arr_size;
	std::cout << "Введите размер массива: ";
	std::cin >> arr_size;
	
	int* arr = new int[arr_size];
	srand(time(0));
	for (int i = 0; i < arr_size; i++) {
		arr[i] = rand() % 10;
	}
	
	print_array("Был сгенерирован массив:", arr, arr_size);
	
	for (int i = 1; i < arr_size - 1; i++) {
		bool even_condition = !(i % 2 == 0 && arr[i] > arr[i - 1]);
		bool odd_condition = !(i % 2 != 0 && arr[i] < arr[i - 1]);
		if (even_condition && odd_condition) {
			std::swap(arr[i], arr[i - 1]);
		}
	}
	
	print_array("Массив после обработки:", arr, arr_size);
	
	delete[] arr;
}

void print_array(const char* const comment, int* arr, const int size) {
	const char space = ' ';
	std::cout << comment;
	for (int i = 0; i < size; i++) {
		std::cout << space << arr[i];
	}
	std::cout << std::endl;
}
