#include"unique_ptr.h"
#include <iostream>
#include <utility>
#include <vector>
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
	temp (): data(0) {}
	temp(const temp& ptr) {
		data = ptr.data;
		printf("copy ctor");
	}
	temp( temp& ptr) {
		data = ptr.data;
		printf("copy ctor");
	}
	//temp(temp&& ptr) = delete; /* {
	//	data = ptr.data;
	//	printf("move ctor");
	//}*/
	temp& operator=(const temp& ptr) {
		data = ptr.data;
		printf("copy assign");
		return *this;
	}
	//temp& operator=( temp&& ptr) = delete;  /* {
	//	data = ptr.data;
	//	printf("move assign");
	//	return *this;
	//}*/
};
int main()
{
	abc<temp> ptr1(3);
	abc<temp> ptr2(4);
	for (int i = 0; i < 3; ++i) {
		std::swap(ptr1[i], ptr2[i]);
	}
}
