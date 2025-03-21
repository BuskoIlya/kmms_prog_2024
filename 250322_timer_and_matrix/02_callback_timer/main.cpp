#include <ctime>
#include <iostream>

#include "callback_timer.hpp"

void print_time(biv::clock::time_point start, biv::clock::time_point end);

int main() {
	biv::CallbackTimer timer(print_time);
	for (int i = 0; i < 1'000'000'000; i++) {}
}

void print_time(biv::clock::time_point start, biv::clock::time_point end) {
	std::cout << "CallbackTimer: " << std::endl;
	
	std::time_t start_time = std::chrono::system_clock::to_time_t(start);
	std::cout 
		<< "\t Время начала = " 
		<< std::ctime(&start_time)
		<< std::endl;
	
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout 
		<< "\t Время завершения = " 
		<< std::ctime(&end_time)
		<< std::endl;
	
	const auto count = 
		std::chrono::duration_cast<biv::microseconds>(end - start).count();
	std::cout 
		<< "\t Времени затрачено: " 
		<< count 
		<< " микросекунд" 
		<< std::endl;
}
