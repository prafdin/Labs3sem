#include"unique_ptr.h"
int main(void) {
	int a = 3;
	UniquePtr<int> abc;

	int* ptr = &a;
	ptr = abc.get();
	
}