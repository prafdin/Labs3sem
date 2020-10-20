#pragma once
#include "cmath"
const double PI = 3.14159265;
namespace cpp
{
	class Point
	{
		double m_x;
		double m_y;
	public:
		Point(double x, double y) : m_x(x), m_y(y) {}
		~Point() {};
		const double& get_x() const { return m_x; }
		const double& get_y() const { return m_y; }
	};
	class RightLine
	{
		Point m_point;
		double m_c;
		double m_k;
	public:
		RightLine(double a, double b, double  c) : m_point(a, b), m_c(c), m_k(-a / b) {}
		~RightLine() {};
		const double& a()  const { return  m_point.get_x(); }
		const double& b() const { return m_point.get_y(); }
		const double& c()  const { return m_c; }
		double calculate_angle(const RightLine& tmp) const
		{
			return (atan((tmp.m_k - this->m_k) / (1 + this->m_k * tmp.m_k)) * 180.0 / PI);
		}
		bool points_on_defferent_sides(const Point& a, const Point& b) const;
		Point decussation_lines(const RightLine& tmp) const;
	};
}
