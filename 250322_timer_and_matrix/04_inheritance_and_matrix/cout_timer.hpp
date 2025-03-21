#pragma once

#include <iostream>

#include "timer.hpp"

namespace biv {
	class CoutTimer : public Timer {
		public:
			~CoutTimer() override {
				std::cout << "CoutTimer: ";
				
				const auto end = clock::now();
				const auto count = 
					std::chrono::duration_cast<microseconds>(end - start).count();
				std::cout << count << " микросекунд" << std::endl;
			}
	};
}
