#include <ctime>
#include <iostream>
#include <thread>

#include "callback_timer.hpp"
#include "cout_timer.hpp"

void print_time(biv::clock::time_point start, biv::clock::time_point end);

int main() {
	using namespace std::chrono_literals;
	{
		biv::CoutTimer timer = biv::CoutTimer();
		std::this_thread::sleep_for(500ms);
		std::cout << "Задержка окончена" << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		//biv::Timer* timer = new biv::CallbackTimer(print_time);
		
		biv::Timer timer = biv::CallbackTimer(print_time);
		std::this_thread::sleep_for(500ms);
		std::cout << "Задержка окончена" << std::endl;
		
		//delete timer;
	}
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
