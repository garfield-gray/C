#include <iostream>
#include <iomanip>

double power(double x, int n);

int main()
{
    double y,x;
    int n;

    std::cin>>x>>n;

    y = power(x,n);

    std::cout<<std::setprecision(14)<<y;

    return 0;
}

double power(double x, int n)
{
	if (n==1)
	{
		return x;
	}
	double m = power(x,n/2);
	if (n%2 == 0)
	{
		return m*m;
	}
	return m*m*x;
}