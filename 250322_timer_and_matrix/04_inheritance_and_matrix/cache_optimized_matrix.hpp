#pragma once

#include "matrix.hpp"

namespace biv {
	class CacheOptimizedMatrix : public Matrix {
		public:
			CacheOptimizedMatrix() = default;
			CacheOptimizedMatrix(const int size) : Matrix(size) {}
			CacheOptimizedMatrix(const int rows, const int columns) : Matrix(rows, columns) {}
			
			Matrix operator * (const Matrix& x) const override;
	};
}
