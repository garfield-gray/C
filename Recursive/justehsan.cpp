#include<iostream>

int function(int n, int r);

int help(int n, int r);

int main()
{
	int n , r;
	std::cin>>n>>r;
	while (r > 10 || n < 1)
	{
		std::cin>>n>>r;
	}
	std::cout<<function(n,r)<<std::endl;
	return 0;
}

int function(int n, int r)
{
	if (n == 1)
		return 1;
	
	return help(n-1,r);
}

int help(int n, int r)
{
	if (r == 1)
		return n + 1;
	
	return function(n, r) + help(n, r-1); 
}