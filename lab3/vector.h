#pragma once 
#include <iostream>
double coefficient_capacity = 1.6;
template <typename T>
class Vector {
	T* data;
	size_t size;
	size_t capacity;
public:
	Vector():data(nullptr),size(0), capacity(0) { }
	Vector(const Vector<T>& ptr) {
		data = new T[ptr.size];
		size = ptr.size;
		for (size_t i = 0; i < size; ++i) {
			data[i] = ptr[i];
		}
	}
	Vector(Vector<T>&& ptr) noexcept : data(ptr.data), size(ptr.size) {
		ptr.data = nullptr;
		ptr.size = 0;
	}
	Vector<T>& operator=(const Vector<T>& rhs) {
		auto temp(rhs);
		swap(temp);
		return *this;
	}
	Vector<T>& operator=(Vector<T>&& rhs) noexcept {
		swap(rhs);
		return *this;
	}
	void swap(Vector<T>& rhs) noexcept {
		std::swap(data, rhs.data);
		std::swap(size, rhs.size);
		std::swap(capacity, rhs.capacity);
	}
	size_t size() const noexcept {
		return size;
	}
	size_t capacity() const noexcept {
		return capacity;
	}
	const T& operator[](const size_t index) const {
		return data[index];
	}
	T& operator[](size_t index) {
		return data[index];
	}
	const T* begin() const {
		return data;
	}

	const T* end() const {
		return data + size;
	}
	const T* insert(const T* pos, const T& value) {

	}
};
