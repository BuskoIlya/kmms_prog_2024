#include <cstdlib>
#include <iostream>

double calculate_average(const int* const arr, const int size);
void generate_array(int* const arr, const int size);
void print_array(const int* const arr, const int size);

int main() {
	const int arr_count = 3;
	
	for (int i = 0; i < arr_count; i++) {
		const int arr_size = 10;
		int arr[arr_size];
		
		generate_array(arr, arr_size);
		
		std::cout << "Последовательность номер " << i + 1 << ": " << std::endl;
		print_array(arr, arr_size);
		
		std::cout 
			<< "Среднее значение равно " 
			<< calculate_average(arr, arr_size) 
			<< std::endl 
			<< std::endl;
	}

    return 0;
}

double calculate_average(const int* const arr, const int size) {
	int summ = 0;
	for (int i = 0; i < size; i++) {
		summ += arr[i];
	}
	return double(summ) / size;
}

void generate_array(int* const arr, const int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % size;
	}
}

void print_array(const int* const arr, const int size) {
	const char format = ' ';
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << format;
	}
	std::cout << std::endl;
}
