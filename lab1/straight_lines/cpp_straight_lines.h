#pragma once
#include "cmath"
#include <stdio.h>
const double PI = 3.14159265;
namespace cpp
{
	class Point
	{
		double m_x;
		double m_y;
	public:

		Point(double x, double y) : m_x(x), m_y(y) {}	
		double get_x() const { return m_x; }
		double get_y() const { return m_y; }
		void print_point() const {
			printf("x=%lf y=%lf\n", m_x, m_y);
		}
	};
	class RightLine
	{
		Point m_point;
		double m_c;
		double m_k;
	public:
		RightLine(double a, double b, double  c) : m_point(a, b), m_c(c) {
			if (b == 0)
				m_k = 0;
			else
				m_k = -a / b;
		}
		double get_a()  const { return  m_point.get_x(); }
		double get_b() const { return m_point.get_y(); }
		const double& get_c()  const { return m_c; }
		const double& get_k()  const { return m_k; }
		double calculate_angle(const RightLine& tmp) const;
		static double calculate_angle(const RightLine& first, const RightLine& second);
		
	};

	bool points_on_defferent_sides(const RightLine& line, const Point& a, const Point& b) ;
	Point decussation_lines(const RightLine& first_line,const RightLine& second_line);
	
	

}
