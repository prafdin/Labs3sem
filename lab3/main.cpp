#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include "vector.h"
#include <list>
#include "list.h"
#include"unique_ptr.h"
#include"shared_ptr.h"

template<class T> using UniquePtrType = std::unique_ptr<T>;
template<class T> using SharedPtrType = std::shared_ptr<T>;
template<class T> using CollectionType =std::vector<T>;
class Item
{
public:
	Item() { std::cout << "Item acquired\n"; }
	~Item() { std::cout << "Item destroyed\n"; }
	
};
template<typename T>
void print_collection(const CollectionType<T>& first) {
	for (auto i = first.begin(); i != first.end(); ++i) {
		std::cout << *i  <<" ";
	}
	std::cout <<"\n"<< std::endl;	
}
template<typename T>
void fill_collection(CollectionType<T>& first, size_t count, bool preorder) {
	for (int i = 0; i < count; ++i) {
		first.insert(first.begin(), preorder ? i : ((int)count - i-1));
	}
}
template<typename T>
void  reverse( CollectionType<T>& collection ) {
	return std::reverse(collection.begin(), collection.end());
}
int main()
{
	{
		CollectionType<int> first;
		CollectionType<int> second;
		fill_collection(first, 10, true);
		fill_collection(second, 10, false);
		std::cout << "First collection: ";
		print_collection(first);
		std::cout << "Second collection: ";
		print_collection(second);
		reverse(first);
		reverse(second);
		std::cout << "Reversed first collection: ";
		print_collection(first);
		std::cout << "Reversed second collection: ";
		print_collection(second);
	}
	{
		std::cout << "Create first shared pointer\n";
		auto ptr1 = SharedPtrType<Item>(new Item());
		{
			std::cout << "Create second shared pointer\n";
			auto ptr2 = ptr1;
			std::cout << "Killing second shared pointer\n";
		}
		std::cout << "Killing first shared pointer\n";
	}
	std::cout << "\n\n";
	{
		std::cout << "Create first unique pointer on Item\n";
		auto ptr1 = UniquePtrType<Item>(new Item());
		{
			std::cout << "Copy-Create second unique pointer on Item\n";
			auto ptr2(std::move(ptr1));
			std::cout << "First pointer contain : " << ptr1.get()<< "\n";
			std::cout << "Second pointer contain : " << ptr2.get() <<"\n";
			std::cout << "Killing second unique pointer\n";
		}
		std::cout << "Killing first unique pointer\n";
	}
}
