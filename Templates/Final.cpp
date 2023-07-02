#include <iostream>


template <typename T, int R,int C>
class Matrix
{
public:
	T m[R][C];
	int rownum = R;
	int colnum = C;
	Matrix()
	{
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				if (i != j){
					m[i][j] = 0;
				}else{
					m[i][j] = 1;
				}}}
	}

	T& operator()(int row,int col)
	{
		return m[row][col];
	}
	
	T& operator()(int roworcol)
	{
		if (this->rownum == 1){
		return m[0][roworcol];}
		else{return m[roworcol][0];}
	}

	Matrix operator+(const Matrix operand)
	{
		if (R != operand.rownum|| C != operand.colnum){
			std::cout<<"imossible";
			return *this;}
		Matrix* Sum = new Matrix<T,R,C>;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				Sum->m[i][j] = this->m[i][j]+operand.m[i][j];
			}}
		return *Sum;
	}
	Matrix operator-(const Matrix operand)
	{
		if (R != operand.rownum|| C != operand.colnum){
			std::cout<<"imossible";
			return *this;}
		Matrix* result = new Matrix<T,R,C>;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				result->m[i][j] = this->m[i][j]-operand.m[i][j];
			}}
		return *result;
	}

	template <int Ro, int Co>
	Matrix<T, R, Co> operator*(const Matrix<T, Ro, Co> operand)
	{
		Matrix<T, R, Co>* Product = new Matrix<T, R, Co>;
		if (C != Ro){
			std::cout<<"imossible";
			return *Product;}
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0 ; j < Co ; ++j)
			{
				Product->m[i][j] = 0;
				for (int k = 0; k < C; ++k)
				{
					Product->m[i][j] += this->m[i][k]*operand.m[k][j];
				}}}
		return *Product;
	}

};


template<typename T,int N>
using colVec = Matrix<T, N, 1>;

template<typename T,int N>
using rowVec = Matrix<T, 1, N>;

template<typename T, int R, int C>
std::ostream& operator<<(std::ostream& stream, const Matrix<T, R, C> en)
{
	for (int i = 0; i < R ; ++i)
	{
		for (int j = 0; j < C ; ++j)
		{
			stream<<en.m[i][j]<<" ";
		}
		stream<<'\n';}
	stream<<'\n';
}

int main()
{
    Matrix<float,5,4> A;
    Matrix<float,4,6> G;
    rowVec<int,4> B;
    colVec<int,4> C;
    auto D = B*C;
    auto E = C*B;
    A(1,1)=3; //by this you can access the [2][2] number of matrix because is starts from 0
    auto H = A*G;
    B(2)=5;//by this you can access the third number of vector because is starts from 0
    C(3)=7;//like above
    std::cout<<H<<B<<C<<std::endl;
    return 0;
}