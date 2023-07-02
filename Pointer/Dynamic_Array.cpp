/*
this code makes a matrix that all elements are in a row using pointers


*/
#include <iostream>
#include <string>

struct matrix
{
	double ** head;
	int row;
	int column;
};


void Build_up(matrix &b)
{
	int r = b.row;
	int c = b.column;
	int m = r*c;
	double* pseudo = new double [m];
	double** array = new double*[r];
	b.head = array;
	for (int i = 0; i < r; ++i)
	{
		array[i] = (double*)&pseudo[(c*i)];
	}
}

void Show_Adress_Of_Matrix(matrix &b)
{
	for (int i = 0; i < b.row; ++i)
	{
		for (int j = 0; j < b.column; ++j)
		{
			std::cout<<(unsigned long long int)&b.head[i][j]<<' ';
		}
		std::cout<<std::endl;
	}
}


void clean_up(matrix &b)
{
	for (int i = 0; i < (b.row); ++i)
	{
		delete[] b.head[i];
	}
}



int main()
{
    matrix a;
    int row;
    int column;
    std::cout<<"enter matrix's row"<<std::endl;
    std::cin>>row;
    a.row = row;
    std::cout<<"enter matrix's column"<<std::endl;
    std::cin>>column;
    a.column = column;
    Build_up(a);
    Show_Adress_Of_Matrix(a);
    clean_up(a);
    }
    
