#pragma once

namespace c
{
	struct RightLine
	{
		double a, b, c;
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
