#include "matrix.hpp"

#include <iostream>

using biv::Matrix;

Matrix::Matrix(const int size) : Matrix(size, size) {}

Matrix::Matrix(const int rows, const int columns) : rows(rows), columns(columns) {
	data = new int*[rows];
	for (int i = 0; i < rows; i++) {
		data[i] = new int[columns];
	}
	generate_default_data();
}

Matrix::Matrix(const Matrix& m) {
	rows = m.rows;
	columns = m.rows;
	
	data = new int*[rows];
	for (int i = 0; i < rows; i++) {
		data[i] = new int[columns];
	}
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			data[i][j] = m.data[i][j];
		}
	}
}

Matrix::Matrix(Matrix&& m) {
	rows = m.rows;
	columns = m.rows;
	data = m.data;
	m.data = nullptr;
}

Matrix::~Matrix() {
	rows = 0;
	columns = 0;
	if (data) {
		for (int i = 0; i < rows; i++) {
			delete [] data[i];
		}
		delete [] data;
		data = nullptr;
	}
}

Matrix& Matrix::operator = (const Matrix& m) {
	if (this == &m) return *this;
	
	std::cout << "Matrix::operator =" << std::endl;
	
	rows = m.rows;
	columns = m.rows;
	
	if (data) {
		for (int i = 0; i < rows; i++) {
			delete [] data[i];
		}
		delete [] data;
		data = nullptr;
	}
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			data[i][j] = m.data[i][j];
		}
	}
	
	return *this;
}

Matrix& Matrix::operator = (Matrix&& m) {
	rows = m.rows;
	columns = m.rows;
	
	if (data) {
		for (int i = 0; i < rows; i++) {
			delete [] data[i];
		}
		delete [] data;
	}
	
	data = m.data;
	m.data = nullptr;
	
	return *this;
}

Matrix Matrix::operator + (const Matrix& m) const {
	std::cout << "Matrix::operator +" << std::endl;
	
	Matrix result(rows, m.columns);
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < m.columns; j++) {
			result.data[i][j] = data[i][j] + m.data[i][j];
		}
	}
	
	return result;
}

Matrix Matrix::operator * (const Matrix& m) const {
	std::cout << "Matrix::operator *" << std::endl;
	
	Matrix result(rows, m.columns);
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < m.columns; j++) {
			for (int k = 0; k < columns; k++) {
				result.data[i][j] += data[i][k] * m.data[k][j];
			}
		}
	}
	
	return result;
}

int Matrix::get_element(const int row, const int column) const {
	// throw exception if row >= rows or column >= columns
	return data[row][column];
}

bool Matrix::set_element(const int row, const int column, const int value) {
	// throw exception if row >= rows or column >= columns
	bool result = true;
	
	if (row < rows && column < columns) {
		data[row][column] = value;
	} else {
		result = false;
	}
	
	return result;
}

// ----------------------------------------------------------------------------
// 									PRIVATE
// ----------------------------------------------------------------------------
void Matrix::generate_default_data() noexcept {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			data[i][j] = 0;
		}
	}
}
