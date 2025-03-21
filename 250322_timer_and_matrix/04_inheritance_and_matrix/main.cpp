#include <iostream>

#include "cache_optimized_matrix.hpp"
#include "cout_timer.hpp"
#include "matrix.hpp"
#include "timer.hpp"

int main() {
	{
		std::cout << "КпоУ: объявлен или не объявлен как default" << std::endl;
		biv::Matrix m1, m2;
		biv::CacheOptimizedMatrix com1, com2;
		
		std::cout << m1.get_rows() << std::endl;
		std::cout << com1.get_rows() << std::endl;
		
		m1 = m2;
		com1 = com2;
	}
	
	const int size = 100;
	{
		std::cout << std::endl;
		std::cout << "Наследование сложения" << std::endl;
		biv::CacheOptimizedMatrix com1(size), com2(size);
		
		biv::CoutTimer cout_timer;
		com1 + com2;
	}
	{
		std::cout << std::endl;
		std::cout << "Умножение как в обычной алгебре" << std::endl;
		biv::Matrix m1(size), m2(size);
		
		biv::CoutTimer cout_timer;
		m1 * m2;
	}
	{
		std::cout << std::endl;
		std::cout << "Умножение с учётом особенностей работы кэш памяти" << std::endl;
		biv::CacheOptimizedMatrix com1(size), com2(size);
		
		biv::CoutTimer cout_timer;
		com1 * com2;
	}
	{
		std::cout << std::endl;
		std::cout << "Динамическое связывание вызывает правильное умножение" << std::endl;
		biv::Matrix* com1 = new biv::CacheOptimizedMatrix(size);
		biv::Matrix* com2 = new biv::CacheOptimizedMatrix(size);
		
		biv::CoutTimer cout_timer;
		*com1 * *com2;
	}
}
