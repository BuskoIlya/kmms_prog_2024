#include <iostream>
#include <string>
#include <vector>

void count_numbers(
	const int n, 
	const int m, 
	std::string number, 
	int& count
);

void count_palindromes(
	const int n, 
	const int d, 
	std::vector<int> vec, 
	int& count
);

namespace IBusko {
	void quick_sort(int arr[], int l, int r);
	void swap(int& x, int& y);
}

void decomposite_in_terms(
	const int n,
	std::vector<int> vec, 
	int summ_rest, 
	int& count
);

void decomposite_in_k_terms(
	const int n,
	const int k,
	std::vector<int> vec, 
	int summ_rest, 
	int& count
);

int main() {
	{
		// Найти количество и вывести на экран все n-значные числа, 
		// у которых сумма цифр в m раз меньше их произведения.
		const int n = 4;
		const int m = 10;
		std::string number;
		int count = 0;
		count_numbers(n, m, number, count);
		std::cout << "Количество чисел = " << count << std::endl;
	}
	{
		std::cout << std::endl;
		// Найти количество и вывести на экран все n-значные 
		// полиндромы, у которых сумма цифр делится на d.
		const int n = 5;
		const int d = 7;
		std::vector<int> vec(n, -1);
		int count = 0;
		count_palindromes(n, d, vec, count);
		std::cout << "Количество палиндромов = " << count << std::endl;	
	}
	{
		std::cout << std::endl;
		// Написать быструю сортировку.
		int arr[] = {3, 12, 4, 0, 6, -2, -6, 11, 3, 5, 8};
		const int size = sizeof(arr) / sizeof(arr[0]);
		IBusko::quick_sort(arr, 0, size - 1);
		for(int i = 0; i < size; i++) {
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		// Найти количество и вывести все варианты разложения числа n 
		// на слагаемые. Разложение отличающееся перестановкой не учитывается.
		std::vector<int> terms;
		const int n = 10;
		int count = 0;
		std::cout 
			<< "Разложение числа " 
			<< n 
			<< " на слагаемые имеет варианты: " 
			<< std::endl;
		decomposite_in_terms(n, terms, n, count);
		std::cout << "Количество вариантов = " << count << std::endl;
	}
	{
		std::cout << std::endl;
		// Найти количество и вывести все варианты рзложения числа n 
		// на k слагаемых. Разложение отличающееся перестановкой не учитывается.
		std::vector<int> terms;
		const int n = 10;
		const int k = 3;
		int count = 0;
		std::cout 
			<< "Разложение числа " 
			<< n 
			<< " на " 
			<< k
			<< " слагаемых имеет варианты: " 
			<< std::endl;
		decomposite_in_k_terms(n, k, terms, n, count);
		std::cout << "Количество вариантов = " << count << std::endl;
	}
	
	return 0;
}

void count_numbers(
	const int n, 
	const int m, 
	std::string number, 
	int& count
) {
	const char zero = '0';
	if (number.size() == n) {
		int summ = 0;
		int multiply = 1;
		for (int i = 0; i < n; i++) {
			summ += number[i] - zero;
			multiply *= number[i] - zero;
		}
		if (multiply / summ == m && multiply % summ == 0) {
			count++;
			std::cout << number << std::endl;
		}
		return;
	}
	
	const int digits_count = 10;
	for (int i = 0; i < digits_count; i++) {
		if (number.size() == 0 && i == 0) {
			continue;
		}
		number += char(i + zero);
		count_numbers(n, m, number, count);
		number.pop_back();
	}
}

void count_palindromes(
	const int n, 
	const int d, 
	std::vector<int> vec, 
	int& count
) {
    if (n <= 0) {
        int summ = 0;
        for (int x: vec) {
            summ += x;
        }
        if (summ % d == 0){
            for (int x: vec) {
				std::cout << x;
            }
            std::cout << std::endl;
            count++;
        }
		return;
    }
    
	for (int i = 0; i < 10; i++) {
        vec[(vec.size() - n) / 2] = i;
        vec[(vec.size() + n) / 2 - 1] = i;
        if (vec[0] == 0) {
            continue;
        }
        count_palindromes(n - 2, d, vec, count);
    }
}

namespace IBusko {
	void quick_sort(int arr[], int l, int r) {
		if (l >= r) return;
		
		int x = arr[(l + r) / 2];
		int i = l; 
		int j = r;
		while (i <= j) {
			while (arr[i] < x) {
				i++;
			}
			while (arr[j] > x) {
				j--;
			}
			if (i <= j) {
				swap(arr[i++], arr[j--]);
			}
		}
		
		quick_sort(arr, l, j);
		quick_sort(arr, i, r);
	}

	void swap(int& x, int& y) {
		int temp = x;
		x = y;
		y = temp;
	}
}

void decomposite_in_terms(
	const int n,
	std::vector<int> vec, 
	int summ_rest, 
	int& count
) {
	if (summ_rest == 0) {
		count++;
		std::cout << n << " = ";
		for (int i = 0; i < vec.size() - 1; i++) {
			std::cout << vec[i] << " + ";
		}
		std::cout << vec[vec.size() - 1] << std::endl;
		return;
	}

	for (int i = 1; i <= summ_rest; i++) {
		if (vec.empty()) {
			vec.push_back(i);
			decomposite_in_terms(n, vec, summ_rest - i, count);
			vec.clear();
		} else if (vec[vec.size() - 1] >= i) {
			vec.push_back(i);
			decomposite_in_terms(n, vec, summ_rest - i, count);
			vec.pop_back();
		}
	}
}

void decomposite_in_k_terms(
	const int n,
	const int k,
	std::vector<int> vec, 
	int summ_rest, 
	int& count
) {
	if (vec.size() > k || (summ_rest == 0 && vec.size() < k)) return;

	if (summ_rest == 0 && vec.size() == k) {
		count++;
		std::cout << n << " = ";
		for (int i = 0; i < vec.size() - 1; i++) {
			std::cout << vec[i] << " + ";
		}
		std::cout << vec[vec.size() - 1] << std::endl;
		return;
	}

	for (int i = 1; i <= summ_rest; i++) {
		if (vec.empty()) {
			vec.push_back(i);
			decomposite_in_k_terms(n, k, vec, summ_rest - i, count);
			vec.clear();
		} else if (vec[vec.size() - 1] >= i) {
			vec.push_back(i);
			decomposite_in_k_terms(n, k, vec, summ_rest - i, count);
			vec.pop_back();
		}
	}
}
