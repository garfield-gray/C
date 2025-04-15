#include <iostream>

int main() {
	std::cout<<"Hey!"<<"\n";
	bool x[10] = {0, 0, 0, 1, 1, 1, 0, 0, 1, 1};
	

	

	for (int i = 0; i < 10; i++) {
        	std::cout << &x[i] << std::endl;
        }



	

	return 0;

}
