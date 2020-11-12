#include <iostream>

#include "set_unical_integer.h"




int main(void) {
	 sui::BinaryTree* t1= new  sui::BinaryTree(4, 0);
	 t1->add(1);
	 auto x = t1->get_min(1);
	sui::del(1, t1);

	}