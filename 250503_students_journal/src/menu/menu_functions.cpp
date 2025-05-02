#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

#include "io.hpp"
#include "students_db.hpp"

using biv::MenuItem;

// ----------------------------------------------------------------------------
// Общие функции
// ----------------------------------------------------------------------------
const MenuItem* biv::exit(const MenuItem* current) {
    std::exit(0);
}

const MenuItem* biv::go_back(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const MenuItem* biv::show_menu(const MenuItem* current) {
    std::cout << "Журнал студентов: у меня всё записано!" << std::endl;
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    
	std::cout << "Журнал студентов > ";
    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

// ----------------------------------------------------------------------------
// Функции, привязанные к соответствующим элементам меню
// ----------------------------------------------------------------------------
const MenuItem* biv::add_student(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const MenuItem* biv::look_at_students(const MenuItem* current) {
    std::cout << "Журнал студентов > Список всех студентов: " << std::endl;
	StudentsDB::get_instance().get_students_data(biv::print_db_data);
	std::cout << std::endl;
    return current->parent;
}
