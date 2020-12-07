#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include<memory>
#include "functions.h"
int RAND_RANG = 100;
int CODE_LEFT = 37;
int CODE_RIGHT = 39;
using node = std::pair <size_t, std::shared_ptr<OneVaribleFunction>>;
using iterator = std::vector<node>::const_iterator;
typedef enum { CreateObject = 1, PushBack, DelObject, DelAll, Equals, Print, CalculateFunc, DerivativeFunc }ItemMainMenu;
typedef enum { CreateConstF = 1, CreateLineF, CreateQuadraticF, CreateSinF, CreateCosF }ItemCreateMenu;
template <typename T>
T input_digit(T left_bound = std::numeric_limits<T>::min(), T right_bound = std::numeric_limits<T>::max()) {
	T data;
	while (true)
	{
		std::string str;
		std::cin >> str;
		bool flag = true;
		for (size_t i = 0; i < str.length(); ++i)
			if (!isdigit(str[i]))
			{
				flag = false;
				break;
			}
		if (!flag)
			continue;
		std::stringstream tmp(str);
		tmp >> data;
		if (data<left_bound || data> right_bound)
			continue;
		else
			break;
	}
	return data;
}
iterator find_pos(const iterator begin, const iterator end, size_t index);
bool cmp_ordering(const node& lhs, const node& rhs);
template<typename T>
void create_object(std::vector<node>& vector, size_t index, T* object) {
	vector.push_back(std::make_pair(index, std::shared_ptr<T>(object))); //make_unique ??
	std::sort(vector.begin(), vector.end(), cmp_ordering);
}
size_t choose_index(const std::vector<node>& vector) {
	while (true) {
		std::cout << "Input index: ";
		size_t index = input_digit<size_t>(0, std::numeric_limits<size_t>::max());
		if (find_pos(vector.begin(), vector.end(), index) != vector.end())
			return index;
		else
			std::cout << "Object by index is missing" << std::endl;
	}
}
size_t input_index( std::vector<node>& vector) {
	while (true) {
		std::cout << "Input index: ";
		size_t index = input_digit<size_t>(0, std::numeric_limits<size_t>::max());
		if (find_pos(vector.begin(), vector.end(), index) == vector.end())
			return index;
		else
			std::cout << "Index already use" << std::endl;
	}
}
OneVaribleFunction* create_func() {
	std::cout << "Select  function that need create:" << std::endl;
	switch (input_digit<int>(CreateConstF, CreateCosF)) {
	case CreateConstF: {
		std::cout << "Input coefficient:" << std::endl << "y(x)=";
		double coefficient = input_digit<double>();
		return new ConstantFunction(coefficient);
	}
	case CreateLineF: {
		std::cout << "Input coefficients: " << "y(x)=a*x+b" << std::endl;
		std::cout << "a:";
		double slope = input_digit<double>();
		std::cout << std::endl;
		std::cout << "b:";
		double intercept = input_digit<double>();
		return new LineFunction(slope, intercept);
	}
	case CreateQuadraticF: {
		std::cout << "Input coefficients: " << "y(x)=a*x^2+b*x+c" << std::endl;
		std::cout << "a:";
		double higher_coefficient = input_digit<double>();
		std::cout << std::endl;
		std::cout << "b:";
		double second_coefficient = input_digit<double>();
		std::cout << std::endl;
		std::cout << "c:";
		double constant_term = input_digit<double>();
		return new QuadraticFunction(higher_coefficient, second_coefficient, constant_term);
	}
	case CreateSinF: {
		std::cout << "Input coefficients: " << "y(x)=a*sin(b*x+c)+d" << std::endl;
		std::cout << "a:";
		double stretching_coefficient = input_digit<double>();
		std::cout << std::endl;
		std::cout << "b:";
		double frequency_coefficient = input_digit<double>();
		std::cout << std::endl;
		std::cout << "c:";
		double offset_on_x = input_digit<double>();
		std::cout << std::endl;
		std::cout << "d:";
		double offset_on_y = input_digit<double>();
		return new SinFunction(frequency_coefficient, stretching_coefficient, offset_on_x, offset_on_y);
	}
	case CreateCosF: {
		std::cout << "Input coefficients: " << "y(x)=a*cos(b*x+c)+d" << std::endl;
		std::cout << "a:";
		double stretching_coefficient = input_digit<double>();
		std::cout << std::endl;
		std::cout << "b:";
		double frequency_coefficient = input_digit<double>();
		std::cout << std::endl;
		std::cout << "c:";
		double offset_on_x = input_digit<double>();
		std::cout << std::endl;
		std::cout << "d:";
		double offset_on_y = input_digit<double>();
		return new CosFunction(frequency_coefficient, stretching_coefficient, offset_on_x, offset_on_y);
	}
	}
	return nullptr;
}
OneVaribleFunction* create_rand_func() {
	auto func = CreateConstF + rand() % CreateCosF;
	switch (func) {
	case CreateConstF: {
		return new ConstantFunction(rand() % RAND_RANG);
	}
	case CreateLineF: {
		return new LineFunction(rand() % RAND_RANG, rand() % RAND_RANG);
	}
	case CreateQuadraticF: {
		return new QuadraticFunction(rand() % RAND_RANG, rand() % RAND_RANG, rand() % RAND_RANG);
	}
	case CreateSinF: {
		return new SinFunction(rand() % RAND_RANG, rand() % RAND_RANG, rand() % RAND_RANG, rand() % RAND_RANG);
	}
	case CreateCosF: {
		return new CosFunction(rand() % RAND_RANG, rand() % RAND_RANG, rand() % RAND_RANG, rand() % RAND_RANG);
	}
	}
	return nullptr;
}
int main(void) {
	std::vector <node>vector;
	while (true) {
		std::cout << "1.Create Object \n2.Push back N object \n3.Dellete object \n4.Dellete all\n5.Compare object\n6.Print all\n";
		std::cout << "7.Calculate function\n8.Calculate derivative of function\n";
		switch (input_digit<int>(CreateObject, DerivativeFunc)) {
		case CreateObject: {
			size_t index = input_index(vector);
			auto func = create_func();
			create_object(vector, index, func);
			break;
		}
		case PushBack: {
			std::cout << "Enter quantity of objects:";
			size_t quantity = input_digit<size_t>(0, std::numeric_limits<size_t>::max());
			size_t last_index = vector.size() == 0 ? 0 : ++(--vector.end())->first;
			srand((unsigned int)time(0));
			for (size_t i = 0; i < quantity; ++i) {
				auto func = create_rand_func();
				vector.push_back(std::make_pair(last_index + i, std::shared_ptr<OneVaribleFunction>(func)));
			}
			break;
		}
		case DelObject: {
			if (vector.size() == 0)
				break;
			size_t index = choose_index(vector);
			auto pos = find_pos(vector.begin(), vector.end(), index);
			vector.erase(pos);
			break;
		}
		case DelAll: {
			vector.clear();
			break;
		}
		case Equals: {
			if (vector.size() == 0)
				break;
			std::cout << "First: ";
			size_t first_index = choose_index(vector);
			std::cout << "Second: ";
			size_t second_index = choose_index(vector);
			auto first_pos = find_pos(vector.begin(), vector.end(), first_index);
			auto second_pos = find_pos(vector.begin(), vector.end(), second_index);
			if (first_pos->second->equals(*second_pos->second))
				std::cout << "Object are equal" << std::endl;
			else
				std::cout << "Object are not equal" << std::endl;
			break;
		}
		case Print: {
			for (int i = 0; i < vector.size(); ++i) {
				std::cout << "[" << vector[i].first << "] ";
				vector[i].second->print(std::cout);
				std::cout << std::endl;
				if (i == 10) {
					std::cout << "(...)" << std::endl;
					break;
				}
			}
			break;
		}
		case CalculateFunc: {
			if (vector.size() == 0)
				break;
			std::cout << "Enter index of object you want to calculate: ";
			size_t index = choose_index(vector);
			auto pos = find_pos(vector.begin(), vector.end(), index);
			pos->second->print(std::cout);
			std::cout << "Enter x: ";
			double argument = input_digit<double>();
			std::cout << "Function solution:" << pos->second->value(argument) << std::endl;
			break;
		}
		case DerivativeFunc: {
			if (vector.size() == 0)
				break;
			size_t index = choose_index(vector);
			auto ref = find_pos(vector.begin(), vector.end(), index);
			ref->second->print(std::cout);
			auto der = ref->second->derivative();
			std::cout << "Derivative of function:" << std::endl;
			der->print(std::cout);
			std::cout << "Save function ?\ny/n" << std::endl;
			char state_derivative = 0;
			std::string choice;
			while (true) {
				getline(std::cin, choice);
				if (choice == "n")
					break;
				else if (choice == "y") {
					size_t index = input_index(vector);
					create_object(vector, index, der);
					break;
				}
			}

		}
		}

	}
}


iterator find_pos(iterator begin,iterator end, size_t index) {
	iterator pos = end;
	for (iterator i = begin; i != end; ++i) {
		if (index == i->first)
			pos = i;
	}
	return pos;
}
bool cmp_ordering(const node& lhs, const node& rhs) {
	if (lhs.first < rhs.first)
		return true;
	else
		return false;
}
