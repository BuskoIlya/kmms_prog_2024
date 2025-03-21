#pragma once

#include <chrono>
#include <iostream>

namespace biv {
	using clock = std::chrono::high_resolution_clock;
	using microseconds = std::chrono::microseconds;
	
	class Timer {
		protected:
			const clock::time_point start;
		public:
			Timer() : start(clock::now()) {}
			virtual ~Timer() {std::cout << "~Timer()" << std::endl;}
	};
}
