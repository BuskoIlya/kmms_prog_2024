#pragma once

#include <sqlite3.h>
#include <string>

namespace biv {
	class StudentsDB {
		private:
			static const char* db_name;
			sqlite3* db;
			int connection_status = SQLITE_ERROR;
			
			static StudentsDB* instance;
			
			StudentsDB();
			~StudentsDB();
		public:
			static StudentsDB& get_instance() {
				if (instance == nullptr) {
					instance = new StudentsDB();
				}
				return *instance;
			};
			
			StudentsDB(const StudentsDB&) = delete;
			StudentsDB& operator = (const StudentsDB&) = delete;
			
			void close();
			void get_students_data(
				int (*callback) (
					void* notused, 
					int col_count, 
					char** columns, 
					char** col_names
				)
			);
			bool is_open_connection() const;
	};
}
