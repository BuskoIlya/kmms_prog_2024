#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"
#include "menu_items.hpp"
#include "students_db.hpp"

int main() {
    const biv::MenuItem* current = &biv::MAIN;

	try {
		do {
			current = current->func(current);
		} while (true);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		biv::StudentsDB::get_instance().close();
	}
}
