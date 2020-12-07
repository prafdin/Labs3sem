#pragma once
#include <iostream>
#include<cmath>
class OneVaribleFunction {
public:
	virtual OneVaribleFunction* derivative() = 0;
	virtual double value(double argument) = 0;
	virtual bool equals(const OneVaribleFunction& rhs) = 0;
	virtual void print(std::ostream& stream) = 0;
	virtual ~OneVaribleFunction() {}
	};
class ConstantFunction :public OneVaribleFunction {
	double coefficient;
public:
	ConstantFunction(double coefficient):coefficient(coefficient){}
	OneVaribleFunction* derivative() {
		return new ConstantFunction(0);
	}
	double value(double argument) {
		return coefficient;
	}
	bool equals(const OneVaribleFunction& rhs) {
		const ConstantFunction* ptr = dynamic_cast<const ConstantFunction*>(&rhs);
		if (ptr != nullptr && *this == *ptr )
			return true;
		else
			return false;
	}
	void print(std::ostream& stream) {
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
	LineFunction(double slope,double intercept):slope(slope),intercept(intercept){}
	OneVaribleFunction* derivative() {
		return new ConstantFunction(slope);
	}
	double value(double argument) {
		return slope * argument + intercept;
	}
	bool equals(const OneVaribleFunction& rhs) {
		const LineFunction* ptr = dynamic_cast<const LineFunction*>(&rhs);
		if (ptr != nullptr && *this ==*ptr)
			return true;
		else
			return false;

	}
	void print(std::ostream& stream) {
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
	OneVaribleFunction* derivative() {
		return new LineFunction(2 * higher_coefficient, second_coefficient);
	}
	double value(double argument) {
		return higher_coefficient * argument * argument + second_coefficient * argument + constant_term;
	}
	bool equals(const OneVaribleFunction& rhs) {
		const QuadraticFunction *ptr = dynamic_cast<const QuadraticFunction*>(&rhs);
		if (ptr != nullptr && *this ==*ptr)
			return true;
		else
			return false;
	}
	void print(std::ostream& stream) {
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
		stretching_coefficient(stretching_coefficient), frequency_coefficient(frequency_coefficient), offset_on_x(offset_on_x), offset_on_y(offset_on_y) {}
	OneVaribleFunction* derivative();
	double value(double argument) {
		return stretching_coefficient*sin(frequency_coefficient * argument + offset_on_x)+offset_on_y;
	}
	bool equals(const OneVaribleFunction& rhs) {
		const SinFunction *ptr = dynamic_cast<const SinFunction*>(&rhs);
		if (ptr != nullptr && *this ==*ptr)
			return true;
		else
			return false;
	}
	void print(std::ostream& stream) {
		stream << "y(x)=";
		if (stretching_coefficient != 1)
			stream << stretching_coefficient;
		stream << "sin(";
		if (frequency_coefficient != 1)
			stream << frequency_coefficient;
		stream << "x";
		if (offset_on_x > 0)
			stream << "+" << offset_on_x;
		if (offset_on_x < 0)
			stream << offset_on_x;
		stream << ")";
		if (offset_on_y > 0)
			stream << "+" << offset_on_y;
		if (offset_on_y < 0)
			stream  << offset_on_y;
		stream << std::endl;
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
		stretching_coefficient(stretching_coefficient), frequency_coefficient(frequency_coefficient), offset_on_x(offset_on_x), offset_on_y(offset_on_y) {}
	OneVaribleFunction* derivative() {
		return new SinFunction(frequency_coefficient, -stretching_coefficient * frequency_coefficient, -offset_on_x);
	}
	double value(double argument) {
		return stretching_coefficient * cos(frequency_coefficient * argument + offset_on_x) + offset_on_y;
	}
	bool equals(const OneVaribleFunction& rhs) {
		const CosFunction * ptr = dynamic_cast<const CosFunction*>(&rhs);
		if (ptr != nullptr && *this == *ptr)
			return true;
		else
			return false;
	}
	void print(std::ostream& stream) {
		stream << "y(x)=";
		if (stretching_coefficient != 1)
			stream << stretching_coefficient;
		stream << "cos(";
		if (frequency_coefficient != 1)
			stream << frequency_coefficient;
		stream << "x";
		if (offset_on_x > 0)
			stream << "+" << offset_on_x;
		if (offset_on_x < 0)
			stream <<  offset_on_x;
		stream << ")";
		if (offset_on_y > 0)
			stream << "+" << offset_on_y;
		if (offset_on_y < 0)
			stream << offset_on_y;
		stream << std::endl;
	}
	bool operator ==(const CosFunction& rhs) {
		if (rhs.stretching_coefficient == stretching_coefficient && rhs.frequency_coefficient == frequency_coefficient &&
			rhs.offset_on_x == offset_on_x && rhs.offset_on_y == offset_on_y)
			return true;
		else
			return false;
	}
};
OneVaribleFunction* SinFunction::derivative() {
	return  new CosFunction(frequency_coefficient, stretching_coefficient * frequency_coefficient, offset_on_x);
}
