#include <cstdlib>
#include <iostream>

void print_array(
	const char* const comment, 
	const int* const arr, 
	const int arr_size);

int main() {
	const int arr_size = 20;
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % arr_size;
    }
	
	print_array("Сгенерированный массив:", arr, arr_size);
	
    for (int i = 0; i < arr_size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arr_size - 1 - i];
        arr[arr_size - 1 - i] = temp;
    }
	
	print_array("Массив после преобразования \"наоборот\":", arr, arr_size);

    return 0;
}

void print_array(
	const char* const comment, 
	const int* const arr, 
	const int arr_size
) {
	std::cout << comment << std::endl;
	static const char format = ' ';
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << format;
    }
    std::cout << std::endl;
}
