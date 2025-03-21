#include <iostream>

#include "simple_timer.hpp"

int main() {
	biv::SimpleTimer timer;
	for (int i = 0; i < 1'000'000'000; i++) {}
	
	// Ошибка компиляции
	// biv::SimpleTimer timer2(timer); 
}
