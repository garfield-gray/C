
#include <iostream>

/*
nothing spatial:) 
*/

void modify(int * p,int *q,int *r)
{
	if ((p == q) || (p ==r)  )
		return;
	std::cout<<*p<<' ';
	p = p-1;
	std::cout<<*p<<' ';
	p = p+3;
	modify(p,q,r);
}


int main()
{
	int a[12];
	for (int i = 0; i < 10; ++i)
	{
		std::cin>>a[i];
	}
	modify(&a[1],&a[10],&a[11]);
	return 0;
}
