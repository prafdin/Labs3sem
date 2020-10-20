
#include "c_right_lines.h"
#include "math.h"
const float PI = 3.14159f;
using namespace c;
double c::calculate_angle(RightLine first, RightLine second)
{
	double k1, k2;
	if (first.b)
		k1 = -((first.a) / (first.b));
	else k1 = 0;
	if (second.b)
		k2 = -((second.a) / (second.b));
	else k2 = 0;
	return (atan((k2 - k1) / (1 + k1 * k2)) * 180.0 / PI);
}
RightLine c::create_line(Point a)
{
	RightLine tmp;
	tmp.a = a.x;
	tmp.b = a.y;
	tmp.c = 0;
	return  tmp;
}
bool c::points_on_defferent_sides(RightLine main_line, Point a, Point b)
{
	RightLine first = create_line(a);
	RightLine second = create_line(b);
	double angle_1 = calculate_angle(main_line, first);
	double angle_2 = calculate_angle(main_line, second);
	if ((angle_1 > 0 && angle_2 < 0) || (angle_1 < 0 && angle_2>0))
		return true;
	else
		return false;
}
Point system_kramer(RightLine vector_1, RightLine vector_2)
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
		return system_kramer(first, second);
}