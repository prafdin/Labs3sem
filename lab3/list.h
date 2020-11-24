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
	size_t size;
public:
	class ConstListIterator {
		Node* node;
		ConstListIterator( Node* ptr) : node(ptr) { }
		friend class List<T>;
	public:
		ConstListIterator& operator++  () {
			node = node->_next;
			return *this;
		}

		ConstListIterator& operator++ (int) {
			auto copy = *this;
			node = node->_next;
			return copy;
		}
		ConstListIterator& operator--() {
			node = node->_prev;
			return *this;
		}
		ConstListIterator& operator--(int) {
			auto copy = *this;;
			node = node->_prev;
			return copy;
		}
		ConstListIterator& operator=(const ConstListIterator& ptr) {
			node = ptr.node;
			return *this;
		}
		const T& operator*() {
			return node->_data;
		}
		const T* operator->() {
			return &(node->_data);
		}
		bool operator==(const ConstListIterator& rhs){
			return node == rhs.node;
		}
		bool operator!=(const ConstListIterator& rhs) {
			return node != rhs.node;
		}
	};
	List() : dummy(new Node(T(), nullptr, nullptr)), size(0) {
		dummy->_next = dummy;
		dummy->_prev = dummy;
		head=dummy ;
		tail=dummy;
	}
	List(const List<T>& rhs) {
		auto src = NodeIterator(rhs.tail);
		for (int i = 0; i < rhs.size; ++i) {
			dst=new Node(*src);
			++dst;
			--src;
		}
	}
	ConstListIterator begin() const {
		return ConstListIterator(head);
	}
	ConstListIterator end() const {
		return ConstListIterator(dummy);
	}
	ConstListIterator insert(ConstListIterator pos, const T& value) {
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
		++size;
		return --pos;
	}
	ConstListIterator erase(ConstListIterator pos) {
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
			--size;
			delete node;		
			return pos;
		}	
	}
	void clear() {
		for (int i = 0; i < size; ++i) {
			auto tmp = head;
			head = head->_next;
			delete tmp;
		}
		size = 0;
		tail = head;
		dummy->_prev = dummy;
	}
};