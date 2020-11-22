#include"unique_ptr.h"
#include <iostream>
#include <utility>
#include <vector>
#include "vector.h"
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
	Vector<temp> a;
	//std::vector<temp> a;
	temp a1 = 1;
	temp b = 2;
	a.insert(a.begin(),a1 );
	printf("\n");
	a.insert(a.begin(),b );
	printf("\n");
	auto ptr1 = a.begin();
//	std::cout << a[0] << std::endl;
	auto  p = a.erase(a.begin());
//	std::cout << a[0] << std::endl;
	
	
	/*auto ptr = new std::vector<temp>();
	ptr->size();
	temp a = 1;
	temp b = 2;
	temp c = 3;
	ptr->insert(ptr->begin(), a);
	printf("\n");
	ptr->insert(ptr->end()-1, b);
	printf("\n");
	ptr->insert(ptr->begin()+1, c);
	printf("\n");
	printf("%d %d %d", (*ptr)[0], (*ptr)[1], (*ptr)[2]);*/
}
