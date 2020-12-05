#pragma once
#include <iostream>
#include<cmath>
class OneVaribleFunction {
public:
	virtual OneVaribleFunction derivative() = 0;
	virtual double value(double argument) = 0;
	virtual bool equals(const OneVaribleFunction& rhs) = 0;
	virtual void print(std::ostream stream) = 0;
	virtual ~OneVaribleFunction() = 0;
};

class ConstantFunction :public OneVaribleFunction {
	double coefficient;
public:
	ConstantFunction(double coefficient):coefficient(coefficient){}
	OneVaribleFunction derivative() {
		return ConstantFunction(0);
	}
	double value(double argument) {
		return coefficient;
	}
	bool equals(const OneVaribleFunction& rhs) {
		ConstantFunction ptr = dynamic_cast<ConstantFunction*>(&rhs);
		if (ptr != nullptr && *ptr==*this)
			return true;
		else
			return false;
	}
	void print(std::ostream stream) {
		stream << "y(x)=" << coefficient << std::endl;
	}
	bool operator ==(const ConstantFunction& rhs) {
		if (rhs.coefficient == coefficient)
			return true;
		else
			return false;
	}
};
class LineFunction : public OneVaribleFunction {
	double slope;
	double intercept;
public:
	LineFunction(double slope,double intercept):,slope(slope),intercept(intercept){}
	OneVaribleFunction derivative() {
		return ConstantFunction(slope)
	}
	double value(double argument) {
		return slope * argument + intercept;
	}
	bool equals(const OneVaribleFunction& rhs) {
		LineFunction ptr = dynamic_cast<LineFunction*>(&rhs);
		if (ptr != nullptr && *ptr==*this)
			return true;
		else
			return false;

	}
	void print(std::ostream stream) {
		stream << "y(x)=" << slope << "x+"<< intercept <<std::endl;
	}
	bool operator ==(const LineFunction& rhs) {
		if (rhs.slope == slope && rhs.intercept == intercept)
			return true;
		else
			return false;
	}
};
class QuadraticFunction:public OneVaribleFunction {
	double higher_coefficient;
	double second_coefficient;
	double constant_term;
public:
	QuadraticFunction(double higher_coefficient, double second_coefficient, double constant_term):
		higher_coefficient(higher_coefficient),second_coefficient(second_coefficient),constant_term(){}
	OneVaribleFunction derivative() {
		return LineFunction(2 * higher_coefficient, second_coefficient);
	}
	double value(double argument) {
		return higher_coefficient * argument * argument + second_coefficient * argument + constant_term;
	}
	bool equals(const OneVaribleFunction& rhs) {
		QuadraticFunction ptr = dynamic_cast<QuadraticFunction*>(&rhs);
		if (ptr != nullptr && *ptr==*this)
			return true;
		else
			return false;
	}
	void print(std::ostream stream) {
		stream << "y(x)=" << higher_coefficient << "x^2+"<< second_coefficient<<"x+"<< constant_term << std::endl;
	}
	bool operator ==(const QuadraticFunction& rhs) {
		if (rhs.higher_coefficient == higher_coefficient && rhs.second_coefficient == second_coefficient && rhs.constant_term == constant_term)
			return true;
		else
			return false;
	}
};
class SinFunction :public OneVaribleFunction {
	double stretching_coefficient;
	double frequency_coefficient;
	double offset_on_x;
	double offset_on_y;
public:
	SinFunction(double frequency_coefficient, double stretching_coefficient = 1, double offset_on_x = 0, double offset_on_y = 0) :
		stretching_coefficient(frequency_coefficient), frequency_coefficient(frequency_coefficient), offset_on_x(offset_on_x), offset_on_y(offset_on_y) {}
	OneVaribleFunction derivative() {
		return CosFunction(frequency_coefficient,stretching_coefficient*frequency_coefficient, offset_on_x);
	}
	double value(double argument) {
		return stretching_coefficient*sin(frequency_coefficient * argument + offset_on_x)+offset_on_y;
	}
	bool equals(const OneVaribleFunction& rhs) {
		SinFunction ptr = dynamic_cast<SinFunction*>(&rhs);
		if (ptr != nullptr && *ptr==*this)
			return true;
		else
			return false;
	}
	void print(std::ostream stream) {
		stream << "y(x)=";
		if (stretching_coefficient != 1)
			stream << stretching_coefficient;
		stream << "sin(";
		if (frequency_coefficient != 1)
			stream << "frequency_coefficient";
		stream << "x";
		if (offset_on_x != 0)
			stream << "+" << offset_on_x;
		stream << ")";
		if (offset_on_y != 0)
			stream << "+" << offset_on_y << std::endl;
	} 
	bool operator ==(const SinFunction& rhs) {
		if (rhs.stretching_coefficient == stretching_coefficient && rhs.frequency_coefficient == frequency_coefficient &&
			rhs.offset_on_x == offset_on_x && rhs.offset_on_y == offset_on_y)
			return true;
		else
			return false;
	}
};
class CosFunction :public OneVaribleFunction {
	double stretching_coefficient;
	double frequency_coefficient;
	double offset_on_x;
	double offset_on_y;
public:
	CosFunction(double frequency_coefficient, double stretching_coefficient = 1, double offset_on_x = 0, double offset_on_y = 0) :
		stretching_coefficient(frequency_coefficient), frequency_coefficient(frequency_coefficient), offset_on_x(offset_on_x), offset_on_y(offset_on_y) {}
	OneVaribleFunction derivative() {
		return SinFunction(-frequency_coefficient, -stretching_coefficient * frequency_coefficient, -offset_on_x);
	}
	double value(double argument) {
		return stretching_coefficient * cos(frequency_coefficient * argument + offset_on_x) + offset_on_y;
	}
	bool equals(const OneVaribleFunction& rhs) {
		CosFunction ptr = dynamic_cast<CosFunction*>(&rhs);
		if (ptr != nullptr && *ptr == *this)
			return true;
		else
			return false;
	}
	void print(std::ostream stream) {
		stream << "y(x)=";
		if (stretching_coefficient != 1)
			stream << stretching_coefficient;
		stream << "cos(";
		if (frequency_coefficient != 1)
			stream << "frequency_coefficient";
		stream << "x";
		if (offset_on_x != 0)
			stream << "+" << offset_on_x;
		stream << ")";
		if (offset_on_y != 0)
			stream << "+" << offset_on_y << std::endl;
	}
	bool operator ==(const CosFunction& rhs) {
		if (rhs.stretching_coefficient == stretching_coefficient && rhs.frequency_coefficient == frequency_coefficient &&
			rhs.offset_on_x == offset_on_x && rhs.offset_on_y == offset_on_y)
			return true;
		else
			return false;
	}
};

