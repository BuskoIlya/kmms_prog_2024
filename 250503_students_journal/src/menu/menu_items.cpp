#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

using biv::MenuItem;

const MenuItem biv::ADD_STUDENT = {
    "1 - Добавить студента в журнал", biv::add_student, &biv::ENTER_JOURNAL
};
const MenuItem biv::LOOK_AT_STUDENTS = {
    "2 - Посмотреть список всех студентов", biv::look_at_students, &biv::ENTER_JOURNAL
};
const MenuItem biv::BACK_TO_MAIN = {
    "0 - Выйти в главное меню", biv::go_back, &biv::ENTER_JOURNAL
};

namespace {
    const MenuItem* const journal_children[] = {
        &biv::BACK_TO_MAIN,
        &biv::ADD_STUDENT,
        &biv::LOOK_AT_STUDENTS
    };
    const int journal_size = sizeof(journal_children) / sizeof(journal_children[0]);
}

const MenuItem biv::ENTER_JOURNAL = {
    "1 - Войти в журнал", biv::show_menu, &biv::MAIN, journal_children, journal_size
};
const MenuItem biv::EXIT = {
    "0 - Завершить просмотр журнала", biv::exit, &biv::MAIN
};

namespace {
    const MenuItem* const main_children[] = {
        &biv::EXIT,
        &biv::ENTER_JOURNAL
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const MenuItem biv::MAIN = {
    nullptr, biv::show_menu, nullptr, main_children, main_size
};
