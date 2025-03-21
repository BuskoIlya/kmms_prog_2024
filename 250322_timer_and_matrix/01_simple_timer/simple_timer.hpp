#pragma once

#include <chrono>

namespace biv {
	using clock = std::chrono::high_resolution_clock;
	using microseconds = std::chrono::microseconds;
	
	class SimpleTimer {
		private:
			const clock::time_point start;
			
		public:
			SimpleTimer() : start(clock::now()) {}
			
			SimpleTimer(const SimpleTimer&) = delete;
			SimpleTimer(SimpleTimer&&) = delete;
			SimpleTimer& operator = (const SimpleTimer&) = delete;
			SimpleTimer& operator = (SimpleTimer&&) = delete;
			
			~SimpleTimer() {
				const auto end = clock::now();
				const auto count = 
					std::chrono::duration_cast<microseconds>(end - start).count();
				std::cout << count << " microseconds" << std::endl;
			}
	};
}
