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
	RightLine create_line(Point a);
	bool points_on_defferent_sides(RightLine main_line, Point a, Point b);
	Point decussation_lines(RightLine first, RightLine second);
}
