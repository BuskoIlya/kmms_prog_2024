#pragma once

#include <cstddef>

namespace biv {
	class Matrix {
		protected:
			int rows = 0;
			int columns = 0;
			int** data = nullptr;
			
		public:
			Matrix() = default;
			Matrix(const int size);
			Matrix(const int rows, const int columns);
			Matrix(const Matrix&);
			Matrix(Matrix&&);
			
			~Matrix();
			
			Matrix& operator = (const Matrix&);
			Matrix& operator = (Matrix&&);
			
			Matrix operator + (const Matrix&) const;
			virtual Matrix operator * (const Matrix&) const;
			
			int get_columns() const noexcept { return columns; }
			int get_element(const int row, const int column) const;
			int get_rows() const noexcept { return rows; }
			bool set_element(const int row, const int column, const int value);
			
		private:
			void generate_default_data() noexcept;
	};
}
