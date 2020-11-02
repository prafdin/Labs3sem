#include <iostream>

#include "set_unical_integer.h"




int main(void) {
	 sui::BinaryTree* t1= new  sui::BinaryTree(4, 0);
	 t1->add(2);
	 t1->add(7);
	 t1->add(6);
	 t1->add(5);
	sui::del(7, t1);

	}