#include "timer.hpp"

namespace biv {
	class CallbackTimer : public Timer {
		private:
			void (* callback)(clock::time_point start, clock::time_point end);
		
		public:
			CallbackTimer(
				void (* callback)(clock::time_point start, clock::time_point end)
			) : callback(callback) {}
			
			~CallbackTimer() override {
				callback(start, clock::now());
			}
	};
}
