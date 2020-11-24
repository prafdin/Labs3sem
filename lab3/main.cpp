#include"unique_ptr.h"
#include <iostream>
#include <utility>
#include <vector>
#include "vector.h"
#include "list.h"
#include <list>
#include <algorithm>
template <typename T>
struct abc {
	int size;
	T* data;
	abc(int size) : size(size), data(new T[size]){}
	T& operator[](int index) {
		return data[index];
	}

};

struct temp {
	int data;
	temp (int data=0): data(data) {}
	temp(const temp& ptr) {
		data = ptr.data;
		printf("copy ctor");
	}
	temp( temp& ptr) {
		data = ptr.data;
		printf("copy ctor");
	}
	temp(temp&& ptr) noexcept {
		data = ptr.data;
		printf("move ctor");
	}
	temp& operator=(const temp& ptr) {
		data = ptr.data;
		printf("copy assign");
		return *this;
	}
	temp& operator=( temp&& ptr) noexcept {
		data = ptr.data;
		printf("move assign");
		return *this;
	}
	~temp() {
		printf("dtor");
	}
};
int main()
{
	int b = 1;
	int c = 2;
	std::list<int> abr;
	List<int> abc;
	
	abr.insert(abr.begin(), b);
	//abr.insert(abr.begin(), c);

	abc.insert(abc.begin(),b);
	abc.insert(abc.begin(), c);
	auto abd = abc;
	printf("%d %d\n", *abr.begin(), *++abr.begin());
	printf("%d %d", *abd.begin(), *++abd.begin());
}
