#include "students_db.hpp"

#include <cstddef>
#include <cstdio>
#include <exception>
#include <iostream>
#include <stdexcept>

using biv::StudentsDB;

const char* StudentsDB::db_name = "students_journal.db";
StudentsDB* StudentsDB::instance = nullptr;

StudentsDB::StudentsDB() {}
StudentsDB::~StudentsDB() {}

void StudentsDB::close() {
	if (is_open_connection()) {
		connection_status = SQLITE_ERROR;
		sqlite3_close(db);
	}
}

void StudentsDB::get_students_data(
	int (*callback) (void* notused, int col_count, char** columns, char** col_names)
) {
	const char* sql = 
		"SELECT name || \" \" || family || \" \" || father as full_name, "
		"start_year, \"group\" FROM students";
	char* err_msg = 0;
	
	connection_status = sqlite3_open(db_name, &db);
	int result = sqlite3_exec(db, sql, callback, 0, &err_msg);
    if (result != SQLITE_OK ) {
        throw std::runtime_error(err_msg);
    }
	close();
}

bool StudentsDB::is_open_connection() const {
	return connection_status == SQLITE_OK;
}
