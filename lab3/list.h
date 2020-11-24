#pragma once 

template<typename T>
class List {
	struct Node{
		T _data;
		Node* _next;
		Node* _prev;
		Node(const T& data , Node * next, Node * prev  ) : _data(data), _next(next), _prev(prev) {}
		Node(T&& data, Node* next , Node* prev ):_data(std::move_if_noexcept(data)), _next(next), _prev(prev){}
		Node(const Node& ptr) : _data(ptr._data), _next(ptr._next), _prev(ptr._prev) {}
		Node(Node&& ptr) : _data(std::move(ptr._data)), _next(ptr._next), _prev(ptr._prev) {}
		struct NodeIterator {
			Node* node;
			NodeIterator(const NodeIterator& ptr) : node(ptr.node) { }
			NodeIterator( NodeIterator&& ptr) : node(ptr.node) { }
			NodeIterator(Node* ptr): node(ptr){ }
			explicit operator bool() const {
				return node != nullptr;
			}
			NodeIterator& operator++  () {
				node = node->_next;
				return *this;
			}
			NodeIterator& operator++ (int) {
				auto copy = *this;
				data = data->_next;
				return copy;
			}
			NodeIterator& operator--() {
				node = node->_prevl;
				return *this;
			}
			NodeIterator& operator--(int) {
				auto copy = *this;;
				node = node->_prev;
				return copy;
			}
			NodeIterator& operator=(const NodeIterator& ptr) {
				node = ptr.node;
				return *this;
			}
			NodeIterator& operator=( NodeIterator&& ptr) {
				node = ptr.node;
				return *this;
			}
			Node* operator*() {
				return node;
			}
			 T* operator->() {
				return node;
			}
			bool operator==(const NodeIterator& rhs) {
				return node == rhs.node;
			}
			bool operator!=(const NodeIterator& rhs) {
				return node != rhs.node;
			}
		};
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
	List(const List<T>& rhs):dummy(rhs.dummy) {
		auto dst = Node::NodeIterator(head);
		
		for (auto src = Node::NodeIterator(rhs.head); src; ++src) {
			dst(*src);
			++dst;
		}
		tail = &(*dst);
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