#include <iostream>

#define Log(x) std::cout<<x<<std::endl;


int main() {


	int x = 20;
	int* ptr = &x;
	int ** ptrptr = &ptr;
	Log(ptrptr);
	Log(&ptr);
	Log(*ptrptr);
	Log(ptr);
	Log((long long int)ptr);
	Log(*ptr);
}

