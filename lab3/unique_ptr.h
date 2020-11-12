#pragma once
#include <iostream>
template <typename T>
class UniquePtr {
	T* data;
public:
	explicit UniquePtr() : data(nullptr) {
	}
	explicit UniquePtr(T* const ptr) : data(ptr) { }
	UniquePtr(UniquePtr& rhs) = delete;
	UniquePtr(UniquePtr&& rhs) noexcept {
		data=rhs.data;
		rhs.data = nullptr;
	}
	~UniquePtr() {
		delete data;
	}
	UniquePtr&	operator=(UniquePtr& rhs) = delete;
	UniquePtr& operator=(UniquePtr&& rhs) noexcept {
		swap(data, rhs.data);
	}
	UniquePtr& operator=(nullptr_t) {
		delete data;
		data = nullptr;
	}
	const T* get() const  noexcept {
		return data;
	}
	T* release() noexcept{
		auto copy = get();
		data = nullptr;
		return copy;
	}
	void reset(T* ptr)noexcept{
		auto copy = get();
		data = ptr;
		if (copy != nullptr)
			delete copy;
	}
	void swap(UniquePtr& rhs) noexcept {
		auto copy = get();
		data = rhs.data;
		rhs.data = copy;
	}
	explicit bool operator bool()const noexcept {
		if (get() == nullptr)
			return false;
		else
			return true;
	}
	T& operator*() {
		return *data;
	}
	const T& operator*() const  {
		return *data;
	}
	T& operator->() {
		return *data;
	}
	const T& operator->() const {
		return *data;
	}

	bool operator==(const UniquePtr& lhs, const UniquePtr& rhs) const  {
		if (lhs.get() == rhs.get())
			return true;
		else
			return false;
	}
	bool operator!=(const UniquePtr& lhs, const UniquePtr& rhs) const {
		if (lhs == rhs)
			return false;
		else
			return true;
	}
	bool operator<(const UniquePtr& lhs, const UniquePtr& rhs) const {
		if (lhs.get() < rhs.get())
			return true;
		else
			return false;
	}
	
};