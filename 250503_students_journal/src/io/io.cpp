#include "io.hpp"

#include <iostream>

int biv::print_db_data(void* notused, int col_count, char** columns, char** col_names) {
	const char* format = " | ";
    for (int i = 0; i < col_count; i++) {
		if (columns[i]) {
			std::cout 
				<< columns[i++] 
				<< format
				<< "Год поступления: " << columns[i++]
				<< format
				<< "Группа: " << columns[i];
		}
    }
	std::cout << std::endl;
	return 0;
}
