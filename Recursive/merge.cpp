#include <iostream>

void MergeSort(int * p, int n);

void Mergre(int * p, int n);

int main()
{
	int n;
	std::cin>>n;
	int * a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		std::cin>>a[i];
	}
	MergeSort(a,n);
	for (int i = 0; i < n; ++i)
	{
		std::cout<<a[i]<<' ';
	}
	std::cout<<std::endl;
	return 0;
}

void MergeSort(int * p, int n)
{
	if (n==1)
	{
		return;
	}
	MergeSort(p, n/2);/*left side*/
	MergeSort(&p[n/2], (n/2)+(n%2));/*right side*/
	Mergre(p, n);
}

void Mergre( int * p, int n)
{
	int * r = new int[n];
	for (int i = 0; i < n; ++i)//before merge
	{
		r[i]= p[i];
		//std::cout<<r[i]<<std::endl;
	}

	int* q = &r[n/2];
	int* e = &r[n];
	int* f = q;

	for (int i = 0; i < n; ++i)
	{
		if (r != f)
		{
			if (q !=e)
			{
				if (*r <= *q)
				{
					p[i] = *r;
					r = r+1;
				}
				else
				{
					p[i] = *q;
					q = q+1;
				}
			}
			else
			{
				p[i] = *r;
				r = r+1;
			}
		}
		else
		{
			if (q !=e)
			{
				p[i] = *q;
				q = q+1;
			}
		}
	}
	//std::cout<<"->"<<std::endl;
	/*for (int i = 0; i < n; ++i)//after merge
	{
		std::cout<<p[i]<<std::endl;
	}*/
	//std::cout<<'*'<<std::endl;
}