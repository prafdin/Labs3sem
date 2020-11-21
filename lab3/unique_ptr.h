#pragma once
#include <iostream>
template <typename T>
class UniquePtr {
	T* data;
public:
	explicit UniquePtr() : data(nullptr) {
	}
	explicit UniquePtr(T* const ptr) : data(ptr) { }
	UniquePtr(const UniquePtr<T>& rhs) = delete;
	UniquePtr(UniquePtr<T>&& rhs) noexcept {
		data = rhs.data;
		rhs.data = nullptr;
	}
	~UniquePtr() {
		delete data;
	}
	UniquePtr<T>& operator=(const UniquePtr<T>& rhs) = delete;
	UniquePtr<T>& operator=(UniquePtr<T>&& rhs) noexcept {
		swap(data, rhs.data);
	}
	UniquePtr<T>& operator=(nullptr_t) {
		delete data;
		data = nullptr;
	}
	const T* get() const {
		return data;
	}
	T* release() noexcept {
		auto copy = data;
		data = nullptr;
		return copy;
	}
	void reset(T* ptr)noexcept {
		if (data != nullptr)
			delete data;
		data = ptr;
	}
	void swap(UniquePtr<T>& rhs) noexcept {
		auto copy = data;
		data = rhs.data;
		rhs.data = copy;
	}
	explicit operator bool()const {
		return data != nullptr;
	}
	T& operator*() {
		return *data;
	}
	const T& operator*() const {
		return *data;
	}
	T& operator->() {
		return *data;
	}
	T* operator->() const {
		return data;
	}
};
template<typename T>
bool operator==(const UniquePtr<T>& lhs, const UniquePtr<T>& rhs) {
	if (lhs.get() == rhs.get())
		return true;
	else
		return false;
}
template<typename T>
bool operator!=(const UniquePtr<T>& lhs, const UniquePtr<T>& rhs) {
	if  lhs == rhs;
		return false;
	else
		return true;
}
template<typename T>
bool operator<(const UniquePtr<T>& lhs, const UniquePtr<T>& rhs) {
	if (lhs.get() < rhs.get())
		return true;
	else
		return false;
}
template<typename T>
bool operator<=(const UniquePtr<T>& lhs, const UniquePtr<T>& rhs) {
	if (lhs < rhs || lhs == rhs)
		return true;
	else
		return false;
}
template<typename T>
bool operator>(const UniquePtr<T>& lhs, const UniquePtr<T>& rhs) {
	if (lhs.get() > rhs.get())
		return true;
	else
		return false;
}
template<typename T>
bool operator>=(const UniquePtr<T>& lhs, const UniquePtr<T>& rhs) {
	if (lhs > rhs || lhs == rhs)
		return true;
	else
		return false;
}