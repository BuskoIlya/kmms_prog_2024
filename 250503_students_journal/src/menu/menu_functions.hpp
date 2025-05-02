#pragma once

#include "menu.hpp"

namespace biv {
	// Общие функции
	const MenuItem* exit(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current);
	const MenuItem* show_menu(const MenuItem* current);

	// Функции, привязанные к соответствующим элементам меню
    const MenuItem* add_student(const MenuItem* current);
    const MenuItem* look_at_students(const MenuItem* current);
}
