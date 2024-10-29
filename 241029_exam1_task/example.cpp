#include <cstdlib>
#include <iostream>

int main() {
	std::cout << "Введите размер массива: ";
	int arr_size;
	std::cin >> arr_size;
	
	int* arr = new int[arr_size];
	for (int i = 0; i < arr_size; i++) {
		arr[i] = rand() % arr_size;
	}
	
	std::cout << "Сгенерированный массив: ";
	const char format = ' ';
	for (int i = 0; i < arr_size; i++) {
		std::cout << arr[i] << format;
	}
	std::endl;
	
	int summ = 0;
	for (int i = 0; i < arr_size; i++) {
		summ += arr[i];
	}
	
	double average = double(summ) / arr_size;
	std::cout 
		<< "Среднее арифметическое равно " 
		<< average
		<< std::endl;
		
	delete[] arr;
}
