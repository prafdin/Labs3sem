#include <gmock/gmock.h>

#include "c_straight_lines.h"
#include "cpp_straight_lines.h"

using namespace c;

namespace c {
	namespace tests {

		TEST(calculate_angle, zero) {
			RightLine first(0, 0, 0);
			RightLine second(0, 0, 0);

			auto result = calculate_angle(first, second);
			ASSERT_EQ(0, result);
		}

		TEST(calculate_angle, positive) {
			RightLine first(3, 2, 1);
			RightLine second(4, 8, 2);
			auto result = calculate_angle(first, second);
			ASSERT_GT(result, 0);
		}

		TEST(calculate_angle, negative) {
			RightLine first(4, 8, 2);
			RightLine second(3, 2, 1);

			auto result = calculate_angle(first, second);
			ASSERT_LT(result, 0);
		}

		TEST(calculate_angle, gag) {
			RightLine first(4, 8, 2);
			RightLine second(3, 2, 1);

			auto result = calculate_angle(first, second);
			ASSERT_LT(result, 0);
		}

		TEST(calculate_angle, P3) {

			ASSERT_LT(-5, 0);
		}

		TEST(calculate_angle, f9g) {

			ASSERT_LT(-1, 0);
		}

	}
}

int main(int argc, char** argv) {

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}