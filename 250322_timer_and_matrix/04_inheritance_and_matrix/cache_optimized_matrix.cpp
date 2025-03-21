#include "cache_optimized_matrix.hpp"

#include <iostream>

using biv::CacheOptimizedMatrix;
using biv::Matrix;

Matrix CacheOptimizedMatrix::operator * (const Matrix& m) const {
	std::cout << "CacheOptimizedMatrix::operator *" << std::endl;
	
	CacheOptimizedMatrix result(rows, m.get_columns());
	
    for (int i = 0; i < rows; i++) {
        for (int k = 0; k < columns; k++) {
            int ik_data = data[i][k];
            for (int j = 0; j < m.get_columns(); j++) {
                result.data[i][j] += ik_data * m.get_element(k, j);
			}
        }
	}
	
	return result;
}
