#include<stdio.h>
#include "c_right_lines.h"
#include "math.h"
using namespace c;

float radian_to_degrees(float radin)
{
	const float PI = 3.14159f;
	const float RightAngle = 90.0f;
	return (radin * 2 * RightAngle / PI);
}
double c::calculate_angle(RightLine first, RightLine second)
{
	double k1=0, k2=0;
	if (first.b != 0)
		k1 = -((first.a) / (first.b));
	if (second.b != 0)
		k2 = -((second.a) / (second.b));
	return ((double)radian_to_degrees((float)atan((k2 - k1) / (1 + k1 * k2))));
}
RightLine create_line(Point a)
{
	RightLine tmp;
	tmp.a = a.x;
	tmp.b = a.y;
	tmp.c = 0;
	return  tmp;
}
bool c::points_on_defferent_sides(RightLine main_line, Point first_point, Point second_point)
{
	RightLine first_line = create_line(first_point);
	RightLine second_line = create_line(second_point);
	double angle_1 = calculate_angle(main_line, first_line);
	double angle_2 = calculate_angle(main_line, second_line);
	if ((angle_1 > 0 && angle_2 < 0) || (angle_1 < 0 && angle_2>0))
		return true;
	else
		return false;
}
Point find_solution_system(RightLine vector_1, RightLine vector_2)
{
	Point a;
	double dx = vector_1.c * vector_2.b - vector_2.c * vector_1.b;
	double dy = vector_1.a * vector_2.c - vector_2.a * vector_1.c;
	double d = vector_1.a * vector_2.b - vector_1.b * vector_2.a;
	a.x = dx / d;
	a.y = dy / d;
	return a;
}
Point c::decussation_lines(RightLine first, RightLine second)
{
	Point tmp;
	tmp.x = NULL;
	tmp.y = NULL;
	if (calculate_angle(first, second) == 0)
		return tmp;
	else
		return find_solution_system(first, second);
}
void c::print_point(Point point) {
	printf("x=%lf y=%lf\n", point.x, point.y);
}