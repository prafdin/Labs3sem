#pragma once

namespace c
{
	struct RightLine
	{
		double a, b, c;

		RightLine(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
	};
	struct Point
	{
		double x;
		double y;
	};
	double calculate_angle(RightLine first, RightLine second);
	bool points_on_different_sides(RightLine main_line, Point a, Point b);
	Point decussation_lines(RightLine first, RightLine second);
	void print_point(Point point);
}
