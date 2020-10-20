#include "cpp_right_lines.h"
#include "math.h"
using namespace cpp;
bool RightLine::points_on_defferent_sides(const Point& a, const Point& b) const
{
	double k1 = (-a.get_x() / a.get_y());
	double k2 = (-b.get_x() / b.get_y());
	if (((k1 > this->m_k) && (k2 < this->m_k)) || ((k1 < this->m_k) && (k2 > this->m_k)))
		return true;
	else
		return false;
}
Point system_kramer(const RightLine& vector_1, const RightLine& vector_2)
{

	double dx = vector_1.a() * vector_2.b() - vector_2.c() * vector_1.b();
	double dy = vector_1.a() * vector_2.c() - vector_2.a() * vector_1.c();
	double d = vector_1.a() * vector_2.b() - vector_1.b() * vector_2.a();
	Point a((dx / d), (dy / d));
	return a;

}
Point RightLine::decussation_lines(const RightLine& line) const
{
	Point tmp(NAN,NAN);
	if (calculate_angle(line) == 0)
		return tmp;
	else
		return system_kramer(*this, line);
}
