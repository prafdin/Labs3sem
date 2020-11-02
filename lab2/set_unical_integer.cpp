#include "set_unical_integer.h"
using namespace sui;
bool is_leaf(BinaryTree* root) {
	if (root->get_left() == nullptr && root->get_right() == nullptr)
		return true;
	else
		return false;

}

void  sui::transplant(BinaryTree*& dst, BinaryTree*& src) {
	if (dst->_parent == nullptr) { // if dst main root
		dst = src;
		src->_parent = nullptr;
	}
	else if (dst->_parent->_right == dst) // if dst is right branch his parent
		dst->_parent->_right = src;
	else { // if dst is left branch his parent
		dst->_parent->_left = src;
		if (src != nullptr)
			src->_parent = dst->_parent;
	}
}

void sui::del(int num, BinaryTree* &root) {
	if (root == nullptr)
		throw std::logic_error("Number not contained in set!");
	if (root->_data > num)
		sui::del(num, root->_left);
	else if (root->_data < num)
		sui::del(num, root->_right);
	else {
		
		BinaryTree* tmp = root;
		
		if (root->_left == nullptr) {
			
			transplant(root, root->_right);
			tmp->_right = nullptr;
			delete tmp;
		}
		else if (root->_right == nullptr) {
			transplant(root, root->_left);
			tmp->_left = nullptr;
			delete tmp;
		}
		else {
			BinaryTree* min = root->_right->get_min();
			if (root!=min->_parent){
				transplant(min, min->_right);
				min->_right = root->_right ;
				min->_right->_parent = min;
			}
			transplant(root, min);
			root->_left = tmp->_left;
			root->_left->_parent = root;
			tmp->_left = nullptr;
			tmp->_right= nullptr;
			delete tmp;
		}

		
	}
}
