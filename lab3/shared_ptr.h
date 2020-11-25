#pragma once
#include <iostream>
template <typename T>
class SharedPtr {
	T* data;
	int* counter;
public:
	SharedPtr() : data(nullptr), counter(nullptr) {}
	explicit SharedPtr(T* const ptr): data(ptr), counter(new int(1)) {}
	SharedPtr(const SharedPtr& ptr): data(ptr.data), counter(ptr.counter){
		++ *counter;
	}
	SharedPtr(SharedPtr&& ptr) :data(ptr.data), counter(ptr.counter) {
		++ *counter;
	}
	template <typename Y>
	SharedPtr(const SharedPtr<Y>& source, T* ptr): data(ptr),counter(source.counter){
		++* counter;
	}
	//ctor move aliasing 
	SharedPtr<T>& operator=(const SharedPtr<T>& ptr){
		delete this;
		data = ptr.data;
		counter = ptr.counter;
		++ *counter;
	}
	SharedPtr<T>& operator=(SharedPtr<T>&& ptr) {
		delete this;
		data = ptr.data;
		counter = ptr.counter;
		++* counter;
	}
	SharedPtr<T>& operator=(nullptr_t) {
		delete this;
		data = nullptr;
	}
	~SharedPtr() {
		if (*counter == 1) {
			delete data;
			delete counter;
		}
		else
			-- *counter;
	}
	int use_count() const {
		if (counter == nullptr)
			return 0;
		else
		return *counter;
	}
	void reset() {
		delete this;
		data = nullptr;
		counter = nullptr;
	}
	void reset(T* const ptr) {
		delete this;
		data = ptr.data;
		counter = new int(1);
	}
	void swap(SharedPtr& ptr) noexcept {
		std::swap(data, ptr.data);
		std::swap(counter, ptr.counter);
	}
	T* get() const {
		return data;
	}
	explicit operator bool() const {
		return data != nullptr;
	}
	T& operator*() {
		return *data;
	}
	T* operator->() {
		return data;
	}
};
template<typename T> 
bool operator==(const SharedPtr<T>& lhs, const SharedPtr<T>& rhs) {
		if (lhs.get() == rhs.get())
			return true;
		else
			return false;
	}
template<typename T>
bool operator!=(const SharedPtr<T>& lhs, const SharedPtr<T>& rhs) {
		if lhs == rhs;
		return false;
		else
			return true;
	}
template<typename T>
bool operator<(const SharedPtr<T>& lhs, const SharedPtr<T>& rhs) {
		if (lhs.get() < rhs.get())
			return true;
		else
			return false;
	}
template<typename T>
bool operator<=(const SharedPtr<T>& lhs, const SharedPtr<T>& rhs) {
		if (lhs < rhs || lhs == rhs)
			return true;
		else
			return false;
	}
template<typename T>
bool operator>(const SharedPtr<T>& lhs, const SharedPtr<T>& rhs) {
		if (lhs.get() > rhs.get())
			return true;
		else
			return false;
	}
template<typename T>
bool operator>=(const SharedPtr<T>& lhs, const SharedPtr<T>& rhs) {
		if (lhs > rhs || lhs == rhs)
			return true;
		else
			return false;
	}
template< class T, class U >
SharedPtr<T> static_pointer_cast(const SharedPtr<U>& ptr) {
	auto tmp = static_cast<T*>(ptr.get());
	return SharedPtr<T>(ptr, tmp);
}
template< class T, class U >
SharedPtr<T> dynamic_pointer_cast(const SharedPtr<U>& ptr) {
	auto tmp = dynamic_cast<T*>(ptr.get());
	if (copy == nullptr)
		return SharedPtr<T>();
	else
		return SharedPtr<T>(ptr, tmp);

}
template< class T, class U >
SharedPtr<T> const_pointer_cast(const SharedPtr<U>& ptr) {
	auto tmp = const_cast<T*>(ptr.get());
	return SharedPtr<T>(ptr, tmp);
}
template< class T, class U >
SharedPtr<T> reinterpret_pointer_cast(const SharedPtr<U>& ptr) {
	auto tmp = reinterpret_cast<T*>(ptr.get());
	return SharedPtr<T>(ptr, tmp);
}