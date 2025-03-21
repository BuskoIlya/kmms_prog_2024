#pragma once

#include <chrono>

namespace biv {
	using clock = std::chrono::high_resolution_clock;
	using microseconds = std::chrono::microseconds;
	
	class CallbackTimer {
		private:
			void (* callback)(clock::time_point start, clock::time_point end);
			const clock::time_point start;
			
		public:
			CallbackTimer(
				void (* callback)(clock::time_point start, clock::time_point end)
			) : callback(callback), start(clock::now()) {}
			
			CallbackTimer(const CallbackTimer&) = delete;
			CallbackTimer(CallbackTimer&&) = delete;
			CallbackTimer& operator = (const CallbackTimer&) = delete;
			CallbackTimer& operator = (CallbackTimer&&) = delete;
			
			~CallbackTimer() {
				callback(start, clock::now());
			}
	};
}
