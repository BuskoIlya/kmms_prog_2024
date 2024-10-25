#include <iostream>

void bubble_sort(int* const arr, const int size);
void print_array(const char* const comment, int* arr, const int size);

int main() {
    int arr[] = {1, 8, 2, 5, 3, 11};
	const int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	print_array("Массив до сортировки:", arr, arr_size);
    
    bubble_sort(arr, arr_size);

    print_array("Массив после сортировки:", arr, arr_size);

    return 0;
}

void bubble_sort(int* const arr, const int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int x = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = x;
            }
        }
    }
}

void print_array(const char* const comment, int* arr, const int size) {
	const char format = ' ';
	std::cout << comment;
	for (int i = 0; i < size; i++) {
		std::cout << format << arr[i];
	}
	std::cout << std::endl;
}
