#pragma once

#include <stdexcept>
namespace sui {
	class BinaryTree {
		int _data;
		int _weight;
		size_t _index;
		BinaryTree* _parent;
		BinaryTree* _left;
		BinaryTree* _right;

	public:
		BinaryTree(int data, size_t index = 0,BinaryTree* parent=nullptr) : _data(data), _index(index), _weight(1),_parent(parent), _left(nullptr), _right(nullptr) {}
		~BinaryTree() {
			delete _left;
			delete _right;

		}
		BinaryTree* get_min() {
			while (_left != nullptr)
				return  _left->get_min();
			
		}
		BinaryTree* get_max() {
			while (_right != nullptr)
				_right->get_min();
			return this;
		}
		 BinaryTree* get_left()  {
			return _left;
		}
		 BinaryTree* get_right()  {
			return _right;
		}
		const int get_data() const {
			return _data;
		}
		
		void add(int num, size_t index = 0) {
			if (num > _data) {
				if (_right != nullptr) {
					_weight++;
					_right->add(num);
				}
				else
					_right = new BinaryTree(num, _index + 1,this);
			}
			else {
				_weight++;
				_index++;
				if (_left != nullptr)
					_left->add(num);
				else
					_left = new BinaryTree(num,0,this);
			}
		}
		size_t find(int num) const {
			if (this == nullptr)
				throw std::logic_error("Number not contained in set!");
			if (_data > num)
				_left->find(num);
			else if (_data < num)
				_right->find(num);
			else
				return _index;
		}
		int& get(size_t index) {
			if (index > _weight)
				throw std::logic_error("Index out of range!");
			if (_index > index)
				_left->get(index);
			else if (_index < index)
				_right->get(index);
			else
				return _data;
		}
		friend void del(int num, BinaryTree* &ancesator);
		friend void  transplant( BinaryTree*& first, BinaryTree*& second);
		};
	
	class SetUnicalInteger {
		BinaryTree* _root;
		size_t _size;
	public:
		SetUnicalInteger(size_t size = 0);



	};




	}