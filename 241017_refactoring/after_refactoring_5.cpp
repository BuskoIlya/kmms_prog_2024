#include <iostream>

int main() { 
	int day;
	std::cout << "Введите номер дня в месяце: ";
	std::cin >> day;
	
	int month;
	std::cout << "Введите номер месяца: ";
	std::cin >> month;

	int year;
	std::cout << "Введите номер года: ";
	std::cin >> year;

	int centure_year = year % 100;
	int century = year / 100;
	
	int week_day_number = (
		day 
		+ (13 * month - 1) / 5 
		+ 2
		+ centure_year 
		+ centure_year / 4 
		+ century / 4 
		- 2 * century 
		) % 7;
	
	switch(week_day_number) {
		case 0: 
			std::cout << "Воскресенье" << std::endl;
			break;
		case 1: 
			std::cout << "Понедельник" << std::endl;
			break;
		case 2: 
			std::cout << "Вторник" << std::endl;
			break;
		case 3: 
			std::cout << "Среда" << std::endl;
			break;
		case 4: 
			std::cout << "Четверг" << std::endl;
			break;
		case 5: 
			std::cout << "Пятница" << std::endl;
			break;
		case 6: 
			std::cout << "Суббота" << std::endl;
			break;
	}

	return 0;
}
