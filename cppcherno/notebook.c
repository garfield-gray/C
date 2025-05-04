// Print numbers from 1 to 10
#include <stdio.h>
#include <math.h>
int main() {
	unsigned long long int x;
	

	for (int n = 1; n < 11; ++n)
  	{
		x = pow(2, pow(2, n));
		printf("%llu \n", x);
	}
  	return 0;
}

