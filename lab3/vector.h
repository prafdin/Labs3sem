#pragma once 
#include <iostream>
double coefficient_capacity = 1.6;
template <typename T>
class Vector {
	T* data;
	size_t _size;
	size_t _capacity;
public:
	Vector():data(nullptr),_size(0), _capacity(0) { }
	Vector(const Vector<T>& ptr) {
		data = new T[ptr._size];
		_size = ptr._size;
		for (size_t i = 0; i < _size; ++i) {
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
		std::swap(_size, rhs._size);
		std::swap(_capacity, rhs._capacity);
	}
	size_t size() const  {
		return _size;
	}
	size_t capacity() const noexcept {
		return _capacity;
	}
	const T& operator[](const size_t index) const {
		return data[index];
	}
	T& operator[](size_t index) {
		return data[index];
	}
	T* begin() const {
		return data;
	}
	T* end() const {
		return data + _size;
	}
	const T* insert(const T* pos, const T& value) {
		if (pos < begin() || pos > end())
			throw std::logic_error("Iterator out of range");
		size_t count_move = _size == 0 ? 0 : _size - (pos - data);
		if (_size + 1 > _capacity) {
			double new_size = _size == 0 ? 1 : ceil(_size * coefficient_capacity);
			this->resize((size_t)new_size);
		}
		else
			++_size;
		auto insert_place = data + (_size - 1 - count_move); 
		for (int i = (int)count_move; i > 0; --i) 
			* (insert_place + i) = std::move_if_noexcept(*(insert_place + i - 1));
		*insert_place= value;
		return insert_place;
	}
	const T* erase(const T* pos) {
		if (pos < begin() || pos > end() )
			throw std::logic_error("Iterator out of range");
		else {
			size_t count_move = _size - (pos - data) -1;
			size_t num_del = data - pos;
			auto delete_place = data + num_del ;
			for (int i =(int) count_move; i > 0; --i) {
				*(delete_place + i - 1) = std::move_if_noexcept(*(delete_place + i ));
			}
			--_size;
			return pos;
		}
	}
	void resize(size_t new_size) {
		if (_capacity >= new_size) {
			auto temp = new T[new_size];
			for (int i = 0; i < _size; ++i) {
				temp[i] = std::move_if_noexcept(data[i]);
			}
			_size = new_size;
			_capacity = new_size;
			delete[]data;
			data = temp;
		}
		else {
		auto temp = new T[new_size];
		for (int i = 0; i < _size; ++i) {
			temp[i] = std::move_if_noexcept(data[i]);
		}
		++_size;
		_capacity = new_size;
		delete[] data;
		data = temp;
	}
	}
	void clear() noexcept {
		delete[] data;
		data = nullptr;
		_size = 0;
		_capacity = 0;
	}
	~Vector() {
		clear();
	}
};
