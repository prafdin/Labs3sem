#pragma once 
template<typename T>
class List {
	struct Node{
		T _data;
		Node* _next;
		Node* _prev;
		Node(const T& data , Node * next, Node * prev  ) : _data(data), _next(next), _prev(prev) {}
		
	};
	Node* head;
	Node* tail;
	Node* dummy;
	size_t _size;
public:
	class ListIterator {
		Node* node;
		ListIterator( Node* ptr) : node(ptr) { }
		friend class List<T>;
	public:
		ListIterator& operator++  () {
			node = node->_next;
			return *this;
		}
		ListIterator& operator++ (int) {
			auto copy = *this;
			node = node->_next;
			return copy;
		}
		ListIterator& operator+ (int count_iter) {
			for (count_iter; count_iter; --count_iter) {
				++*this;
			}
			return *this;
		}
		ListIterator& operator--() {
			node = node->_prev;
			return *this;
		}
		ListIterator& operator--(int) {
			auto copy = *this;;
			node = node->_prev;
			return copy;
		}
		ListIterator& operator=(const ListIterator& ptr) {
			node = ptr.node;
			return *this;
		}
		T& operator*() {
			return node->_data;
		}
		T* operator->() {
			return &(node->_data);
		}
		bool operator==(const ListIterator& rhs){
			return node == rhs.node;
		}
		bool operator!=(const ListIterator& rhs) {
			return node != rhs.node;
		}
	};
	List() : dummy(new Node(T(), nullptr, nullptr)), _size(0) {
		dummy->_next = dummy;
		dummy->_prev = dummy;
		head=dummy ;
		tail=dummy;
	}
	List(const List<T>& rhs) : dummy(new Node(T(), nullptr, nullptr)) {
		Node * src = rhs.tail;
		dummy->_next = dummy;
		Node* dst = dummy;
		for (size_t i = 0; i < rhs._size; ++i) {
			Node* tmp = new Node(src->_data, dst, nullptr);
			dst->_prev = tmp;
			src = src->_prev;
			dst = tmp;
		}
		dst->_prev = dummy;
		head = dst;
		tail = dst->_prev->_prev;
		_size = rhs._size;
	}
	List(List<T>&& rhs) {
		swap(*this, rhs);
	}
	~List() {
		clear();
		delete dummy;
	}
	List<T>& operator=(const List<T>& rhs) {
		auto temp(rhs);
		swap(temp);
		return *this;
	}
	List<T>& operator=(List<T>&& rhs) noexcept {
		swap(rhs);
		return *this;
	}
	size_t size() {
		return _size;
	}
	void swap(List<T>& rhs) noexcept{
		std::swap(head, rhs.head);
		std::swap(tail, rhs.tail);
		std::swap(dummy, rhs.dummy);
		std::swap(_size, rhs._size);
	}
	ListIterator begin() const {
		return ListIterator(head);
	}
	ListIterator end() const {
		return ListIterator(dummy);
	}
	ListIterator insert(ListIterator pos, const T& value) {
		auto node = pos.node;
		Node* tmp = nullptr;
		if (pos == this->begin()) {
			tmp = new Node(value, node, dummy);
			head = tmp;
		}
		else {
			tmp = new Node(value, node, node->_prev);
			node->_prev->_next = tmp;
		}
		if (pos == this->end()) {
			tail = tmp;
			dummy->_prev = tmp;
		}
		else
			node->_prev = tmp;
		++_size;
		return --pos;
	}
	ListIterator erase(ListIterator pos) {
		if (pos == this->end()) 
			return dummy;
		else {
			auto node = pos.node;
			if (pos == this->begin()) {
				node->_next->_prev = dummy;
				head = node->_next;
			}
			else {
				node->_prev->_next = node->_next;
				node->_next->_prev = node->_prev;
			}
			if (node->_next == this->end().node) {
				tail = head;
			}
			++pos;
			--_size;
			delete node;		
			return pos;
		}	
	}
	void clear() {
		for (int i = 0; i < _size; ++i) {
			auto tmp = head;
			head = head->_next;
			delete tmp;
		}
		_size = 0;
		tail = head;
		dummy->_prev = dummy;
	}
	
};