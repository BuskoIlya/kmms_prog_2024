#include <gtest/gtest.h>

#include "vector.hpp"

using biv::Vector;

// Тесты

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
