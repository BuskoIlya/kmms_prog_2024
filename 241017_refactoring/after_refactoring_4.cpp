#include <cmath>
#include <iostream>

int main() {
	double angle;
	std::cout << "Введите угол: ";
	std::cin >> angle;
	
	double result_f1;
	if  (std::cos(2 * angle) != 1) {
		result_f1 = 
			(1 + std::sin(2 * angle)) 
			/ 
			(1 - std::cos(2 * angle));
		std::cout << "F(x1) = " << result_f1 << std::endl;
	} else if (std::cos(2 * angle) == 1) {
		std::cout << "Неверный ввод для F(x1)" << std::endl;
	}
	
	double result_f2;
	if  (std::tan(angle) != 1) {
		result_f2 = 
			(1 + std::tan(angle) * std::tan(angle)) 
			/ 
			(1 - std::tan(angle) * std::tan(angle));
		std::cout << "F(X2) = " << result_f2 << std::endl;
	} else if (std::tan(angle) == 1) {
		std::cout<< "Неверный ввод для F(x2)" << std::endl;
	}

	return 0;
}
